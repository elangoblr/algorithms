#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}NODE;

typedef struct list{
  NODE *head;
}LIST;

LIST *newList(){
  LIST *newList = (LIST *)malloc(sizeof(LIST));
  newList->head = NULL;
  return newList;
}

void printList(LIST *l){
  NODE *tmp = l->head;
  while(tmp != NULL){
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

void add(LIST *l, int data){
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;
  newNode->next = NULL;
  // traverse to last
  if (l->head == NULL){
    l->head = newNode;
  }else{
    NODE *tmp = l->head;
    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = newNode;
  }
  return;
}

NODE *revListIterative(NODE *head){
  if (head == NULL)
    return NULL;
  NODE *prev = NULL;
  NODE *curr = head;
  NODE *next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

NODE *revListRecursive(NODE *head){
  if (head == NULL || head->next == NULL){
    return head;
  }
  NODE *rest = revListRecursive(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

void reverseI(LIST *l){
  if (l->head == NULL)
    return;
  l->head = revListIterative(l->head);
}

void reverseR(LIST *l){
  if (l->head == NULL)
    return;
  l->head = revListRecursive(l->head);
}

int main(){
  LIST *l = newList();
  add(l, 10);
  add(l, 20);
  add(l, 30);
  add(l, 40);
  printList(l);
  reverseI(l);
  printList(l);
  reverseI(l);
  printList(l);
  printf("Recursive\n");
  reverseR(l);
  printList(l);
}
