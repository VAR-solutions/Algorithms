class Graph():
	def __init__(self ,Vert):
		self.graph = []
		for i in range(Vert):
			self.graph.append([])


	def addEdge(self,u,v):
		self.graph[u].append(v)

	def DFSrecur(self,s,visited):
		visited[s] = True
		print(s , end=" ")
		for i in self.graph[s]:
			if visited[i] == False:
				self.DFSrecur(i,visited)	

	def DFS(self,s):
		visited = [False]*(len(self.graph))
		for i in range(len(self.graph)):
			if visited[i] == False:
				self.DFSrecur(s , visited)

		

g = Graph(4)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

g.DFS(2)