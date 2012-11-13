// #include "stack.h" // s_create, s_length, s_push, s_pop, s_peek, s_destroy

// Declared here, because it's a public structure
struct Stack
{
  void *baseNode;
  void *head;
  int length;
};



int s_create();
int s_length(Stack *s);
int s_push(Stack *s, void *a);  // returns length of stack
void* s_pop(Stack *s);
void* s_peek(Stack *s);
int s_destroy(Stack *s);
