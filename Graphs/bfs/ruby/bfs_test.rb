require 'test/unit'
require_relative 'bfs'

class DfsTest < Test::Unit::TestCase
  def test_validation_of_input
    assert_raises { Dfs.new [] }
    assert_raises { Dfs.new [[1, 2]] }
    Dfs.new [
                [1, 2],
                [3, 4]
            ]
  end

  def test_correct_order
    input = [
        [0, 1, 0, 1],
        [1, 0, 1, 0],
        [0, 1, 0, 1],
        [1, 0, 1, 0]
    ]
    expected = [0, 1, 3, 2]
    assert_equal expected, Dfs.new(input).search(0)
  end
end