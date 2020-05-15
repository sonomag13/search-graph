/**
 * this class is used to manage a sparse graph
 */

#pragma once

class SparseGraph {

public:

    // constructor and destructor
    SparseGraph(int numVertex, bool isDirected) {
        this->numVertex = numVertex;
        this->isDirected = isDirected;
        for (int i = 0; i < numVertex; ++i)
            graphList.push_back(vector<int>());
    }

    ~SparseGraph() = default;

    // add edge between two vertices
    void addEdge(int i, int j) {
        qualifyIdx(i);
        qualifyIdx(j);
        if (existEdge(i, j))
            return;
        graphList[i].push_back(j);
        // i != j exclude the self loop
        if (i != j && !isDirected)
            graphList[j].push_back(i);
        numEdge++;
    }

    bool existEdge(int i, int j) {
        qualifyIdx(i);
        qualifyIdx(j);
        for (int k = 0; k < graphList[i].size(); ++k)
            if (graphList[i][k] == j)
                return true;
        return false;
    }

    // getters
    int getNumVertex() {
        return numVertex;
    }

    int getNumEdge() {
        return numEdge;
    }

    vector<vector<int>> getGraphList() {
        return graphList;
    }

    void showGraph() {
        cout << "\nprint out sparse graph" << endl;
        for (int i = 0; i < numVertex; ++i) {
            cout << "vertex " << i << ": ";
            for (int j = 0; j < graphList[i].size(); ++j)
                cout << "\t" << graphList[i][j];
            cout << endl;
        }
    }

    // iterator
    class adjIterator {
    public:
        adjIterator(SparseGraph& sparseGraph, int v) : sparseGraph(sparseGraph) {
            this->v = v;
            this->idx = 0;
        }

        ~adjIterator() = default;

        int begin() {
            idx = 0;
            if (sparseGraph.graphList.size())
                return sparseGraph.graphList[v][idx];
            return -1;
        }

        int next() {
            idx++;
            if (idx < sparseGraph.graphList[v].size())
                return sparseGraph.graphList[v][idx];
            return -1;
        }

        bool end() {
            return idx >= sparseGraph.graphList[v].size();
        }

    private:
        SparseGraph& sparseGraph;
        int v;
        int idx;
    };

private:
    int numVertex{0};
    int numEdge{0};
    bool isDirected{false};
    vector<vector<int>> graphList;

    void qualifyIdx(int idx) {
        assert(idx >= 0 && idx < numVertex);
    }
};
