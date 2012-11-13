#include <stdlib.h> // NULL, malloc, free
#include "stack.h" // s_create, s_length, s_push, s_pop, s_peek, s_destroy

typedef struct S_Node
{
  S_Node *prevNode;
  void *data;  
} S_Node;

Stack *s_create()
{
  Stack *s = malloc(sizeof(Stack));

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

int s_push(Stack *s, void *a) {
  // pushes a new value on the stack; returns length of stack

  // Initialize the node
  S_Node *n = malloc(sizeof(S_Node));
  if (n == NULL) {
    return -1;
  }

  n->prevNode = s->head;
  n->data = a;

  // Push it onto the stack
  s->head = n;
  s->length++;

  return s->length;
}

void* s_pop(Stack *s) {
  // pops value from stack and returns it.

  // Test for empty stack.
  if (s->head == NULL) {
    return NULL;
  }

  // Get the data and the prev node...
  void *data = s->head->data;
  S_Node *prev = s->head->prevNode;

  // free the old node information
  free(s->head);
  s->head = prev;
  s->length--;

  return data;
}

void* s_peek(Stack *s) {
  // returns the data of the current head of the stack, without
  // altering the stack itself!

  if ((s == NULL) || (s->head == NULL)) {
    return NULL;
  } else {
    return s->head->data;
  }
}

void s_destroy(Stack *s) {
  // destroys the stack altogether, a node at a time.

  // pop everything off the stack
  S_Node *head;
  for (head = s_pop(s); head != NULL; head = s_pop(s)) {
    ;
  }

  // destroy the stack itself
  free(s);
}
