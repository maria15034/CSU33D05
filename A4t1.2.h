#ifndef T1_H_
#define T1_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 40

typedef struct Graph{ //graph is an array of adjacency lists
    //the size of the graph is graph_nodes, the number of vertices in the graph
    int num_nodes;
    struct AdjList* array;
    //int *visited; ///TRY PUTTING THIS WITHIN the AdjList structure ???????????????? OK??? or the other one ??????
    
} Graph;

struct AdjList {
    struct AdjListNode* head; //points to head of node in adjlist
};

struct AdjListNode {
    int to;
    struct AdjListNode* next;
    int *visited;
};

Graph* create_graph(int num_nodes); // creates a graph with num_nodes nodes, assuming nodes are stored in alphabetical order (A, B, C..)
void add_edge(Graph *g, int from, int to); // adds a directed edge
void bfs(Graph* g, int origin); //implements breath first search and prints the results
void dfs(Graph* g, int origin); //implements depth first search and prints the results
void printGraph(struct Graph* graph);

//FOR BFS

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


#endif



////// 'node' = Adj List Node
/*struct node {
  int vertex; //vertex = 'to'
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices; // num_nodes
  struct node** adjLists; //array
  
};
*/

//also , ‘’Puts all its adjacent vertices in the stack’ adjacent vertices = vertices it POINTS to.

