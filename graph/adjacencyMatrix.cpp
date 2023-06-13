#include <bits/stdc++.h>
#define MAX_SIZE 1001

using namespace std;

class Graph {
    private:
    char vertices[MAX_SIZE];
    bool edges[MAX_SIZE][MAX_SIZE] = {0};
    int sizeOfV;
    vector <bool> visitedDfs;

    public:

    Graph() {
        sizeOfV = -1;
    }

    void addVertex(char v) {
        sizeOfV++;
        vertices[sizeOfV] = v;
        visitedDfs.push_back(false);
        return;
    }   

    void addEdge(char src, char dest) {
        int srcIndex = getIndex(src);
        int destIndex = getIndex(dest);
        if(srcIndex == -1 || destIndex == -1) {
            cout<<"Invalid verteces"<<endl;
            return;
        }
        edges[srcIndex][destIndex] = true;
        edges[destIndex][srcIndex] = true;
        return;
    }  

    void printMatrix() {
        for(int i = 0; i<= sizeOfV; i++) {
            cout<<i<<"-"<<vertices[i]<<", ";            
        }
        cout<<endl;
        for(int i = 0; i<= sizeOfV; i++) {
            for(int j = 0; j<= sizeOfV; j++) {
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    int getIndex(char ch) {
        for(int i = 0; i <= sizeOfV; i++) {
            if(vertices[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    void bfs(char sr)
    {
        // Visited vector to so that
        // a vertex is not visited more than once
        // Initializing the vector to false as no
        // vertex is visited at the beginning
        vector<bool> visited(sizeOfV, false);
        queue<int> q;
        int start = getIndex(sr);
        q.push(start);
    
        // Set source as visited
        visited[start] = true;
    
        int vis;
        while (!q.empty()) {
            vis = q.front();
    
            // Print the current node
            cout << vertices[vis] << " ";
            q.pop();
    
            // For every adjacent vertex to the current vertex
            for (int i = 0; i <= sizeOfV; i++) {
                if (edges[vis][i] == 1 && (!visited[i])) {
    
                    // Push the adjacent node to the queue
                    q.push(i);
    
                    // Set
                    visited[i] = true;
                }
            }
        }
    }
    
    void dfs(char sr)
    {
        int start = getIndex(sr);
        // Print the current node
        cout << vertices[start] << " ";
    
        // Set current node as visited
        visitedDfs[start] = true;
    
        // For every node of the graph
        for (int i = 0; i <= sizeOfV; i++) {
    
            // If some node is adjacent to the current node
            // and it has not already been visited
            if (edges[start][i] == 1 && (!visitedDfs[i])) {
                dfs(vertices[i]);
            }
        }
    }
};

int main() {
    Graph gp;
    gp.addVertex('A');
    gp.addVertex('B');
    gp.addVertex('C');
    gp.addVertex('D');
    gp.addVertex('E');
    gp.addVertex('F');
    gp.addVertex('G');
    gp.addVertex('H');
    gp.addVertex('I');

    gp.addEdge('A', 'B');
    gp.addEdge('B', 'C');
    gp.addEdge('C', 'F');
    gp.addEdge('F', 'I');
    gp.addEdge('D', 'A');
    gp.addEdge('E', 'D');
    gp.addEdge('G', 'D');
    gp.addEdge('G', 'H');
    gp.addEdge('E', 'H');

    gp.printMatrix();
    gp.bfs('A');
    cout<<endl;
    gp.dfs('A');
}