
#include "Component.h"
#include "DenseGraph.h"
#include "Helper.h"
#include "Path.h"
#include "ReadGraph.h"
#include "ShortestPath.h"
#include "SparseGraph.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {

    string projPath{"/home/strobe/search-graph/"};

    bool directed{false};

    /**
     * // as an alternative in this section the graph is generated with random variblas
     * int numVertex{20};
     * int numEdge{100};
     * vector<pair<int, int>> edgeList = calcEdges(numVertex, numEdge);
     * for (auto edge : edgeList) {
     *      denseGraph.addEdge(edge.first, edge.second);
     *      sparseGraph.addEdge(edge.first, edge.second);
     * }
     */

    // sparse graph
    int numVertex1 = 13;

    SparseGraph sparseGraph1(numVertex1, directed);
    string sparseGraphFileName1 = projPath + "./testG1.txt";
    ReadGraph<SparseGraph>(sparseGraphFileName1, sparseGraph1);
    Component<SparseGraph> graphComponent1(sparseGraph1);
    cout << "Graph 1" << endl;
    cout << "# of components in graph 1 = " << graphComponent1.getComponentCount() << endl;
    sparseGraph1.showGraph();

    // path in the graph
    int sourceVertex1{0}, targetVertex1{6};
    // use DFS
    Path<SparseGraph> pathSparseGraph1(sparseGraph1, sourceVertex1);
    bool existPath = pathSparseGraph1.existPath(targetVertex1);
    cout << "source = " << sourceVertex1 << " and target = " << targetVertex1 << endl;
    cout << "DFS" << endl;
    cout << "path exist? " << existPath << endl;
    if (existPath) {
        pathSparseGraph1.showPath(targetVertex1);
    }
    // use BFS
    ShortestPath<SparseGraph> sortestPathGraph1(sparseGraph1, sourceVertex1);
    cout << "BFS" << endl;
    bool existPathBFS = sortestPathGraph1.existPath(targetVertex1);
    cout << "path exist? " << existPathBFS << endl;
    if (existPathBFS) {
        sortestPathGraph1.showPath(targetVertex1);
    }

    int numVertex2 = 7;
    SparseGraph sparseGraph2(numVertex2, directed);
    string sparseGraphFileName2 = projPath + "testG2.txt";
    ReadGraph<SparseGraph>(sparseGraphFileName2, sparseGraph2);
    Component<SparseGraph> graphComponent2(sparseGraph2);
    cout << "\nGraph 2" << endl;
    cout << "# of components in graph 2 = " << graphComponent2.getComponentCount() << endl;
    sparseGraph2.showGraph();

    // path in the graph
    int sourceVertex2{0}, targetVertex2{6};
    Path<SparseGraph> pathSparseGraph2(sparseGraph2, sourceVertex2);
    bool existPath2 = pathSparseGraph1.existPath(targetVertex2);
    cout << "source = " << sourceVertex2 << " and target = " << targetVertex2 << endl;
    cout << "DFS" << endl;
    cout << "path exist? " << existPath2 << endl;
    if (existPath2) {
        pathSparseGraph2.showPath(targetVertex2);
        pathSparseGraph2.showFrom();
    }
    ShortestPath<SparseGraph> shortestPathGraph2(sparseGraph2, sourceVertex2);
    bool existPath2BFS = shortestPathGraph2.existPath(targetVertex2);
    cout << "DFS" << endl;
    cout << "path exist? " << existPath2BFS << endl;
    if (existPath2BFS) {
        shortestPathGraph2.showPath(targetVertex2);
        shortestPathGraph2.showFrom();
    }
}
