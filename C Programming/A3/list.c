#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assignment3.h"
// Reference to
// https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
// https://www.learn-c.org/en/Linked_lists
// https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/

static int cmpfunc(const void *a, const void *b) {
  const double *A = (double *)a, *B = (double *)b;
  // printf("%d  %d\n", *A,*B);
  return (*A - *B);
}

// adds node horizontally

static void add_node_h(struct HBnode *head, int val) {
  struct HBnode *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  /* now we can add a new variable, pointer at tail */
  current->next = malloc(sizeof(struct HBnode));
  current->next->key = val;
  current->next->next = NULL;
}

// adds node vertically
static void add_node_b(struct SLnode *head, int val) {
  struct SLnode *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  /* now we can add a new variable, pointer at tail of vertical list */
  current->next = malloc(sizeof(struct SLnode));
  current->next->key = val;
  current->next->next = NULL;
}
// adds node initially
static void add_node_b_ini(struct HBnode *head, int val) {
  struct HBnode *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  /* now we can add a new variable, pointer at tail of vertical list */
  current->bottom = malloc(sizeof(struct SLnode));
  struct SLnode *current_bot = NULL;
  current_bot = current->bottom;
  current_bot->key = val;
  current_bot->next = NULL;
}

typedef struct HBnode *HBnodePtr;

HBnodePtr createHBlist(int n, int m) {
  int i, j, k, rand_bottom, array_counter;
  int array_size = n * (m + 1);
  time_t t;
  srand(time(NULL));
  double A[array_size];

  if (n == 0 && m == 0) {
    return NULL;
  }

  if (n == 0 && m > 0) {
    return NULL;
  }

  for (i = 0; i < array_size; i++) {
    A[i] = rand() % 70;
    printf("A[%d] = %lf \n", i, A[i]);
  }
  qsort(A, (array_size), sizeof(double), cmpfunc);
  printf("\nAFTER SORT\n");
  for (i = 0; i < array_size; i++) {
    printf("A[%d] = %lf \n", i, A[i]);
  }

  // initialization
  struct HBnode *head = NULL;
  head = malloc(sizeof(struct HBnode));
  head->key = A[0];
  head->next = NULL;
  array_counter = 1;

  for (i = 0; i < n; i++) {
    struct HBnode *current = head;
    rand_bottom = rand() % (m + 1);
    if (rand_bottom != 0) {
      add_node_b_ini(current, A[array_counter]);
      array_counter++;
    }
    while (current->next != NULL) {
      current = current->next;
    }
    if (rand_bottom != 0) {
      struct SLnode *cur_bot = current->bottom;
      for (j = 0; j < (rand_bottom - 1); j++) {
        add_node_b(cur_bot, A[array_counter]);
        array_counter++;
        cur_bot = cur_bot->next;
      }
    }
    add_node_h(current, A[array_counter]);
    array_counter++;
  }
  return head;
};
SLnodePtr flattenList(const HBnodePtr L) {
  struct HBnode *current = L;
  struct SLnode *SLhead = NULL;
  SLhead = malloc(sizeof(struct SLnode));
  while (current->next != NULL) {
    add_node_b(SLhead, current->key);
    struct SLnode *cur_bot = current->bottom;
    while (cur_bot != NULL) {
      add_node_b(SLhead, cur_bot->key);
      cur_bot = cur_bot->next;
    }
    current = current->next;
  }
  struct SLnode *cur;
  cur = SLhead;
  SLhead = SLhead->next;
  free(cur);
  return SLhead;
}

static void free_recursively(HBnodePtr L) {
  if (!L)
    return;
  free_recursively(L->next);
  free(L);
}

void freeSLlist(SLnodePtr L) {
  if (!L)
    return;
  freeSLlist(L->next);
  free(L);
}
void freeHBlist(HBnodePtr L) {
  struct HBnode *current = L;
  while (current->next != NULL) {
    struct SLnode *cur_bot = current->bottom;
    struct SLnode *next_bot;
    while (cur_bot != NULL) {
      next_bot = cur_bot->next;
      free(cur_bot);
      cur_bot = next_bot;
    }
    current = current->next;
  }
  free_recursively(L);
}

void printHBlist(const HBnodePtr L) {
  struct HBnode *current = L;
  while (current->next != NULL) {
    printf("\n%d ->", current->key);
    struct SLnode *cur_bot = current->bottom;
    while (cur_bot != NULL) {
      printf(" %d ", cur_bot->key);
      cur_bot = cur_bot->next;
    }
    current = current->next;
  }
}
void printSLlist(const SLnodePtr L) {
  struct SLnode *current = L;
  while (current->next != NULL) {
    printf("%d -> ", current->key);
    current = current->next;
  }
  printf("%d", current->key);
}
