#include "t1.h"

// converts an upper case character (A-Z) to a numerical value (between 0 and 25)
static int char2val ( char c ) {
    if ( c < 'A' || c > 'Z' ) {
        return -1;
    }

    return c-'A';
}
/*
int main(){
    int num_nodes = 6;
    Graph *graph = create_graph(num_nodes);
   
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
    
    printGraph(graph);
    
    //A goes to E , D, B
    //i believe the seocnd half

    //dfs(graph, char2val('A'));
    //bfs(graph, char2val('A'));

    //delete_graph(graph);

}
*/
/*
int main()
{
    // create the graph given in above figure
    int graph_nodes = 5;
    struct Graph* graph = create_graph(graph_nodes);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
 
    // print the adjacency list representation of the above
    // graph
    printGraph(graph);
 
    return 0;
}

*/


int main() {
  struct Graph* graph = create_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

  bfs(graph, 0);

  return 0;
}
