#ifndef T1_H_
#define T1_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Graph{ //graph is an array of adjacency lists
    //the size of the graph is graph_nodes, the number of vertices in the graph
    int num_nodes;
    struct AdjList* array;
    
} Graph;

struct AdjList {
    struct AdjListNode* head; //points to head of node in adjlist
};

struct AdjListNode {
    int to;
    struct AdjListNode* next;
};



Graph* create_graph(int num_nodes); // creates a graph with num_nodes nodes, assuming nodes are stored in alphabetical order (A, B, C..)
void add_edge(Graph *g, int from, int to); // adds a directed edge
void bfs(Graph* g, int origin); //implements breath first search and prints the results
void dfs(Graph* g, int origin); //implements depth first search and prints the results
void printGraph(struct Graph* graph);

#endif
