import networkx as nx

G = nx.complete_graph(9)
A = nx.adjacency_matrix(G)
print(A.todense())
[[1]]
A.setdiag(A.diagonal() * 2)
print(A.todense())
