/**
 * search for the shortest path between two vertices
 */

#pragma once

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename Graph>
class ShortestPath {
public:
    // BFS is used to search for the shortest path
    ShortestPath(Graph& graph, int sourceVertex) : graph(graph) {
        initializeParmeters(graph.getNumVertex());
        this->sourceVertex = sourceVertex;
        queue<int> qVertex;
        // push the source vertex
        qVertex.push(sourceVertex);
        order[sourceVertex] = 0;
        visited[sourceVertex] = true;
        while(!qVertex.empty()) {
            int currentVertex = qVertex.front();
            qVertex.pop();
            typename Graph::adjIterator adj(graph, currentVertex);
            for (int itr = adj.begin(); !adj.end(); itr = adj.next()) {
                if (!visited[itr]) {
                    qVertex.push(itr);
                    visited[itr] = true;
                    from[itr] = currentVertex;
                    order[itr] = order[currentVertex] + 1;
                }
            }
        }

    }

    ~ShortestPath() = default;

    void findPath(int targetVertex, vector<int>& pathVec) {
        assert(existPath(targetVertex));
        stack<int> pathStack;
        int currentVertex = targetVertex;
        while (currentVertex != -1) {
            pathStack.push(currentVertex);
            currentVertex = from[currentVertex];
        }
        pathVec.clear();
        while (!pathStack.empty()) {
            pathVec.push_back(pathStack.top());
            pathStack.pop();
        }
    }

    bool existPath(int targetVertex) {
        return visited[targetVertex];
    }

    void showPath(int targetVertex) {
        assert(existPath(targetVertex));
        vector<int> pathVec;
        findPath(targetVertex, pathVec);
        cout << "show path" << endl;
        for (auto ele : pathVec) {
            cout << ele << "\t->\t";
        }
        cout << endl;
    }

    void showFrom() {
        cout << "show from" << endl;
        for (int i = 0; i < graph.getNumVertex(); ++i) {
            cout << from[i] << "\t->\t";
        }
        cout << endl;
    }

    int length(int targetVertex) {
        return order[targetVertex];
    }

private:
    Graph& graph;
    int sourceVertex;
    bool* visited;
    int* order;
    int* from;

    void initializeParmeters(int numVertex) {
        visited = new bool[numVertex];
        order = new int[numVertex];
        from = new int[numVertex];
        for (int i = 0; i < numVertex; i++) {
            visited[i] = false;
            order[i] = -1;
            from[i] = -1;
        }
    }
};