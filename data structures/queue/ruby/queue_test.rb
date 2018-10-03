require 'test/unit'
require_relative 'queue'

class QueueTest < Test::Unit::TestCase
  def setup
    @sut = Queue.new
  end

  def test_can_enqueue
    @sut.enqueue 'foo'
    assert_false @sut.empty?
  end

  def test_can_dequeue
    element = 'foo'
    @sut.enqueue element
    assert_equal element, @sut.dequeue
  end

  def test_empty_queue
    assert_true @sut.empty?
    @sut.enqueue 42
    assert_false @sut.empty?
  end

  def test_multiple_inputs
    elements = ['foo', nil, :bar, 42]
    elements.each { |element| @sut.enqueue element }
    assert_false @sut.empty?
    elements.each do |element|
      assert_equal element, @sut.dequeue
    end
    assert_true @sut.empty?
  end
end