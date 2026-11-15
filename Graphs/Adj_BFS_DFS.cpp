/* this code is applicable for graphs with ordered vertices starting from 0 */
#include<bits/stdc++.h>
using namespace std;

class Graph{
private: 
    int V; // total number of vertices in the graph
    list<int> *l;
public :
    Graph(int V){ // this->V refer to the V defined inside the private section of class and RHS V is the value from the object
        this->V = V;
        l = new list<int> [V]; // creates an array of list with V number of list . [] refers to array
    }

    void addEdge(int a, int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void printneighbour(){
        for(int i=0;i<V;i++){
            cout<<i <<":";
            for(int neighbour : l[i]){
                cout<<neighbour<<" "; 
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> visited(V,false); // creates vector of V size and false value stored in it initially 
        q.push(0); // push the source vertex/start vertex
        visited[0] = true; // change its status to true
        while(q.size() > 0){
            int a = q.front();
            q.pop();
            cout<<a<<" ";
            for(int b : l[a]){
                if(visited[b] == false){ // b is the neighbour of a, if its visited status is false then make it as true and push to q 
                    visited[b] = true;
                    q.push(b); 
                }
            }
        }
        cout<<endl;
    }

    void dfsHelper(int a ,vector<bool> &visited){
        cout<<a<<" ";
        visited[a] = true;
        for(int b : l[a]){ // b is the neighbour of a, so print b and check if b has another neighbour, if yes then print that neighbour 
            if(visited[b] == false){
                dfsHelper(b,visited);
            }
        }
    }

    void dfs(){
        int source_vertex = 0; // starting vertex is considered as 0
        vector<bool> visited(V,false); // visited vector is created with false as initial value 
        dfsHelper(source_vertex,visited);
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    cout<<"neighbours"<<endl;
    g.printneighbour();
    cout<<"bfs"<<endl;
    g.bfs(); 
    cout<<"dfs"<<endl;
    g.dfs();
}
