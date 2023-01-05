
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
#include "t1.h"


void bfs(struct Graph* graph, int initpoint) {
    //initialising all nodes 'visited' status as 0
    int a = 0;
    for(a;a<graph->nodes;a++){
        graph->visited[a] = 0;
    }
    
  struct queue* q = create_queue();

  graph->visited[initpoint] = 1;
  enqueue(q, initpoint);

  while (!empty(q)) {
    print_queue(q);
    int currentVertex = dequeue(q);
      
      //so it converts back to characters;
    printf("%c ", (char)(65+currentVertex));

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
    
    int b =0;
    for(b;b<graph->nodes;b++){
        graph->visited[b] = 0;
    }
}


//DFS1 algorithm - nested inside function dfs that lets it be initialised
//nvm not doing that, initialisation of visited member is only needed at end of bfs
void dfs(struct Graph* graph, int vertex) {
    
    //dfs(graph,vertex);
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
    
    //so it converts back to characters;
  printf("%c ", (char)(65+vertex));

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      dfs(graph, connectedVertex); //recursion
    }
    temp = temp->next;
  }
}

/*
void dfs(struct Graph* graph, int vertex){
    //initialise all nodes 'visited' status as 0
    int a =0;
    for(a;a<graph->nodes;a++){
        graph->visited[a] = 0;
    }
    //DFS1(graph, vertex);
}*/

// Creating a node
struct node* create_node(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct Graph* create_graph(int nodes) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->nodes = nodes;

  graph->adjLists = malloc(nodes * sizeof(struct node*)); //allocating memory for each linked list
  graph->visited = malloc(nodes * sizeof(int)); //allocating memory for 'visited' member of each node

  int i;
  for (i = 0; i < nodes; i++) {
      // initialising
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void add_edge(struct Graph* graph, int src, int dest) {
  // adding a directed edge from 'from' to 'to'
  struct node* newNode = create_node(dest); //new node at destination
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // adding a directed edge from 'to' to 'from' ... unnecessary for this graph tho
  /*newNode = create_node(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;*/
}

void delete_graph(struct Graph* g){
    //USE FREE FUNCTION TO DELETE THE WHOLE THING
    
    if(g == NULL){
        return;
    }
    else {
        free(g);
    }
        
    //delete graph->visited
    //delete graph->adjLists
    //delete graph itself
    
    //delete newNode (from add_edge); (counter that counts every new edge created?)
    //delete queues
    
    }
    



// creating a queue
struct queue* create_queue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->infront = -1;
  q->behind = -1;
  return q;
}

// Check if the queue is empty
int empty(struct queue* q) {
  if (q->behind == -1)
    return 1;
  else
    return 0;
}

// adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->behind == SIZE - 1)
    //printf("\nQueue is Full!!");
      return;
  else {
    if (q->infront == -1)
      q->infront = 0;
    q->behind++;
    q->items[q->behind] = value;
  }
}

// deleting elements from queue
int dequeue(struct queue* q) {
  int item;
  if (empty(q)) {
    //printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->infront];
    q->infront++;
    if (q->infront > q->behind) {
      //printf("Resetting queue ");
      q->infront = q->behind = -1;
    }
  }
  return item;
}

// printing the queue
void print_queue(struct queue* q) {
  int i = q->infront;

  if (empty(q)) {
      return;
  } else {
      
    for (i = q->infront; i < q->behind + 1; i++) {
      //printf("%d ", q->items[i]);
    }
  }
}


