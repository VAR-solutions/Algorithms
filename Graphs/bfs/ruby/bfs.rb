# Implementation of Dfs on graphs
class Dfs
  def initialize(adjacences)
    @graph = validate adjacences
    @next = []
    @visited = []
  end

  def search(start)
    add_next start
    while next?
      current = next_node
      visit current
      @graph[current].each_with_index do |weight, node|
        next unless weight > 0
        add_next node
      end
    end
    @visited
  end

  private

  def add_next(node)
    return if @visited.include? node
    return if @next.include? node
    @next << node
  end

  def next?
    !@next.empty?
  end

  def next_node
    @next.first
  end

  def visit(node)
    @next.delete node
    @visited << node unless @visited.include? node
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