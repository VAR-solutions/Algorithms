defmodule QuickSort do
  @moduledoc """
  This modules implements the quick sort algorithm.

  Quicksort (sometimes called partition-exchange sort) is an efficient \
   sorting algorithm, serving as a systematic method for placing the \
   elements of an array in order. Developed by British computer scientist \
   Tony Hoare in 1959[1] and published in 1961,[2] it is still a commonly \
   used algorithm for sorting. When implemented well, it can be about two \
   or three times faster than its main competitors, merge sort and heapsort. \
   (https://en.wikipedia.org/wiki/Quicksort)

  This module has two implementations of the algorithm.
  The diference is how the lists ar manipulated. The sort\1 function always \
  mantain a flatted by concatenating lists, but it's not very performatic in Elixir.\
  while the second implementation sort2\1 only adds to the head of lists or creates \
  new lists of lists leaving the flattening to the last moment, what i expect to be faster.
  """

  def sort([head | tail]) do
    tail
    |> Enum.reduce(%{smaller: [], pivot: head, larger: []}, fn elem, acc ->
      case elem > acc.pivot do
        true -> %{acc | larger: [elem | acc.larger]}
        false -> %{acc | smaller: [elem | acc.smaller]}
      end
    end)
    |> next()
  end

  defp next(%{smaller: [], pivot: head, larger: []}), do: [head]
  defp next(%{smaller: [], pivot: head, larger: larger}), do: [head | sort(larger)]
  defp next(%{smaller: smaller, pivot: head, larger: []}), do: sort(smaller) ++ [head]
  defp next(%{smaller: smaller, pivot: head, larger: larger}),
    do: sort(smaller) ++ [head | sort(larger)]

  def sort2([]), do: []
  def sort2(x) when is_integer(x), do: x
  def sort2([head | tail]) do
    tail
    |> Enum.reduce([[], head, []], fn elem, acc ->
      [smaller, pivot, bigger] = acc

      case elem > pivot do
        true -> [smaller, pivot, [elem | bigger]]
        false -> [[elem | smaller], pivot, bigger]
      end
    end)
    |> Enum.map(&sort2(&1))
    |> List.flatten()
  end
end
