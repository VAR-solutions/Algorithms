# Implementation of a priority queue
class PriorityQueue
  def initialize
    @first = nil
  end

  def push(element, weight)
    elem = QueueElement.new element, weight, nil
    return @first = elem if empty?

    if weight > @first.weight
      elem.next = @first
      return @first = elem
    end

    prev = @first
    while true
      current = prev.next
      return prev.next = elem if current.nil?

      next prev = current if weight <= current.weight

      prev.next = elem
      return elem.next = current
    end
  end

  def next
    temp = @first
    @first = @first.next
    temp.element
  end

  def empty?
    @first.nil?
  end

  private

  class QueueElement
    attr_accessor :element, :weight, :next

    def initialize(element, weight, next_element)
      @element = element
      @weight = weight
      @next = next_element
    end
  end
end