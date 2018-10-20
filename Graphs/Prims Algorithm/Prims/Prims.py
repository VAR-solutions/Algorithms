import random
import math
import numpy as np

# Prim's Minimum Spanning Tree Algorithm
def primsAlgo(e,c,n):
	sel_edge = ()
	mincost = 0
	near = [0 for x in range(n)]
	t = [[0 for x in range(2)] for y in range(n-1)] 
	print('Initially Minimum Spanning Tree: \n' ,np.matrix(t))
	values = np.array(c)
	index = np.argmin(values)
	minedge = [index//n, index%n]

	sel_edge = minedge
	mincost += c[sel_edge[0]][sel_edge[1]]

    #Select neighboring edge with minimum cost
	t[0][0],t[0][1] = sel_edge[0],sel_edge[1]
	for l in range(0,n):
		if(c[l][sel_edge[0]] < c[l][sel_edge[1]]):
			near[l] = sel_edge[0]
		else:
			near[l] = sel_edge[1]
	near[sel_edge[0]],near[sel_edge[1]] = -1,-1
	minm = math.inf
	for i in range(1,n-1):
		for j in range(n):
			if(near[j] != -1):
				if(c[j][near[j]] < minm):
					minm = c[j][near[j]]
					sel_edge[0] = j
					sel_edge[1] = near[j]
		minm = math.inf
		t[i][0],t[i][1] = sel_edge[0],sel_edge[1]
		mincost += c[sel_edge[0]][sel_edge[1]]
		near[sel_edge[0]] = -1
		for k in range(n):
			if(near[k] != -1 and (c[k][near[k]] > c[k][sel_edge[0]])):
				near[k] = sel_edge[0]
	print('Resultant MST: \n', np.matrix(t))
	return mincost

n = random.randint(5,7)
print('Number of vertices:', n)
max_int = math.inf
e = [[0 for x in range(n)] for y in range(n)] 
c = [[max_int for x in range(n)] for y in range(n)] 
for i in range(n):
	for j in range(n):
		if(i < j):
			e[i][j]=1
			c[i][j]=float(random.randint(10,50))
		else:
			e[i][j]=e[j][i]
			c[i][j]=c[j][i]
print('Edge Adjacency Matrix: \n', np.matrix(e))
print('Cost Adjacency Matrix: \n',np.matrix(c))
print ('Cost of MST: ', primsAlgo(e,c,n))
