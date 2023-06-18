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

        void addUndirectedEdge(char src, char dest) {
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

        void addDirectedEdge(char src, char dest) {
            int srcIndex = getIndex(src);
            int destIndex = getIndex(dest);
            if(srcIndex == -1 || destIndex == -1) {
                cout<<"Invalid vertices"<<endl;
                return;
            }
            edges[srcIndex][destIndex] = true;
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

        void bfs(char sr) {
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
        
        vector <int> visitedDfs;
        void dfs(char sr) {
            int start = getIndex(sr);
            cout << vertices[start] << " ";
            visitedDfs[start] = true;
            for (int i = 0; i <= sizeOfV; i++) {

                if (edges[start][i] == 1 && (!visitedDfs[i])) {
                    dfs(vertices[i]);
                }
            }
        }

        vector <int> discover;
        vector <int> finish;
        vector <int> previous;
        vector <string> color;
        int time;
        void dfs() {
            for(int i = 0; i <= sizeOfV; i++) {
                color.push_back("white");
                previous.push_back(-1);
                discover.push_back(-1);
                finish.push_back(-1);
            }
            time = 0;
            for(int i = 0; i <= sizeOfV; i++) {
                if(color[i] == "white") {
                    DFS_Visit(i);
                }
            }
            for(int i = 0; i <= sizeOfV; i++) {
                cout<<vertices[i]<<" - Discover Time: "<<discover[i]<<" - Finish Time: "<<finish[i]<<endl;
            }
        }

        void DFS_Visit(int currentNode) {
            color[currentNode] = "gray";
            time++;
            discover[currentNode] = time;
            for(int i = 0; i <= sizeOfV; i++) {
                if(edges[currentNode][i] == true && color[i] == "white") {
                    previous[i] = currentNode;
                    DFS_Visit(i);
                }
            }

            color[currentNode] = "black";
            // cout<<vertices[currentNode]<<" ";
            time++;
            finish[currentNode] = time;
        }

        void isBipertite(char src) {
            queue <int> q;
            int source = getIndex(src);
            q.push(source);

            string color[sizeOfV] = {"white"};
            color[source] = "red";

            int currentNode;
            while(!q.empty()) {
                currentNode = q.front();
                q.pop();

                for(int i = 0; i <= sizeOfV; i++) {
                    if(edges[currentNode][i] == 1) {
                        if(color[i] == "white") {
                            if(color[currentNode] == "red") {
                                color[i] = "blue";
                            } else {
                                color[i] = "red";
                            }
                            q.push(i);
                        }
                    }
                    if(color[currentNode] == color[i]) {
                        cout<<"Not bipertite"<<endl;
                        return;
                    }
                }

            }
            cout<<"Bipertite"<<endl;
            return;
        }
};

int main() {
    Graph undirectedGP;
    undirectedGP.addVertex('A');
    undirectedGP.addVertex('B');
    undirectedGP.addVertex('C');
    undirectedGP.addVertex('D');
    undirectedGP.addVertex('E');

    undirectedGP.addUndirectedEdge('A', 'B');
    undirectedGP.addUndirectedEdge('A', 'E');
    undirectedGP.addUndirectedEdge('B', 'C');
    undirectedGP.addUndirectedEdge('B', 'D');
    undirectedGP.addUndirectedEdge('C', 'D');
    undirectedGP.addUndirectedEdge('D', 'E');

    undirectedGP.printMatrix();
    cout<<endl<<endl;
    cout<<"Breadth First Search"<<endl;
    undirectedGP.bfs('A');
    cout<<endl<<endl;
    cout<<"Depth First Search"<<endl;
    undirectedGP.dfs('A');
    cout<<endl<<endl;
    undirectedGP.isBipertite('A');
    cout<<endl<<endl;

    Graph directedGraph;
    directedGraph.addVertex('A');
    directedGraph.addVertex('B');
    directedGraph.addVertex('C');
    directedGraph.addVertex('D');

    directedGraph.addDirectedEdge('A', 'D');
    directedGraph.addDirectedEdge('B', 'A');
    directedGraph.addDirectedEdge('B', 'C');
    directedGraph.addDirectedEdge('C', 'D');
    directedGraph.printMatrix();
    directedGraph.dfs();


}