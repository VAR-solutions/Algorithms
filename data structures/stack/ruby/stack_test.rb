require 'test/unit'
require_relative 'stack'

class StackTest < Test::Unit::TestCase

  # Called before every test method runs. Can be used
  # to set up fixture information.
  def setup
    @sut = Stack.new
  end

  def test_can_push_elements
    @sut.push 1
    assert_false @sut.empty?
  end
  
  def test_can_pop
    element = 'foo'
    @sut.push element
    assert_equal element, @sut.pop
  end

  def test_cannot_pop_on_empty
    assert_raises { @sut.pop }
  end

  def test_can_push_multiple
    values = ['foo', nil, :bar, 42]
    values.each { |element| @sut.push element }
    values.reverse.each do |element|
      assert_equal element, @sut.pop
    end
  end
end