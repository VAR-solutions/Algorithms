# Minimum spanning tree
## Dijkstra-Jarník-Prim algorithm and Kruskal's algorithm

This is a C++11 implementation of the [Dijkstra-Jarník-Prim algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm) (also known as Prim's algorithm and Jarník's algorithm), as well as [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm), using an [Adjacency list](https://en.wikipedia.org/wiki/Adjacency_list) graph representation.

#### Files
* `prim.cpp` implements the Dijkstra-Jarník-Prim algorithm
* `kruskal.cpp` implements Kruskal's algorithm
* `mst.cpp` is a small program that generates random graphs, showcases these algorithms, and measures their runtime
* The `data-structures/` directory contains definitions and implementations of custom data structures used here

#### Building
There is a `Makefile` containing recipes for building the program. Run `make` to simply build the executable, or `make run` to build and run. All objects, as well as the executable, are placed inside the `out/` directory, which can also be manually created with `make init`. Further comments can be found in the `Makefile`.

You should also be able to build the program in any IDE of your choosing, on any platform that supports C++11.

#### Data structures
The graph structure is named `LinkedGraph`, which I recognise might be misleading: it doesn't actually link graph nodes or edges together through pointers. However, this name is the least lengthy/confusing that I could come up with. Feel free to refactor the heck out of it.

`ArrayList<T>` is a custom, generic implementation of a dynamic array that resizes itself at every addition and deletion. `LinkedList<T>` is a custom, generic, doubly-linked list. These have been taken directly from a university project and could probably be optimised considerably.

A graph is represented as an `ArrayList` of nodes. Each node is a `LinkedList` of edges connected to it. An edge has an origin node index, a destination node index, and a metric (edge 'weight'/'length').

#### Directionality
The DJP algorithm implementation treats the graph representation as undirected, whereas the Kruskal's algorithm implementation treats it as directed. Pretty much the only implication here is that DJP can find multiple connections (edges) between each pair of nodes, and it only considers the cheapest one for its spanning tree. The `LinkedGraph` structure can easily be used for purely undirected graphs as well, because it stores each edge in the lists of both end nodes.
