#include "stack.h" // s_create, s_length, s_push, s_pop, s_peek, s_destroy

struct S_Node
{
  void *prevNode;
  void *data;  
};

struct Stack
{
  void *baseNode;
  void *head;
  int length;
};

int s_create()
{
  Stack *s = malloc(sizeof(Stack));

  s->baseNode = NULL;
  s->head = NULL;
  s->length = 0;

  return s; 
}

int s_length(Stack *s) {
  if (s == NULL) {
    // ERROR:  Stack is uninitialized!
    return -1;
  } else {
    return s->length;
  }
}

int s_push(Stack *s, void *a);  // returns length of stack
void* s_pop(Stack *s);
void* s_peek(Stack *s);
int s_destroy(Stack *s);