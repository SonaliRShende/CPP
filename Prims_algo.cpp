#include <iostream>
using namespace std;

#define ROW 10
#define COL 10
#define INFI 9999

class Prims {
    int graph[ROW][COL], nodes, edges;
    int visited[ROW];

public:
    Prims() {
        // Initialize the adjacency matrix and visited array
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                graph[i][j] = INFI;
            }
            visited[i] = 0;
        }
    }

    void createGraph() {
        // Input number of nodes and edges
        cout << "Enter number of nodes: ";
        cin >> nodes;
        cout << "Enter number of edges: ";
        cin >> edges;

        int s, d, w;
        cout << "Enter edges (source destination weight):" << endl;
        for (int i = 0; i < edges; ++i) {
            cout << "Edge " << i + 1 << ": ";
            cin >> s >> d >> w;
            graph[s][d] = w;
            graph[d][s] = w;
        }
    }

    void Pr_Algo() {
        int Min, Cost = 0, Edge_count = 1;
        visited[0] = 1; // Assuming source is 0th node

        while (Edge_count < nodes) {
            Min = INFI;
            int i, j;

            // Finding the minimum edge
            for (i = 0; i < nodes; ++i) {
                if (visited[i] == 1) {a
                    for (j = 0; j < nodes; ++j) {
                        if (graph[i][j] < Min && i != j && visited[j] == 0) {
                            Min = graph[i][j];
                            cout << "Edge included: " << i << " - " << j << " Weight: " << graph[i][j] << endl;
                        }
                    }
                }
            }

            Cost += Min;
            visited[j - 1] = 1;
            Edge_count++;
        }

        cout << "Total cost of Minimum Spanning Tree: " << Cost << endl;
    }
};

int main() {
    Prims p;
    p.createGraph();
    p.Pr_Algo();

    return 0;
}


