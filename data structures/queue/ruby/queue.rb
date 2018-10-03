# Implementation of Queue data structure
class Queue
  def initialize
    @first = nil
    @last = nil
  end

  def enqueue(value)
    element = QueueElement.new value, nil
    # NOTE: only set @first when empty
    @first = element if empty?
    # safety check for empty Queue
    @last.next = element unless empty?
    @last = element
  end

  def dequeue
    raise ArgumentError if @first.nil?

    value = @first.value
    @first = @first.next
    @last = @first if @first.nil?
    value
  end

  def empty?
    @first.nil? || @last.nil?
  end

  private

  class QueueElement
    attr_accessor :value, :next

    def initialize(value, next_element)
      @value = value
      @next = next_element
    end
  end
end