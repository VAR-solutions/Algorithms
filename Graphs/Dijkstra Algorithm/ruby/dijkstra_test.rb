require 'test/unit'
require_relative 'dijkstra'

class DijkstraTest < Test::Unit::TestCase
  def test_invalid_dimensions
    input = [
        [1, 2],
        [2, 3, 4]
    ]
    assert_raises { Dijkstra.new input }
  end

  def test_invalid_empty_input
    assert_raises { Dijkstra.new [] }
  end

  def test_invalid_start
    input = [
        [1, 2],
        [3, 4]
    ]
    dijkstra = Dijkstra.new input
    assert_raises { dijkstra.find_shortest_paths -1 }
    assert_raises { dijkstra.find_shortest_paths 2 }
  end

  # Fake test
  def test_find_shortest_paths
    input = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    expected = [12, 8, 0, 7, 14, 4, 6, 7, 2]
    dijkstra = Dijkstra.new input
    actual = dijkstra.find_shortest_paths 2

    assert_equal expected, actual
  end
end
