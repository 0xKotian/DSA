/*
Topological Sort is a way of arranging vertices in a Directed Acyclic Graph (DAG) so that for every directed edge a → b, a comes 
before b.

logic -> iterate every number in ascending order, check if they are not visited, if not visited then send that number to the dfs 
function. in dfs function mark the current node as visited and iterate to their neighbours, if the neighbour node is not visited 
then run dfs code for it as current node. push the current node to stack and pop out the top elements that is the toplogical sort   
*/
#include<bits/stdc++.h>
using namespace std;

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
    
    void dfs(int current,vector<bool> &vis,stack<int> &s){
        vis[current] = true;
        for(int i : l[current]){
            if(!vis[i]){
                dfs(i,vis,s);
            }
        }
        s.push(current);
    }

    void topoSort(){
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(vis[i] == false){
                dfs(i,vis,s);
            }
        }
        while(s.size() > 0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
/*
topological sort using khan's algorithem uses bfs. for ever node calculate the indegree i.e the incoming edge, then push 
the node val in q that has indegree 0, in while loop perform bfs currnt will be q.front then pop it out and pushback to res, 
for every current node that is added to res and poped out from q decrease their neighbour's indegree count, 
when their neighbours indegree count decreases to 0 push them to q. finally display res
*/
    void topoSortKhanAlgo(){
        vector<int> res;
        queue<int> q;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int neighbour : l[i]){ // if there is a neighbour of i then increase the inorder of that neighbour
                indegree[neighbour]++;
            }
        }
        // push val in q whose indegree is 0
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(q.size() > 0){ 
            int current = q.front();
            q.pop();
            res.push_back(current);
            for(int neighbour : l[current]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        for(int val : res){
            cout<<val<<" ";
        }
        cout<<endl;
    }
};

int main(){
    DirectedGraph g(6);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    cout<<"topological sort using dfs : ";
    g.topoSort();
    cout<<"topological sort using khan's algorithem (bfs) : ";
    g.topoSortKhanAlgo();
}