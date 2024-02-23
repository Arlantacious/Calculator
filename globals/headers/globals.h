#ifndef GLOBALS_H
#define GLOBALS_H

#define INPUT_BUFFER_SIZE 99
#define NUM_OPERATIONS

typedef struct {
        unsigned int code;
        char* litrl;
} ERROR;

extern ERROR SUCCESS;
extern ERROR ERROR_ILLEGAL_INPUT;
extern ERROR ERROR_ILLEGAL_INPUT_EXCEEDS_BUFFER_LIMIT;
extern ERROR ERROR_STACK_OVERFLOW;
extern ERROR ERROR_STACK_UNDERFLOW;
extern ERROR ERROR_CANNOT_DIVIDE_BY_ZERO;

#endif
