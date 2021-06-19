#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
  int number;
  struct _Node *next;
} Node;

Node *createList(int n) {
  Node *now = NULL;
  for(int i = 0; i < n; i++){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = i;
    newNode->next = NULL;
    if(now != NULL){
      newNode->next = now->next;
      now->next = newNode;
    }
    now = newNode;
  }
}

int solveJosephus(Node **head, int step) {

}