class Graph(object):
  def __init__(self, vertices):
    self.vertices = vertices
    self.adjacency = [[] for _ in range(vertices)]

  def addEdge(self, i, vertex):
    self.adjacency[i].append(vertex)

  def dfs(self, vertex):
    visited = [False for _ in range(self.vertices)]
    self._dfs(vertex, visited)
   
  def _dfs(self, vertex, visited):
    print(vertex)
    visited[vertex] = True
    for i in self.adjacency[vertex]:
      if not visited[i]:
        self._dfs(i, visited)

# Testing the code, values taken from https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
g = Graph(4)
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
print('Following is Depth First Traversal (starting from vertex 2)')
g.dfs(2)   