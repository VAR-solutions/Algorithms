// Main DFS method 
dfs(startingNode) 
{ 
  
    var visited = []; 
    for (var i = 0; i < this.noOfVertices; i++) 
        visited[i] = false; 
  
    this.DFSUtil(startingNode, visited); 
} 
  
// Recursive function which process and explore 
// all the adjacent vertex of the vertex with which it is called 
DFSUtil(vert, visited) 
{ 
    visited[vert] = true; 
    console.log(vert); 
  
    var get_neighbours = this.AdjList.get(vert); 
  
    for (var i in get_neighbours) { 
        var get_elem = get_neighbours[i]; 
        if (!visited[get_elem]) 
            this.DFSUtil(get_elem, visited); 
    } 
}  
