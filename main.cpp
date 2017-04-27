#include <iostream>
#include <string>
#include "ArgumentManager.h"
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

class Graph{
private:
    std::vector<Node> nodes;
public:
    Graph(){

    }
    void addEntry( std::string str ){

    }
    std::string getReachable( int startPoint ){
        
    }
};

//Util functions
class UtilClass{
private:
    std::string str;
public:
    UtilClass(){}

    std::vector<std::string> splitBy(std::string str, char split){
        int lastPos = 0;
        std::vector<std::string> ret;

        for( int i = 0; i < str.length(); i++){
            if(str.at(i) == split ){
                std::string temp = str.substr(lastPos, i-lastPos);
                lastPos = i+1;
                ret.push_back(temp);
            }
        }
        ret.push_back( str.substr(lastPos));
        return ret;
    }
    std::vector<std::string> readFileToVector(std::string filename){
        std::fstream file;
        file.open(filename);
        std::vector<std::string> ret;
        std::string line;

        if(file.is_open()){
            while(getline(file, line)){
                ret.push_back(line);
            }
            file.close();
        }

        return ret;
    }

    int toInt(std::string str1){
        int ret = 0;
        for( int i = 0; i < str1.length(); i++){
            if(str1.at(i)==' ')
                continue;
            ret *= 10;
            ret += int((str1.at(i) - '0'));
        }
        return ret;
    }
};

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
