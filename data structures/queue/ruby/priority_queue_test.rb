require 'test/unit'
require_relative 'priority_queue'

class PriorityQueueTest < Test::Unit::TestCase
  def setup
    @sut = PriorityQueue.new
  end

  def test_correct_push
    @sut.push :foo, 42
    @sut.push 'bar', 3
    @sut.push 'baz', 3
    @sut.push 42, 1024

    assert_equal 42, @sut.next
    assert_equal :foo, @sut.next
    assert_equal 'bar', @sut.next
    assert_equal 'baz', @sut.next
  end

  def test_error_on_empty_next
    assert_raises { @sut.next }
  end

  def test_empty_check
    assert_true @sut.empty?
    @sut.push 'foo', 42
    assert_false @sut.empty?
    @sut.next
    assert_true @sut.empty?
  end
end