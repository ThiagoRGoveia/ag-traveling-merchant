import networkx as nx

G = nx.path_graph(9)
A = nx.adjacency_matrix(G)
print(A.todense())
