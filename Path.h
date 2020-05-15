//
// Created by strobe on 4/19/20.
//

#pragma once

#include <stack>
#include <vector>

template<typename GraphType>
class Path {
public:
    Path(GraphType& graph, int sourceVertex) : graph(graph) {
        setVisitedFrom(graph.getNumVertex());
        this->sourceVertex = sourceVertex;
        // path finding
        dfs(sourceVertex);
    }

    ~Path() = default;

    // if there is a path from source to target
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

private:
    GraphType& graph;
    int sourceVertex;
    bool* visited;
    int* from;

    void setVisitedFrom(int numVertex) {
        visited = new bool[numVertex];
        from = new int[numVertex];
        for (int i = 0; i < numVertex; ++i) {
            visited[i] = false;
            from[i] = -1;
        }
    }

    void dfs(int currentVertex) {
        visited[currentVertex] = true;
        typename GraphType::adjIterator adj(graph, currentVertex);
        for (int itr = adj.begin(); !adj.end(); itr = adj.next()) {
            if (!visited[itr]) {
                from[itr] = currentVertex;
                dfs(itr);
            }
        }
    }
};