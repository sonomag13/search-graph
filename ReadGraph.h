//
// Created by strobe on 4/18/20.
//

#pragma one

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<typename Graph>
class ReadGraph {
public:
    ReadGraph(const string& fileName, Graph& graph) {
        // ifstream fileID(fileName);
        fstream fileID;
        fileID.open(fileName);
        string readLine;
        int numVertex, numEdge;
        assert(fileID.is_open());
        assert(getline(fileID, readLine));
        stringstream ss(readLine);
        ss >> numVertex >> numEdge;
        assert(graph.getNumVertex() == numVertex);
        while (numEdge) {
            assert(getline(fileID, readLine));
            int v1, v2;
            stringstream ss(readLine);
            ss >> v1 >> v2;
            graph.addEdge(v1, v2);
            numEdge--;
        }
    }
};