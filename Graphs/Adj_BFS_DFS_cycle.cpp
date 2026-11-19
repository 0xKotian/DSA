/* this code is applicable for graphs with ordered vertices starting from 0 */
#include<bits/stdc++.h>
using namespace std;

class UndirectedGraph{
private: 
    int V; // total number of vertices in the graph
    list<int> *l;
public :
    UndirectedGraph(int V){ // this->V refer to the V defined inside the private section of class and RHS V is the value from the object
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

    bool iscycleBFS(int src,vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;
        while(q.size() > 0){
            int a = q.front().first;
            int parent = q.front().second;
            q.pop();
            list<int> neighbours = l[a];
            for(int b : neighbours){
                if(!vis[b]){
                    q.push({b,a});
                    vis[b] = true;
                } 
                else if(b != parent){
                    return true;
                }
            }
        }
        return false ;
    }

    bool iscycleDFS(int src, int parent, vector<bool> &vis){ 
        vis[src] = true; // mark visited to the src vertex
        list<int> neighbours = l[src]; // take the neighbours of src  
        for(int v : neighbours){
            if(!vis[v]){ // check if the neighbour is not visited then perform DFS with src as the parent vertex
                if(iscycleDFS(v,src,vis) == true){
                    return true;
                }
            }
            else if(v != parent){ // if the neighbour is visited and the neighbour is not its parent node then it has loop connection
                return true;
            }
        }
        return false;
    }

    bool iscycle(){ // when we iterate in graph from a vertex to b vertex then for b a is the parent node 
        int ch;
        cout<<"enter choice\n1.using BFS\n2.using DFS"<<endl;
        cin>>ch;
        
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(ch == 1){
                    if(iscycleDFS(i,-1,vis) == true){ 
                    return true;
                }
                }
                else if(ch == 2){
                    if(iscycleDFS(i,-1,vis) == true){ // initially the parent node will be -1
                    return true;
                    }
                }
            }
        }
        return false;
    }
};

class DirectedGraph{
    int V; // total number of vertices in the graph
    list<int> *l;
public :
    DirectedGraph(int V){ // this->V refer to the V defined inside the private section of class and RHS V is the value from the object
        this->V = V;
        l = new list<int> [V]; // creates an array of list with V number of list . [] refers to array
    }

    void addEdge(int a, int b){
        l[a].push_back(b); // a-->b means b is stored as neighbour of a, but a is not stored as neighbour of b in directed graph
    }

    bool iscycleDFS(int current, vector<bool> &vis, vector<bool> &reccursionPath){ // checks for every neighbour marking it true in both vis and reccursioPath, when the neighbour is already visited then check if its there in reccursionPth, if yes then there is a loop detected. 
        vis[current] = true;
        reccursionPath[current] = true;
        for(int neighbour : l[current]){
            if(vis[neighbour] == false){
                if(iscycleDFS(neighbour,vis,reccursionPath) == true){
                    return true;
                }
            }
            else if(reccursionPath[current] == true){
                return true;
            }
        }
        reccursionPath[current] = false;
        return false;
    }

    bool iscycle(){
        vector<bool> vis(V,false);
        vector<bool> reccursionPath(V,false);

        for(int i=0;i<V;i++){
            if(vis[i] == false){
                if(iscycleDFS(i,vis,reccursionPath) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    UndirectedGraph g(5);
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

    UndirectedGraph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,0);
    g1.addEdge(0,3);
    g1.addEdge(3,4);
    cout<<"check for loop"<<endl;
    cout<<g1.iscycle()<<" [ 1 means loop detected and 0 means loop not detected ]"<<endl;

    DirectedGraph g2(4);
    g2.addEdge(1,0);
    g2.addEdge(0,2);
    g2.addEdge(2,3);
    g2.addEdge(3,0);
    cout<<g2.iscycle()<<" [ 1 means loop detected and 0 means loop not detected ]"<<endl;
}
