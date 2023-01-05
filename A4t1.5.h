#ifndef T1_H_
#define T1_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//void DFS1(struct Graph* graph, int vertex);
//void dfs(struct Graph* graph, int vertex);
struct Graph {
  int nodes;
  struct node** adjLists; //array of linked lists; each element is a separate linked list
  int* visited;
};

struct node {
  int vertex;
  struct node* next;
};
struct Graph* create_graph(int nodes);
struct node* create_node(int);
void add_edge(struct Graph* graph, int src, int dest);

void bfs(struct Graph* graph, int initpoint);
void dfs(struct Graph* graph, int vertex);
void delete_graph(struct Graph* g);

void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int empty(struct queue* q);
void print_queue(struct queue* q);

struct queue* create_queue();
struct queue {
    int items[50];
    int infront;
    int behind;
  };

#endif
