#ifndef ALPHY_STRUCT
#define ALPHY_STRUCT

// #include "stack.h" // s_create, s_length, s_push, s_pop, s_peek, s_destroy

typedef struct S_Node S_Node;

// Declared here, because it's a public structure
typedef struct Stack
{
  S_Node *head;
  int length;
} Stack;



Stack *s_create();
int s_length(Stack *s);
int s_push(Stack *s, void *a);  // returns length of stack
void* s_pop(Stack *s);
void* s_peek(Stack *s);
void s_destroy(Stack *s);
#endif
