#include "t1.h"

// converts an upper case character (A-Z) to a numerical value (between 0 and 25)
static int char2val ( char c ) {
    if ( c < 'A' || c > 'Z' ) {
        return -1;
    }

    return c-'A';
}


//DFS1 into dfs

int main(){
    int num_nodes = 6;
    struct Graph *graph = create_graph(num_nodes);
   
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

    dfs(graph, char2val('A'));
    printf("\n");
    bfs(graph, char2val('A'));
    printf("\n");

    //delete_graph(graph);
    return 0;
}


