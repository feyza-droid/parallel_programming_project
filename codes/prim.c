// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mpi.h>

#define INF 9999999


int main(int argc, char* argv[]) {
    // open the file and read the graph
	FILE* inputFile;
	const char* inputMode = "r";
	inputFile = fopen(argv[1], inputMode);
	if (inputFile == NULL) {
		fprintf(stderr, "Couldn't open input file, exiting!\n");
		exit(EXIT_FAILURE);
	}

	int fscanfResult;

	// first line contains number of vertices and edges
	int V = 0;
	int n_edges = 0;
	fscanfResult = fscanf(inputFile, "%d %d", &V, &n_edges);
    // create a 2d array of size VxV
    //for adjacency matrix to represent graph
    int i=0,j=0;  
    int G[V][V];
    for(i=0;i<V;i++){    
        for(j=0;j<V;j++){
            G[i][j] = 0; 
        }//end of j    
    }//end of i   

	int from;
	int to;
	int weight;
	for (int i = 0; i < n_edges; i++) {
		fscanfResult = fscanf(inputFile, "%d %d %d", &from, &to, &weight);

        G[from][to] = weight;
        G[to][from] = weight;

		if (fscanfResult == EOF) {
			fprintf(stderr,"Something went wrong during reading of graph file, exiting!\n");
			fclose(inputFile);
			exit(EXIT_FAILURE);
		}
	}

	fclose(inputFile);

    // to store the execution time of code
    double time_spent = 0.0;
    clock_t begin = clock();

    int no_edge;  // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false

    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    //graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x;  //  row number
    int y;  //  col number

    // print for edge and weight
    printf("Minimum Spanning Tree\nEdge : Weight\n");

    while (no_edge < V - 1) {
        //For every vertex in the set S, find the all adjacent vertices
        // , calculate the distance from the vertex selected at step 1.
        // if the vertex is already in the set S, discard it otherwise
        //choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
                    if (min > G[i][j]) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f s\n", time_spent);

    return 0;
}