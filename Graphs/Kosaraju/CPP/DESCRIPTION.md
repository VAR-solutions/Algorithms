* <b>Decription</b> - This algorithm can be used to find a strongly connected components of a graph.</br>
  <p>The algorithm in steps can be described as below:</br>

     1.Do a  on the original graph, keeping track of the finish times of each node. This can be done with a stack, when some  finishes put the source vertex on the stack. This way node with highest finishing time will be on top of the stack.
     ```
	 stack STACK
	 void DFS(int source) {
     visited[s]=true
     for all neighbours X of source that are not visited:
        DFS(X)
     STACK.push(source)
	 }
	 ```

     2.Reverse the original graph, it can be done efficiently if data structure used to store the graph is an adjacency list.</br>
	 ```
	 CLEAR ADJACENCY_LIST
 	 for all edges e:
    	first = one end point of e
    	second = other end point of e
    	ADJACENCY_LIST[second].push(first)
     ```
     3.Do  on the reversed graph, with the source vertex as the vertex on top of the stack. When  finishes, all nodes visited will form one Strongly Connected Component. If any more nodes remain unvisited, this means there are more Strongly Connected Component's, so pop vertices from top of the stack until a valid unvisited node is found. This will have the highest finishing time of all currently unvisited nodes. This step is repeated until all nodes are visited.</br>
     ```
	 while STACK is not empty:
    	source = STACK.top()
    	STACK.pop()
    	if source is visited :
        	continue
    	else :
        	DFS(source)
  	 ```

* <b>Time Complexity</b> - O(V + E) : V and E are no. of vertices and edges in the graph respectively.

* <b>Test Case</b> :
  * Input :
    5 6
    1 4
    1 3
    2 4
    3 4
    4 5
    5 1
   
  * Output :
    -3
  
