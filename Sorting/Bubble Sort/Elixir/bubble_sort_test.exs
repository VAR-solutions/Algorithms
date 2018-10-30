defmodule BubbleSortTest do
  use ExUnit.Case
  doctest BubbleSort

  test "sorting succefully" do
    input = 1..1000 |> Enum.shuffle()

    expected_result = input |> Enum.sort()

    assert BubbleSort.sort(input) == expected_result
  end
end
