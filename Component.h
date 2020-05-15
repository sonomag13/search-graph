/**
 * this class is used to check if two vertices are connected
 */
#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template<typename GraphType>
class Component {
public:

    // constructor and destructor
    Component(GraphType& graphIn) : graph(graphIn) {
        int numVertex = graphIn.getNumVertex();
        setVisited(numVertex);
        cntComp = 0;
        for (int i = 0; i < numVertex; ++i)
            if (!visited[i]) {
                dfs(i);   // dfs is used for the searching
                cntComp++;
            }
    }

    ~Component() = default;

    // getters
    int getComponentCount() {
        return cntComp;
    }

    bool isConnected(int vertex1, int vertex2) {
        return compID[vertex1] == compID[vertex2];
    }

private:
    GraphType& graph;
    bool* visited;
    int* compID;
    int cntComp;

    void setVisited(int numVertex) {
        visited = new bool[numVertex];
        compID = new int[numVertex];
        for (int i = 0; i < numVertex; ++i) {
            visited[i] = false;
            compID[i] = -1;
        }
    }

    // dfs
    void dfs(int v) {
        visited[v] = true;
        compID[v] = cntComp;
        typename GraphType::adjIterator adj(graph, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }
};