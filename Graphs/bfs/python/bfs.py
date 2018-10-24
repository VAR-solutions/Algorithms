class Graph:
	def __init__(self):
		self.nodes = {}

	def insertNode(self, u):
		if u not in self.nodes:
			self.nodes[u] = {}

	def V(self):
		return self.nodes.keys()

	def adj(self, u):
		if u in self.nodes:
			return self.nodes[u]

	def insertEdge(self, u, v, w=0):
		if u not in self.nodes:
			self.insertNode(u)
		if v not in self.nodes:
			self.insertNode(v)
		self.nodes[u][v] = w
		self.nodes[v][u] = w

	def bfs(self, start):
		S = [start]
		visited = {}
		for node in self.V():
			visited[node] = False
		visited[start] = True
		while len(S) > 0:
			u = S.pop(0)
			for v in self.adj(u):
				print "Start \t", u, " | Destination:\t", v
				if not visited[v]:
					visited[v] = True
					S.append(v)

	def __str__(self):
		string = ""
		for u in self.V():
			string += (str(u) + "->" + str(self.adj(u)) + "\n")
		return string


class OrientedGraph:
	def __init__(self):
		self.nodes = {}

	def insertNode(self, u):
		if u not in self.nodes:
			self.nodes[u] = {}

	def V(self):
		return self.nodes.keys()

	def adj(self, u):
		if u in self.nodes:
			return self.nodes[u]

	def insertEdge(self, u, v, w=0):
		if u not in self.nodes:
			self.insertNode(u)
		if v not in self.nodes:
			self.insertNode(v)
		self.nodes[u][v] = w

	def bfs(self, start):
		S = [start]
		visited = {}
		for node in self.V():
			visited[node] = False
		visited[start] = True
		while len(S) > 0:
			u = S.pop(0)
			for v in self.adj(u):
				print "Start \t", u, " | Destination:\t", v, " | Cost:\t", self.nodes[u][v]
				if not visited[v]:
					visited[v] = True
					S.append(v)

	def __str__(self):
		string = ""
		for u in self.V():
			string += (str(u) + "->" + str(self.adj(u)) + "\n")
		return string


def init():
	print "Test for non-oriented graph"
	graph = Graph()
	for u in ['a', 'b', 'c', 'd', 'e', 'f']:
		graph.insertNode(u)
	for u, v in [('a', 'b'), ('a', 'd'), ('b', 'c'), ('d', 'a'), ('d', 'c'), ('d', 'e'), ('e', 'c'), ('e', 'f')]:
		graph.insertEdge(u, v)
	print str(graph)
	#  Test bfs starting from a
	graph.bfs('a')
	print "---------------------------------------------"
	print "\nTest for Oriented Graph"
	graph = Graph()
	for u in ['a', 'b', 'c', 'd', 'e', 'f']:
		graph.insertNode(u)
	for u, v, w in [('a', 'b', 3), ('a', 'd', 2), ('b', 'c', 0), ('d', 'a', 1), ('d', 'c', 6), ('d', 'e', 10), ('e', 'c', 1), ('e', 'f', 0)]:
		graph.insertEdge(u, v, w)
	print str(graph)
	#  Test bellman starting from a
	graph.bfs('a')
	return


if __name__ == '__main__':
	init()
