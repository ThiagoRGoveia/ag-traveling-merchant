import networkx as nx
import random
import time
import pandas as pd

start_time = time.time()

graphSize = 1000
G = nx.binomial_graph(graphSize, 1)
for (u, v, w) in G.edges(data=True):
    w['weight'] = random.randint(1, 100)
df = nx.to_pandas_adjacency(G, dtype=int)
# print(nx.is_connected(G))
A = nx.adjacency_matrix(G).toarray()
# print(A)
f = open("./graph.c", "w")
f.write('#include "Includes.h"\n')
f.write("int completeGraph[%d][%d] = {" % (graphSize, graphSize))
for  i in range(graphSize):
    f.write("{")
    for j in range(graphSize):
        if A[i][j] == 0:
            element =  50000
        else:
            element = str(A[i][j])
        if (j == graphSize - 1):
            f.write("%s" % element)
        else:
            f.write("%s, " % element)
    if (i == graphSize - 1):
        f.write("}\n")
    else:
        f.write("},\n")
f.write("};\n")
f.close()
print(df.to_csv(path_or_buf='./graphGenerator/graphs/graph_1000_100.csv',
                index=False, header=False))


# print("--- %s seconds ---" % (time.time() - start_time))


