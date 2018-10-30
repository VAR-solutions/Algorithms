require 'test/unit'
require_relative 'dfs'

class DFSTest < Test::Unit::TestCase
  def test_validation_of_input
    assert_raises { DFS.new [] }
    assert_raises { DFS.new [[1, 2]] }
    DFS.new [
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
    expected = [0, 1, 2, 3]
    assert_equal expected, DFS.new(input).search(0)
  end
end