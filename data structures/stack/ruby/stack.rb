# Example implementation of a stack
class Stack
  def initialize
    @first = nil
  end

  def push(element)
    @first = StackElement.new element, @first
  end

  def pop
    raise ArgumentError if @first.nil?
    value = @first.value
    @first = @first.next
    value
  end

  def empty?
    @first.nil?
  end

  private

  class StackElement
    attr_accessor :value, :next

    def initialize(value, next_element)
      @value = value
      @next = next_element
    end
  end
end