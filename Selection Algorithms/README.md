# Selection algorithm
A selection algorithm is an algorithm for finding the kth smallest number in a list or array; such a number is called the kth order statistic. This includes the cases of finding the minimum, maximum, and median elements. There are O(n) time (worst-case linear time) selection algorithms, and sublinear performance is possible for structured data; in the extreme, O(1) for an array of sorted data. 

## Quick Select
Recursively call partition algorithm and reduce the search space according to the pivot. If the randomly selected pivot(index) is the desired index(selection), we simply return the index. Otherwise, if selected pivot index is less than the desired, we search in right subproblem, or left in case of selected pivot index is greater than the desired
## Median of Medians
Median of medians is used as a pivot selection strategy in the quickselect algorithm.
[Median-of-Medians](https://en.wikipedia.org/wiki/Median_of_medians)
## Intro Select
Introselect works by optimistically starting out with quickselect and only switching to a worst-case linear-time selection algorithm (the Blum-Floyd-Pratt-Rivest-Tarjan median of medians algorithm) if it recurses too many times without making sufficient progress. The switching strategy is the main technical content of the algorithm.
[Introselect Algorithm](https://en.wikipedia.org/wiki/Introselect)