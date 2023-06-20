#include <bits/stdc++.h>
#define MAX_SIZE 101
#define INF 9999999

using namespace std;

class Graph {
    private:
        int vert[MAX_SIZE];
        int edges[MAX_SIZE][MAX_SIZE] = {0};
        int sizeOfV;

    public:
        Graph() {
            sizeOfV = -1;
        }

        void addVertex(char v) {
            sizeOfV++;
            vert[sizeOfV] = v;
            return;
        }

        void addUndirectedWeightedEdge(char src, char dest, int weight) {
            int srcIndex = getIndex(src);
            int destIndex = getIndex(dest);
            if(srcIndex == -1 || destIndex == -1) {
                cout<<"Invalid vertices"<<endl;
                return;
            }
            edges[srcIndex][destIndex] = weight;
            edges[destIndex][srcIndex] = weight;
            return;
        }

        int getIndex(int v) {
            for(int i = 0; i <= sizeOfV; i++) {
                if(vert[i] == v) {
                    return i;
                }
            }
            return -1;
        }

        void printMatrix() {
            for(int i = 0; i<= sizeOfV; i++) {
                cout<<i<<"-"<<vert[i]<<", ";
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

        int* extractMin(bool selected[]) {
            int min = INF;
            int treeNode;
            int noTreeNode;
            for(int i = 0; i <= sizeOfV; i++) {
                if(selected[i]) {
                    for(int j = 0; j <= sizeOfV; j++) {
                        if(!selected[j] && edges[i][j] != 0) {
                            if(min > edges[i][j]) {
                                min = edges[i][j];
                                treeNode = i;
                                noTreeNode = j;
                            }
                        }
                    }
                }
            }

            int* result = new int[3];
            result[0] = treeNode;
            result[1] = noTreeNode;
            result[2] = min;

            return result;
        }

        // void prims(int root = 0) {
        //     queue <int> q;
        //     int key[sizeOfV - 1];
        //     int pi[sizeOfV - 1];

        //     for(int i = 0; i <= sizeOfV; i++) {
        //         if(i != root) {
        //             q.push(i);
        //             key[i] = INF;
        //         }
        //     }
        //     bool alreadySelected[sizeOfV-1] = {false};

        //     key[root] = 0;
        //     pi[root] = -1;
        //     alreadySelected[root] = true;

        //     // for(int i = 0; i <= sizeOfV; i++) {
        //     //     cout<<alreadySelected[i]<<endl;
        //     // }
        //     while(!q.empty()) {
        //         // int *result = extractMin(alreadySelected);
        //         // cout<<"Size: "<<q.size()<<endl;
        //         int min = INF;
        //         int treeNode;
        //         int noTreeNode;
        //         for(int i = 0; i <= sizeOfV; i++) {
        //             if(alreadySelected[i]) {
        //                 for(int j = 0; j <= sizeOfV; j++) {
        //                     if(!alreadySelected[j] && edges[i][j] != 0) {
        //                         if(min > edges[i][j]) {
        //                             min = edges[i][j];
        //                             treeNode = i;
        //                             noTreeNode = j;
        //                         }
        //                     }
        //                 }
        //             }
        //         }
        //         int u = noTreeNode;
        //         alreadySelected[u] = true;
        //         q.pop();
        //         for(int v = 0; v <= sizeOfV; v++) {
        //             if(edges[u][v] != 0 && (!alreadySelected[v]) && edges[u][v] < key[v]) {
        //                 pi[v] = u;
        //                 key[v] = edges[u][v];
        //                 cout<<"From: "<<vert[u]<<"to: "<<vert[v]<<"Cost:"<< edges[u][v]<<endl;
        //             }
        //         }
        //     }

        //     int score = 0;
        //     for(int i = 0; i <= sizeOfV; i++) {
        //         cout<<"key:"<<i<<":"<<key[i]<<endl;
        //         score += key[i];
        //     }
        //     // cout<<score<<endl;
        // }

        void primsEdited(int root = 0) {
            vector <int> tree;
            tree.push_back(root);
            vector <int> key;
            bool selected[sizeOfV+1] = {false};
            selected[root] = true;
            while(tree.size() != sizeOfV+1) {
                int min = INF;
                int u;
                int v;
                for(int i = 0; i <= sizeOfV; i++) {
                    if(selected[i]) {
                        for (int j = 0; j <= sizeOfV; j++) {
                            if((!selected[j]) && edges[i][j] != 0) {
                                if(min > edges[i][j]) {
                                    min = edges[i][j];
                                    u = i;
                                    v = j;
                                }
                            }
                        }
                    }
                }
                tree.push_back(v);
                selected[v] = true;
                key.push_back(min);
            }
            cout<<tree.size()<<endl;
            cout<<accumulate(key.begin(),key.end(), 0);
        }
};

int main() {
    Graph gp;
    gp.addVertex(1);
    gp.addVertex(2);
    gp.addVertex(3);
    gp.addVertex(4);
    gp.addVertex(5);
    gp.addVertex(6);
    gp.addVertex(7);
    gp.addVertex(8);

    gp.addUndirectedWeightedEdge(1, 3, 47);
    gp.addUndirectedWeightedEdge(3, 2, 55);
    gp.addUndirectedWeightedEdge(2, 8, 79);
    gp.addUndirectedWeightedEdge(1, 6, 54);
    gp.addUndirectedWeightedEdge(6, 4, 74);
    gp.addUndirectedWeightedEdge(4, 8, 29);
    gp.addUndirectedWeightedEdge(6, 3, 75);
    gp.addUndirectedWeightedEdge(4, 2, 31);
    gp.addUndirectedWeightedEdge(3, 4, 88);
    gp.addUndirectedWeightedEdge(1, 5, 80);
    gp.addUndirectedWeightedEdge(5, 7, 93);
    gp.addUndirectedWeightedEdge(7, 8, 68);
    gp.addUndirectedWeightedEdge(5, 3, 23);
    gp.addUndirectedWeightedEdge(7, 2, 74);
    gp.addUndirectedWeightedEdge(5, 2, 32);
    gp.addUndirectedWeightedEdge(3, 7, 66);

    // gp.printMatrix();
    gp.primsEdited();
}