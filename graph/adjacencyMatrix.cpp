#include <bits/stdc++.h>
#define MAX_SIZE 1001

using namespace std;

class Graph {
    private:
        char vertices[MAX_SIZE];
        bool edges[MAX_SIZE][MAX_SIZE] = {0};
        int sizeOfV;        

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
                cout<<"Invalid vertices"<<endl;
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
            cout<<endl<<endl;
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
            vector<bool> visited(sizeOfV, false);
            queue<int> q;

            int level[sizeOfV];
            char parent[sizeOfV];

            int start = getIndex(sr);
            q.push(start);

            visited[start] = true;
            level[0] = 0;
            parent[0] = 0;

            int currentNode;
            while (!q.empty()) {
                currentNode = q.front();
                q.pop();

                for (int i = 0; i <= sizeOfV; i++) {
                    if (edges[currentNode][i] == 1 && (!visited[i])) {
                        q.push(i);
                        visited[i] = true;
                        level[i] = level[currentNode] + 1;
                        parent[i] = currentNode;
                    }
                }
            }
            for(int i = 0; i <= sizeOfV; i++) {
                cout<<vertices[i]<<"-"<<level[i]<<"- Parent "<<vertices[parent[i]]<<endl;
            }
        }
        
        vector <bool> visitedDfs;
        void dfs(char sr)
        {
            int start = getIndex(sr);
            cout << vertices[start] << " ";
            visitedDfs[start] = true;
            for (int i = 0; i <= sizeOfV; i++) {

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

    gp.addEdge('A', 'B');
    gp.addEdge('A', 'E');
    gp.addEdge('B', 'C');
    gp.addEdge('B', 'D');
    gp.addEdge('C', 'D');
    gp.addEdge('D', 'E');
    gp.addEdge('A', 'E');

    gp.printMatrix();
    cout<<endl<<endl;
    cout<<"Breadth First Search"<<endl;
    gp.bfs('A');
    cout<<endl<<endl;
    cout<<"Depth First Search"<<endl;
    gp.dfs('A');

    cout<<endl<<endl;
}