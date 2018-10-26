class Graph(object):
    def __init__(self,graph={}):
        self.graph=graph

    def vertices(self):
        return list(self.graph.keys())

    def isVertex(self,vertex):
        vert=self.vertices()
        if vertex in vert:
            return True
        else:
            return False
        

    def edges(self):
        return self.generateEdges()

    def isEdge(self,vertexFrom,vertexTo):
        edgesOfGraph=self.edges()
        if (vertexFrom,vertexTo) in edgesOfGraph:
            return True
        else:
            return False

    def addVertex(self,vertex):
        if vertex not in self.graph:
            self.graph[vertex]=[]

    def addEdge(self,edge):
        edge=set(edge)
        (vertex1,vertex2)=tuple(edge)
        if vertex1  in self.graph:
            self.graph[vertex1].append(vertex2)
        else:
            self.graph[vertex1]=[vertex2]

    def generateEdges(self):
        edges=[]
        for vertex in self.graph:
            for neighbour in self.graph[vertex]:
                if (neighbour,vertex) not in edges:
                    edges.append((vertex,neighbour))
        return edges

    def printGraph(self):
        res="Vertices : "
        for k in self.graph:
            res+=str(k)+" "
        res+="\nedges :"
        for edge in self.generateEdges():
            res+=str(edge)+" "
        return res

    def findPath(self,startVertex,endVertex,path=[]):
        graph=self.graph
        path=path+[startVertex]
        if startVertex==endVertex:
            return path
        if startVertex not in graph:
            return None
        for vertex in graph[startVertex]:
            if vertex not in path:
                extendedPath=self.findPath(vertex,endVertex,path)
            
                if extendedPath:
                    return extendedPath
        return None

    def find_all_paths(self, startVertex, endVertex, path=[]):
        
        graph = self.graph
        path = path + [startVertex]
        if startVertex == endVertex:
            return [path]
        if startVertex not in graph:
            return []
        paths = []
        for vertex in graph[startVertex]:
            if vertex not in path:
                extendedPaths = self.find_all_paths(vertex, 
                                                     endVertex, 
                                                     path)
                for p in extendedPaths: 
                    paths.append(p)
        return paths

    def findOutDegree(self,vertex):
        vert=self.vertices()
        if vertex not in vert:
            return None
        else:
            count=0
            for vrtx in self.graph:
                if vrtx==vertex:
                    for neighbour in self.graph[vertex]:
                        count+=1
            return count

    def findInDegree(self,vertex):
        vert=self.vertices()
        if vertex not in vert:
            return None
        else:
            count=0
            for vrtx in self.graph:
                for neighbour in self.graph[vrtx]:
                    if neighbour==vertex:
                        count+=1
        return count



g = { "a" : ["c"],
       "b" : ["e"],
       "c" : ["b", "d", "e","f"],
       "d" : [],
       "e" : ["f","c"],
       "f" : ["b"]
    }
gW = { "a":[1],
       "b":[2],
       "c":[]
    }

graph = Graph(g)
'''
graph.vertices()
['a', 'c', 'b', 'e', 'd', 'f']

graph.isEdge('b','c')
False

graph.isEdge('c','b')
True

graph.findPath('a','c')
['a', 'c']

graph.findPath('a','f')
['a', 'c', 'b', 'e', 'f']

graph.find_all_paths('a','f')
[['a', 'c', 'b', 'e', 'f'], ['a', 'c', 'e', 'f'], ['a', 'c', 'f']]

graph.findInDegree('c')
2

graph.findOutDegree('c')
4

graph.findInDegree('f')
2

graph.findOutDegree('f')
1
 '''   
