defmodule BubbleSort do
  @moduledoc """
  This modules implements the bubble sort algorithm

  Bubble sort, sometimes referred to as sinking sort, is \
   a simple sorting algorithm that repeatedly steps through \
   the list to be sorted, compares each pair of adjacent items \
   and swaps them if they are in the wrong order. The pass \
   through the list is repeated until no swaps are needed, \
   which indicates that the list is sorted. (https://en.wikipedia.org/wiki/Bubble_sort)

  for beginners to elixir, I tried to use some nice features of the language as:
  - Accessing elements of a list with pattern-matching in function's parameters
  - Pattern-matching in parameters instead of 'if' statements
  - Function *guards* instead of 'if' statements
  - One-line functions and multi-line functions
  - Adding elements to the head of a list with [a | x] command
  - function *specs*
  - doctest
  """

  @doc """
  This function will execute the sort

  ## Examples

      iex> BubbleSort.sort(1..10 |> Enum.shuffle)
      [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

  """
  @spec sort(list()) :: list()
  def sort(list) do
    do_sort(list, [], :sorted)
  end

  defp do_sort([a, b | tail], acc, _) when a < b, do: do_sort([a | tail], [b | acc], :unsorted)
  defp do_sort([a, b | tail], acc, sorted?), do: do_sort([b | tail], [a | acc], sorted?)
  defp do_sort([x], acc, :unsorted), do: Enum.reverse([x | acc]) |> do_sort([], :sorted)
  defp do_sort([x], acc, :sorted), do: [x | acc]
end
