#ifndef MST_LINKEDGRAPHEDGE_HPP_
#define MST_LINKEDGRAPHEDGE_HPP_

class LinkedGraphEdge {

public:
	int originNode;
	int destinationNode;
	int metric;
	
	LinkedGraphEdge() = default;
	LinkedGraphEdge(int origin, int destination, int metric);
	~LinkedGraphEdge() = default;
	
};

#endif //MST_LINKEDGRAPHEDGE_HPP_
