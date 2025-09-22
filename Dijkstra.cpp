#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    int n = 5; // To apply algoritham i take only 5 nodes in the graph

    // graph represented as an adjacency matrix 0 means no edge between nodes
    vector<vector<int>> g = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int start, end;
    cout << "hey buddy enter start node (0-" << n-1 << "): ";
    cin >> start;
    cout << "plz enter end node (0-" << n-1 << "): ";
    cin >> end;

    // check if user entered nodes outside the graph to stop the program i write here
    if(start < 0 || start >= n || end < 0 || end >= n) {
        cout << "sorry buddy it has only " << n << " nodes (0-" << n-1 << ") i will do that code further" << endl;
        return 0;
    }

    // store shortest distance from start node to all other nodes
    vector<int> d(n, INT_MAX);

    // mark if we already visited a node
    vector<bool> vis(n, false);

    // keep track of parent nodes to print the path later
    vector<int> parent(n, -1);

    d[start] = 0; // distance from start to itself is 0

    // main loop of Dijkstra
    for(int i=0;i<n-1;i++) {
        int u=-1;

        // find the node with smallest distance which is not visited yet
        for(int j=0;j<n;j++) {
            if(!vis[j] && (u==-1 || d[j]<d[u])) {
                u=j;
            }
        }

        vis[u] = true; // here the mark this node as visited

        // this is for update distances for neighbors of u
        for(int v=0;v<n;v++) {
            // here i write if there is an edge and new distance is smaller to update it
            if(g[u][v] && d[u]!=INT_MAX && d[u]+g[u][v]<d[v]) {
                d[v] = d[u]+g[u][v];
                parent[v] = u; // to inform parent to print path later
            }
        }
    }

    // print the shortest path from start to end
    cout<<"hey buddy here the shortest path: ";
    vector<int> path;
    for(int v=end; v!=-1; v=parent[v]) {
        path.insert(path.begin(), v); // build path in correct order
    }

    for(int i=0;i<path.size();i++) {
        cout<<path[i];
        if(i!=path.size()-1) cout<<" -> "; // print arrow between nodes
    }

    cout<<"\nTotal cost: "<<d[end]<<endl; // print total distance

    return 0;
}
