class Graph
    # builds a graph with the specified number of vertices.
    def initialize(vertices)
        @vertices = vertices
        @adjacency = vertices.times.collect{[]}
    end

    def addEdge(i, vertex)
        adjacency[i].push(vertex)
    end

    def dfs(element)
        visited = vertices.times.collect{false}
        dfs_run(element, visited)
    end


    private
    
    def dfs_run(v, visited)
        puts v
        visited[v] = true
        adjacency[v].each do |vertex| 
            if not visited[vertex]
                dfs_run(vertex, visited)
            end
        end
    end

    attr_reader :vertices, :adjacency
end

# Testing the code, values taken from https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
g = Graph.new(4)
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
  
puts "Following is Depth First Traversal (starting from vertex 2)"

g.dfs(2)    