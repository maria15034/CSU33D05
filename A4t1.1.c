//
//  t1.c
//  assignment4.1
//
//  Created by Maria Isabella on 29/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "t1.h"



Graph* create_graph(int num_nodes){
     Graph* graph = (Graph*)malloc(sizeof(struct Graph));
        graph->num_nodes = num_nodes;
     
        // Create an array of adjacency lists.  Size of
        // array will be num_nodes
        graph->array = (struct AdjList*)malloc(num_nodes * sizeof(struct AdjList));
     
        // Initialize each adjacency list as empty by
        // making head as NULL
        int i;
        for (i = 0; i < num_nodes; ++i)
            graph->array[i].head = NULL;
     
    return graph;
    
}; // creates a graph with num_nodes nodes, assuming nodes are stored in alphabetical order (A, B, C..)

struct AdjListNode* newAdjListNode(int to) //new node function
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)); //in this line?
    newNode->to = to;
    newNode->next = NULL;
    return newNode;
}



void add_edge(Graph *g, int from, int to){
    
    // Add an edge from 'from' to 'to'.  A new node is
        // added to the adjacency list of from.  The node
        // is added at the beginning...
        struct AdjListNode* check = NULL;
        struct AdjListNode* newNode = newAdjListNode(to); ////? could be newNode = newAdjListNode(to);
     
        if (g->array[from].head == NULL) {
            newNode->next = g->array[from].head;
            g->array[from].head = newNode;
        }
        else {
     
            check = g->array[from].head;
            while (check->next != NULL) {
                check = check->next;
            }
            // graph->array[src].head = newNode;
            check->next = newNode;
        }
     
        // Since graph is undirected, add an edge from
        // dest to src also
        newNode = newAdjListNode(from);
        if (g->array[to].head == NULL) {
            newNode->next = g->array[to].head;
            g->array[to].head = newNode;
        }
        else {
            check = g->array[to].head;
            while (check->next != NULL) {
                check = check->next;
            }
            check->next = newNode;
        }
     //??
        // newNode = newAdjListNode(from);
        // newNode->next = graph->array[to].head;
        // graph->array[dest].head = newNode;
    
}; // adds a directed edge

void printGraph(struct Graph* graph)
{
    int v;
        for (v = 0; v < graph->num_nodes; ++v) {
            struct AdjListNode* pCrawl = graph->array[v].head;
            //printf("\n Adjacency list of vertex %d\n head ", v);
            
            
            //char x = (char)(65+(pCrawl->to));
            char x = (char)(65);
            printf("\n Adjacency list of vertex %c\n head ", x+v);
            
            
            while (pCrawl) {
                //pCrawl->to is our number; 0 = A, 1= B...
                printf("-> %c", (char)(65 + (pCrawl->to)));
                pCrawl = pCrawl->next;
            }
            printf("\n");
        }
}



void bfs(Graph* g, int origin){}; //implements breath first search and prints the results
void dfs(Graph* g, int origin){};

/*void delete_graph(???){
 
    }*/
