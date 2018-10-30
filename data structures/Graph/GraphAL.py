class Node:
    def __init__(self,vertex):
        self.vertex = vertex
        self.next = None
    def getEndNode(self):
        nextNode = self
        returnNode = self
        while(nextNode!=None):
            returnNode = nextNode
            nextNode = nextNode.next
        return returnNode
class Graph:
    def __init__(self):
        self.graphItems = [] #graph vertexes
        self.graph = [] #graph with nodes
        self.edges = []
    def addVertex(self,data):
        self.graphItems.append(data)
        self.graph.append(None)
    def getVertexNumber(self,value):
        return self.graphItems.index(value)+1
    def addEdge(self,vertexFrom,vertexTo):
        vertexFrom = self.getVertexNumber(vertexFrom)
        vertexTo = self.getVertexNumber(vertexTo)
        fromNode = self.graph[vertexFrom-1]
        node = Node(vertexTo)
        if(fromNode!=None): #check whether there is a path added to the fromeNode position if not, node will be the first path
            endNode = fromNode.getEndNode()
            endNode.next = node
        else:
            self.graph[vertexFrom-1] = node
    def isEdge(self,vertexFrom,vertexTo):
        vertexFrom = self.getVertexNumber(vertexFrom)
        vertexTo = self.getVertexNumber(vertexTo)
        currentPos = self.graph[vertexFrom-1]
        while(currentPos!=None):
            if(currentPos.vertex==vertexTo):
                return True
            currentPos = currentPos.next
        return False
    def isPath(self,vertexFrom,vertexTo):
        vertexFrom = self.getVertexNumber(vertexFrom)
        vertexTo = self.getVertexNumber(vertexTo)
        visited = []
        queue = []
        queue.append(vertexFrom)
        while(len(queue)>0):
            vertex = queue.pop(0)
            if(vertex not in visited):
                visited.append(vertex)
                currentNode = self.graph[vertex-1]
                while(currentNode!=None):
                    if(currentNode.vertex==vertexTo):
                        return True
                    queue.append(currentNode.vertex)
                    currentNode = currentNode.next
        return False
    def isVertex(self,vertex):
        return vertex in self.graphItems
    def __str__(self):
        return self.printGraph("key")
    def printGraph(self,gtype=None):
        out = ""
        for i in range(len(self.graph)):
            paths = ""
            node = self.graph[i]
            while(node!=None):
                if(gtype=="key"):
                    paths += "-->"+str(node.vertex)
                else:
                    paths += "-->"+str(self.graphItems[node.vertex-1])
                node = node.next
            if(gtype=="key"):
                out += "V"+str(i+1)+" :"+paths+"\n"
            else:
                out += str(self.graphItems[i])+" :"+paths+"\n"
        return out
