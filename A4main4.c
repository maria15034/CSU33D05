// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
#include "t1.h"

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
    //initialise all nodes 'visited' status as 0
    int a =0;
    for(a;a<graph->numVertices;a++){
        graph->visited[a] = 0;
    }
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
      
    //printf("%d\n", currentVertex);
      printf("%c ", (char)(currentVertex+65));
      
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
    for(b;b<graph->numVertices;b++){
        graph->visited[b] = 0;
    }
}


//DFS1 algorithm - nested inside function dfs that lets it be initialised
void DFS1(struct Graph* graph, int vertex) {
    
    //dfs(graph,vertex);
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  //printf("%d \n", vertex);
    //char x = (char)(vertex+65);
    printf("%c ", (char)(vertex+65));

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS1(graph, connectedVertex); //recursion
    }
    temp = temp->next;
  }
}

/*void dfs(struct Graph* graph, int vertex){
    //initialise all nodes 'visited' status as 0
    int a =0;
    for(a;a<graph->numVertices;a++){
        graph->visited[a] = 0;
    }
    
    //DFS1(graph, vertex);

}*/



// Creating a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    //printf("\nQueue is Full!!");
      return;
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    //printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      //printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    //printf("Queue is empty");
  } else {
    //printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      //printf("%d ", q->items[i]);
    }
  }
}
/*
int main() {
  struct Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

    DFS1(graph, 0);
    printf("\n");
  bfs(graph, 0);
    printf("\n");
   

  return 0;
}*/

// converts an upper case character (A-Z) to a numerical value (between 0 and 25)
static int char2val ( char c ) {
    if ( c < 'A' || c > 'Z' ) {
        return -1;
    }

    return c-'A';
}

int main(){
    int num_nodes = 6;
    //Graph *graph = create_graph(num_nodes);
    struct Graph *graph = createGraph(num_nodes);
   
    /*
    add_edge(graph, char2val('A'), char2val('E'));
    add_edge(graph, char2val('B'), char2val('D'));
    add_edge(graph, char2val('A'), char2val('D'));
    add_edge(graph, char2val('A'), char2val('B'));
    add_edge(graph, char2val('B'), char2val('C'));
    add_edge(graph, char2val('C'), char2val('B'));
    add_edge(graph, char2val('E'), char2val('D'));
    add_edge(graph, char2val('D'), char2val('F'));
    add_edge(graph, char2val('F'), char2val('C'));
    add_edge(graph, char2val('C'), char2val('D'));
    */
    
    addEdge(graph, char2val('A'), char2val('E'));
    addEdge(graph, char2val('B'), char2val('D'));
    addEdge(graph, char2val('A'), char2val('D'));
    addEdge(graph, char2val('A'), char2val('B'));
    addEdge(graph, char2val('B'), char2val('C'));
    addEdge(graph, char2val('C'), char2val('B'));
    addEdge(graph, char2val('E'), char2val('D'));
    addEdge(graph, char2val('D'), char2val('F'));
    addEdge(graph, char2val('F'), char2val('C'));
    addEdge(graph, char2val('C'), char2val('D'));
    
    
    /*addEdge(graph, 0,1);
    addEdge(graph, 0,3);
    addEdge(graph, 1,2);*/
    
    //printGraph(graph);
    
    //A goes to E , D, B
    //i believe the seocnd half

    DFS1(graph, 0);
    printf("\n");
    bfs(graph, 0);

    //delete_graph(graph);
    return 0;
}
