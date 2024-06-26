#include "utils.h"

static Exit_Code resolve_val(Stack* src, Stack* out)
{
        if (token_eval_id(src->top->data.id))
        {
                stack_push(out, stack_pop(src));
                assert(!stack_is_empty(out));

                return SUCCESS;
        }
        
        return SAFE_FAIL;
}

static Exit_Code resolve_op(Stack* src, Stack* out)
{ 
        assert(token_eval_id(!src->top->data.id));
        assert(!stack_is_empty(src));
        assert(!stack_is_empty(out));

        Token op = stack_pop(src);

        Token rval = stack_pop(out);

        Token lval = stack_pop(out);
       
        float final = 0.0;

        switch (op.id)
        {
                case ADD:
                        final = lval.val + rval.val;
                        break;
                case SUB:
                        final = lval.val - rval.val;
                        break;
                case MUL:
                        final = lval.val * rval.val;
                        break;
                case DIV:
                        final = lval.val / rval.val;
                        break;
                case MOD:
                        final = fmod(lval.val, rval.val);
                        break;
                case EXP:
                        final = powf(lval.val, rval.val);
                        break;
                case VAL:
                case END:
                default:
                        break;
        }

        Token data = {final, VAL, 0};
        
        stack_push(out, data);

        return SUCCESS;
}

Exit_Code process(Stack* src, float* answer) {
        Exit_Code err = SUCCESS;
        Stack out;
        stack_init(&out);

        while (!stack_is_empty(src))
        {
                err = resolve_val(src, &out);
               
                if (err < 0)
                {
                        return err;
                }

                if (err == SUCCESS)
                {
                        continue;
                }

                err = resolve_op(src, &out);

                if (err < 0)
                {
                        return err;
                }
        }
        
        *answer = out.top->data.val;
        
        return err;
}
