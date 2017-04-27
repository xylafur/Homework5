#ifndef GRAPH_NODE
    #define GRAPH_NODE
#include <vector>
class Node{
private:
    std::vector<Node> nodes;
    int val;
public:
    Node(int val){
        this->val = val;
    }
    void addNode(Node node){
        this->nodes.push_back( node );
    }
    void getNodes(){
        return this->nodes;
    }

};

#endif
