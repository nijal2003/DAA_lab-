#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[][MAX], int V) {
    int parent[MAX], key[MAX];
    bool mstSet[MAX];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0] = 0, parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    int graph[MAX][MAX] = {0};
    cout << "Enter the edges and their weights: " << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w, graph[v][u] = w;
    }
    primMST(graph, V);
    return 0;
}
/*int V = 9;
	Graph g(V);

	// making above shown graph
	(0, 1, 4);
	(0, 7, 8);
	(1, 2, 8);
	(1, 7, 11);
	(2, 3, 7);
	(2, 8, 2);
	(2, 5, 4);
	(3, 4, 9);
	(3, 5, 14);
	(4, 5, 10);
	(5, 6, 2);
	(6, 7, 1);
	(6, 8, 6);
	(7, 8, 7);*/