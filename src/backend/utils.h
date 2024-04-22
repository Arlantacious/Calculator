#ifndef UTILS_H
#define UTILS_H

typedef enum {
    SUCCESS = 0,
    ERROR_ILLEGAL_INPUT = 1
} Error;

typedef enum {
    VALUE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    END
} Token_ID;

typedef struct {
    float val;
    Token_ID id;
} Token;

struct Node {
    struct Node* next;
    struct Node* prev;
    Token data;
};

typedef struct {
    struct Node* top;
} Stack;

int isempty(Stack* stack);

void push(Stack* stack, Token data);

Token pop(Stack* stack);

void init_stack(Stack* stack);

void free_stack(Stack* stack);

#endif