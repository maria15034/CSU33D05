#ifndef T1_H_
#define T1_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


//void DFS1(struct Graph* graph, int node);
//void dfs(struct Graph* graph, int node);
struct Graph {
  int nodes;
  struct node** adjLists; //array of linked lists; each element is a separate linked list
  int* visited;
};

struct node {
  int node;
  struct node* next;
};

struct Graph* create_graph(int nodes);
struct node* create_node(int);
void add_edge(struct Graph* graph, int from, int to);


void bfs(struct Graph* graph, int initpoint);
void dfs(struct Graph* graph, int node);
//void delete_graph(struct Graph* g);


struct queue {
    int items[50];
    int infront; //head
    int behind; //tail
  };


void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int empty(struct queue* q);
void print_queue(struct queue* q);


struct queue* create_queue();


#endif
