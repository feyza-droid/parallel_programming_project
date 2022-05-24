# Prim's Algorithm in Python

class PRIM:
    def __init__(self, graph):
        self.graph = graph
        # Matrix of the resulting MST
        self.mst = [[0 for c in range(self.graph.V)] for r in range(self.graph.V)]

    def find_mst(self):
        inf = float('inf')

        # This is a list showing which nodes are already selected 
        # so we don't pick the same node twice and we can actually know when stop looking
        selected_nodes = [False for node in range(self.graph.V)]        
        
        indx = 0
        
        # While there are nodes that are not included in the MST, keep looking:
        while(False in selected_nodes):
            # We use the big number we created before as the possible minimum weight
            minimum = inf

            # The starting node
            start = 0 # we can also randomly start from available nodes

            # The ending node
            end = 0

            for i in range(self.graph.V):
                # If the node is part of the MST, look its relationships
                if selected_nodes[i]:
                    for j in range(self.graph.V):
                        # If the analyzed node have a path to the ending node AND its not included in the MST (to avoid cycles)
                        if (not selected_nodes[j] and self.graph.adj_matrix[i][j]>0):  
                            # If the weight path analized is less than the minimum of the MST
                            if self.graph.adj_matrix[i][j] < minimum:
                                # Defines the new minimum weight, the starting vertex and the ending vertex
                                minimum = self.graph.adj_matrix[i][j]
                                start, end = i, j
            
            # Since we added the ending vertex to the MST, it's already selected:
            selected_nodes[end] = True

            # Filling the MST Adjacency Matrix fields:
            self.mst[start][end] = minimum
            
            if minimum == inf:
                self.mst[start][end] = 0

            indx += 1
            
            self.mst[end][start] = self.mst[start][end]

    def print_mst(self):
        # Print the resulting MST
        # for node1, node2, weight in result:
        total = 0
        print("\n-------MST-------")
        for i in range(self.graph.V):
            for j in range(i, self.graph.V):
                if self.mst[i][j] != 0:
                    total += self.mst[i][j]
                    print("%d - %d: %d" % (i, j, self.mst[i][j]))

        print(f"Total weight of MST is {total}")