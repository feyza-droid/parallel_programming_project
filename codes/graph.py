class Graph:
    def __init__(self, V):
        self.V = V # number of nodes/vertices
        self.adj_matrix = [[0 for c in range(V)] for r in range(V)] # Initialize the adjacency matrix with zeros

    def add_edge(self, n1, n2, w):
        self.adj_matrix[n1][n2] = w # edge-weighted undirected graph
        self.adj_matrix[n2][n1] = w # edge-weighted undirected graph

    def print(self):
        print("-------GRAPH-------")
        for n1 in range(self.V):
            for n2 in range(self.V):
                print(f"{n1} - {n2}: {self.adj_matrix[n1][n2]}")