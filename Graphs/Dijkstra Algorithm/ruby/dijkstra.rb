# Implementation of Dijkstra algorithm
class Dijkstra
  def initialize(adjacences)
    @graph = validate adjacences
    # NOTE: if a node has a final distance of -1 it is not reachable from the start node
    @distances = Array.new(adjacences.size) { -1 }
    # could be used to reconstruct the way to the node from the start
    @previous = Array.new(adjacences.size) { nil }
    @visited = []
    @next = []
  end

  def find_shortest_paths(start)
    validate_start start
    @distances[start] = 0
    add_next start
    while next?
      current = next_node
      visit current
      @graph[current].each_with_index do |weight, node|
        # There is a connection between the two nodes
        if weight > 0
          add_next node
          distance = @distances[current] + weight
          if distance < @distances[node] || @distances[node] == -1
            @distances[node] = distance
            @previous[node] = current
          end
        end
      end
    end
    @distances
  end

  private

  def add_next(node)
    return if @visited.include? node

    @next.push node
    @next.uniq!
  end

  def next?
    !@next.empty?
  end

  def next_node
    smallest = -1
    smallest_index = -1
    @next.each do |index|
      value = @distances[index]
      if value > -1 && (value < smallest || smallest == -1)
        smallest = value
        smallest_index = index
      end
    end
    smallest_index
  end

  def visit(node)
    @next.delete node
    @visited.push node
    @visited.uniq!
  end

  def validate_start(index)
    raise ArgumentError if index < 0 || index >= @graph.size
  end

  def validate(adjacences)
    raise ArgumentError unless adjacences.is_a? Array

    dimension = adjacences.size
    raise ArgumentError if dimension < 1

    adjacences.each do |row|
      raise ArgumentError unless row.is_a? Array

      raise ArgumentError if row.size != dimension
    end
    adjacences
  end
end
