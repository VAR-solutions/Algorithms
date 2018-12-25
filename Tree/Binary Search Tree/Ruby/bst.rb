class BinarySearchTree
  class Node
    attr_reader :key, :left, :right
    def initialize( key )
      @key = key
      @left = nil
      @right = nil
    end

    def insert( new_key )
      if new_key <= @key
        @left.nil? ? @left = Node.new( new_key ) : @left.insert( new_key )
      elsif new_key > @key
        @right.nil? ? @right = Node.new( new_key ) : @right.insert( new_key )
      end
    end
  end

  def initialize
    @root = nil
  end

  def insert( key )
    if @root.nil?
      @root = Node.new( key )
    else
      @root.insert( key )
    end
  end

  def in_order(node=@root, &block)
    return if node.nil?
    in_order(node.left, &block)
    yield node
    in_order(node.right, &block)
  end

  def pre_order(node=@root, &block)
    return if node.nil?
    yield node
    in_order(node.left, &block)
    in_order(node.right, &block)
  end

  def post_order(node=@root, &block)
    return if node.nil?
    in_order(node.left, &block)
    in_order(node.right, &block)
    yield node
  end
 
  def search( key, node=@root )
    return nil if node.nil?
    if key < node.key
      search( key, node.left )
    elsif key > node.key
      search( key, node.right )
    else
      return node
    end
  end

  def check_height(node)
    return 0 if node.nil?

    leftHeight = check_height(node.left)
    return -1 if leftHeight == -1

    rightHeight = check_height(node.right)
    return -1 if rightHeight == -1

    diff = leftHeight - rightHeight
    if diff.abs > 1
      -1
    else
      [leftHeight, rightHeight].max + 1
    end
  end

  def is_balanced?(node=@root)
    check_height(node) == -1 ? false : true
  end

end

tree = BinarySearchTree.new
tree.insert(50)
tree.insert(25)
tree.insert(75)
tree.insert(12)
tree.insert(37)
tree.insert(87)
tree.insert(63)
puts tree.inspect
puts "tree.is_balanced?"
puts tree.is_balanced?

puts "pre_order"
tree.pre_order do |node|
  puts node.key
end

puts "in_order"
tree.in_order do |node|
  puts node.key
end

puts "post_order"
tree.post_order do |node|
  puts node.key
end
