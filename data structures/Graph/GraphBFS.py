class Node:
   def __init__(self,vertex):
      self.vertex = vertex
      self.next = None

userinput = str(input("Number of nodes and edges : ")).split() #First line as a string and split (from spaces) it to an array.
N = int(userinput[0]) #Extract Number of vertexes
M = int(userinput[1]) #Extract Number of edges

graph = [] #Create an array to hold the graph
for i in range(N):
   graph.append(None)

#Requesting next M lines of inputs which are the description of edges
for i in range(M):
   edges = str(input("Edge if between vertexes  : ")).split() #string input line of the user splitted in to an array
   fromVertex = int(edges[0]) #extracting the 1st vertex of the user input and assigning it to fromVertex
   toVertex = int(edges[1])#extracting the 2nd vertex of the user input and assigning it to toVertex

   #Now let us create a node to toVertex and put that it to a/the linkedlist in the postion of fromVertex in the main graph
   node = Node(toVertex) #creating the node
   #if there's no linkedlist already in that position, then put the node there
   if(graph[fromVertex-1]== None): 
      graph[fromVertex-1] = node
   else:
   #if there's already a linkedlist append the linkedlist to the newly created node and put that in to the position of fromNode in the main graph
      node.next = graph[fromVertex-1]
      graph[fromVertex-1] = node

def bfs(graph,source):
   color = []
   distance = []
   for i in range(len(graph)):
      color.append("white")
      distance.append(None)
   color[source-1] = "gray"
   distance[source-1] = 0
   Queue = []
   Queue.append(source)
   while(len(Queue)!=0):
      u = Queue.pop(0)
      node = graph[u-1]
      while(node!=None):
         if(color[node.vertex-1]=="white"):
            Queue.append(node.vertex)
            color[node.vertex-1]="gray"
            distance[node.vertex-1] = distance[u-1]+1
         node = node.next
      color[u-1] = "black"
   return distance

#Now let us see how we can use this BFS
#If you want to print distances from 3 to other vertexes, call bfs function with the source vertex 3.
print(bfs(graph,3))















      
