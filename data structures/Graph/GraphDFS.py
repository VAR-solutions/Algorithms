class Node:
   def __init__(self,vertex):
      self.vertex = vertex
      self.next = None
   def __repr__(self):
      out = ""
      tn = self
      while(tn!=None):
         out += str(tn.vertex)+"->"
         tn = tn.next
      return out[0:len(out)-2]
class Stack:
   def __init__(self):
      self.stack = []
   def push(self,data):
      self.stack.append(data)
   def pop(self):
      return self.stack.pop()
   def peek(self):
      return self.stack[len(self.stack)-1]
   def isEmpty(self):
      return len(self.stack)==0
 
#all the vertex UIs should go through this function   
def getVertex(vertexData):
   return int(vertexData)-1

userinput = str(input()).split()
N = int(userinput[0])
M = int(userinput[1])

graph = []
for i in range(N):
   graph.append(None)

for i in range(M):
   edges = str(input()).split()
   fromVertex = edges[0] #fromVertex is UI
   toVertex = edges[1] #toVertex is UI
   node = Node(getVertex(toVertex))
   if(graph[getVertex(fromVertex)]== None): 
      graph[getVertex(fromVertex)] = node
   else:
      node.next = graph[getVertex(fromVertex)]
      graph[getVertex(fromVertex)] = node
   #since undirected
   node = Node(getVertex(fromVertex))
   if(graph[getVertex(toVertex)]== None): 
      graph[getVertex(toVertex)] = node
   else:
      node.next = graph[getVertex(toVertex)]
      graph[getVertex(toVertex)] = node

def dfs(graph,start): #source is UI
   global vertexdata
   order = []
   time = 0 #time count
   dTime = [] #discover times
   fTime = [] #final times
   predecessor = []
   
   visited = Stack()
   
   colors = ["White" for i in range(len(graph))]
   dTime = [None for i in range(len(graph))]
   fTime = [None for i in range(len(graph))]
   predecessor = [None for i in range(len(graph))]

   sources = list(range(len(graph)))
   start = sources.pop(getVertex(start))
   sources = [start]+sources
   for source in sources:
      if(colors[source]=="White"):
         time+=1
         colors[source] = "Gray"
         dTime[source] = time
         visited.push(source)
         while(not visited.isEmpty()):
            current = visited.peek()
            adjecents = []
            adjList = graph[current]
            tempNode = adjList
            while(tempNode!=None):
               adjecents.append(tempNode.vertex)
               tempNode = tempNode.next
            adjecents.sort()
            currentVertex = None
            for i in range(len(adjecents)):
               if(colors[adjecents[i]]=="White"):
                  time +=1
                  currentVertex = adjecents[i]
                  colors[adjecents[i]]="Gray"
                  dTime[adjecents[i]]=time
                  predecessor[adjecents[i]] = current
                  break
            if(currentVertex==None):
               time +=1
               vertex = visited.pop()
               colors[vertex]="Black"
               dTime[vertex]=time
               order.append(vertexdata[vertex])
            else:
               visited.push(currentVertex)
   return order

print(dfs(graph,"A"))    
