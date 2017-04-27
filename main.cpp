#include <iostream>
#include <string>
#include "ArgumentManager.h"
#include <vector>
#include "node.h"
#include "graph.h"
#include "util.h"

int main(int argc, char *argv[] ){
    ArgumentManager am;
    UtilClass util;
    Graph graph;

    std::string filename = am.get("E");
    int source = util.toInt( am.get("source") );
    
    std::vector lines = readFileToVector( filename ); 

    for( int i = 0; i < lines.size(); i++){
        graph.addEntry( lines[i] );
    }

    std::cout << graph.getReachable( source );
    return 0;
}
