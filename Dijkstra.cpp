#include <iostream>
using namespace std;

#define ROW 10
#define COL 10
#define INFI 9999

class Dijkstra {
    int graph[ROW][COL], Nodes, Edges;
    int Visited[ROW];
    int DIST[ROW]; // Holds distance values

public:
    Dijkstra() {
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                graph[i][j] = INFI;
            }
            Visited[i] = 0;
            DIST[i] = INFI;
        }
    }

    void createGraph() {
        cout << "Enter number of nodes: ";
        cin >> Nodes;
        cout << "Enter number of edges: ";
        cin >> Edges;

        int s, d, w;
        cout << "Enter edges (source destination weight):" << endl;
        for (int i = 0; i < Edges; ++i) {
            cout << "Edge " << i + 1 << ": ";
            cin >> s >> d >> w;
            graph[s][d] = w;
            graph[d][s] = w; // If it's an undirected graph
        }
    }

    int MIN(int a, int b) {
        return (a < b) ? a : b;
    }

    int Smallest_of_Array() {
        int min = INFI, index = -1;
        for (int i = 0; i < Nodes; ++i) {
            if (Visited[i] == 0 && DIST[i] < min) {
                min = DIST[i];
                index = i;
            }
        }
        return index;
    }

    void DJ_Algo() {
        int Min, SRC, Edge_count = 0;
        cout << "Enter source node: ";
        cin >> SRC;

        DIST[SRC] = 0;

        while (Edge_count < Nodes) {
            int Selected_node = Smallest_of_Array();
            if (Selected_node == -1) break; // No more nodes to explore

            Visited[Selected_node] = 1;
            Edge_count++;

            for (int j = 0; j < Nodes; ++j) {
                if (graph[Selected_node][j] != INFI && Visited[j] == 0) {
                    if (DIST[Selected_node] + graph[Selected_node][j] < DIST[j]) {
                        DIST[j] = DIST[Selected_node] + graph[Selected_node][j];
                    }
                }
            }
        }
        cout<<"Shortest Distance from node "<<SRC<<endl;
        for (int i = 0; i < Nodes; ++i) {
            cout << "To Node " << i << ": Distance = " << DIST[i] << endl;
        }
    }
    

    
};

int main() {
    Dijkstra d;
    d.createGraph();
    d.DJ_Algo();
  
    return 0;
}
