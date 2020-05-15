//
// Created by strobe on 4/18/20.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printAdjacentMatrix(vector<vector<T>> matIn) {
    cout << "\nprint out the graph\n" << endl;
    for (auto v1 : matIn) {
        for (auto v2 : v1) {
            cout << "\t" << v2;
        }
        cout << endl;
    }
}

template<typename T>
void printAdjacentList(vector<vector<T>> listIn) {
    cout << "\nprint out the graph\n" << endl;
    int k = 0;
    for (auto v1 : listIn) {
        cout << k++ << ": ";
        for (auto v2 : v1) {
            cout << "\t" << v2;
        }
        cout << endl;
    }
}

vector<pair<int, int>> calcEdges(int numVertex, int numEdge) {
    vector<pair<int, int>> vecOut;
    srand(time(NULL));
    for (int i = 0; i < numEdge; ++i) {
        vecOut.push_back(make_pair(rand() % numVertex, rand() % numVertex));
    }
    return vecOut;
}
