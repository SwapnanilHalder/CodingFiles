#include <iostream>
#include <cstdlib>

typedef struct node_s {
  struct node_s *lft, *rgt;
  int data;
} NODE;

typedef struct heap_s {
  NODE *root;
  size_t size;
} HEAP;

// Add a new node at the last position of a complete binary tree.
void add(HEAP *heap, NODE *node) {
  size_t mask = 0;
  size_t size = ++heap->size;
  // Initialize the mask to the high-order 1 of the size.
  for (size_t x = size; x; x &= x - 1) mask = x;
  NODE **pp = &heap->root;
  // Advance pp right or left depending on size bits.
  while (mask >>= 1) pp = (size & mask) ? &(*pp)->rgt : &(*pp)->lft;
  *pp = node;
}   

void print(NODE *p, int indent) {
  if (!p) return;
  for (int i = 0; i < indent; i++) printf(" ");
  printf("%d\n", p->data);
  print(p->lft, indent + 1);
  print(p->rgt, indent + 1);
}   

int main(void) {
  HEAP h[1] = { NULL, 0 };
  for (int i = 0; i < 16; i++) {
    NODE *p = (NODE *)malloc(sizeof *p);
    p->lft = p->rgt = NULL;
    p->data = i;
    add(h, p);
  }   
  print(h->root, 0);
}   