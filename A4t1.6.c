
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
    
    //making queue;
  struct queue* q = create_queue();

  graph->visited[initpoint] = 1; //node visited so 1
  enqueue(q, initpoint); //put it at the back of the queue

  while (!empty(q)) {//while the queue is not empty, cuz if its empty cant do anything
    //print_queue(q); //print whats in the queue
    int current_node = dequeue(q); //dequeues current value and return
      
      //so it converts back to characters;
    printf("%c ", (char)(65+current_node));

    struct node* temp = graph->adjLists[current_node]; //set temp to the current node

    while (temp) { //if there's something in current node
      int adj_node = temp->node; //set the adj_node to the current node

      if (graph->visited[adj_node] == 0) { //if the node is unvisited, process it and print
        graph->visited[adj_node] = 1; //set status to 1
        enqueue(q, adj_node); //queue up the current node to be processed
      }
      temp = temp->next;//continue for other adjnodes
    }
  }
    //reset visited statuses for incase you wanna do bfs or dfs again
    int b =0;
    for(b;b<graph->nodes;b++){
        graph->visited[b] = 0;
    }
}


//DFS1 algorithm - nested inside function dfs that lets it be initialised
//nvm not doing that, initialisation of visited member is only needed at end of bfs
void dfs(struct Graph* graph, int node) { //works recusrively
    
    //dfs(graph,node);
  struct node* adjList = graph->adjLists[node]; //taking the adj list of node, ie 'A'
  struct node* temp = adjList; //temp storing adj list of that node

  graph->visited[node] = 1; //mark off that node as visited
    
    //so it converts back to characters;
  printf("%c ", (char)(65+node)); //print A

  while (temp != NULL) { //if the temp isnt empty
    int connected_node = temp->node; //the connected node is gonna be whatever node is connected to A
    if (graph->visited[connected_node] == 0) {//which we recurse on
      dfs(graph, connected_node);
    }
    temp = temp->next;
  }
    
}

/*
void dfs(struct Graph* graph, int node){
    //initialise all nodes 'visited' status as 0
    int a =0;
    for(a;a<graph->nodes;a++){
        graph->visited[a] = 0;
    }
    //DFS1(graph, node);
}*/

// Creating a node
struct node* create_node(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->node = v;
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
void add_edge(struct Graph* graph, int from, int to) {
  // adding a directed edge from 'from' to 'to'
  struct node* newNode = create_node(to); //creates a new node at the end point
  newNode->next = graph->adjLists[from];
  graph->adjLists[from] = newNode;
    
  // adding a directed edge from 'to' to 'from' ... unnecessary for this graph tho
  /*newNode = create_node(from);
  newNode->next = graph->adjLists[to];
  graph->adjLists[to] = newNode;*/
}

//void delete_graph(Graph *graph);
   /*
        for (int i = 0; i < g->nodes; i++)
          {
         //goes through each list
           Element* temp = g->AdjList[i];
         while(temp != NULL){
        //temparary pointer so that we dont delete our link between two nodes
           Element*  p = temp;
           temp = temp->next;
           free(p);
         }
         
      }
      free(g->AdjList);
      free(g->visited);
      free(g);
    */
    
    



// creating a queue
struct queue* create_queue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->infront = -1; //set to null
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
    q->behind++; //increment
    q->items[q->behind] = value; //setting what's at the back of the queue to node
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


