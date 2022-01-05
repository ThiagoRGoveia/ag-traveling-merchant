import networkx as nx
import random
import time
import pandas as pd

start_time = time.time()

G = nx.binomial_graph(10, 0.5)
for (u, v, w) in G.edges(data=True):
    w['weight'] = random.randint(0, 10)
# A = nx.adjacency_matrix(G)
df = nx.to_pandas_adjacency(G, dtype=int)
print(nx.is_connected(G))
print(df.to_csv(path_or_buf='./pgraph', index=False, header=False))
print("--- %s seconds ---" % (time.time() - start_time))
