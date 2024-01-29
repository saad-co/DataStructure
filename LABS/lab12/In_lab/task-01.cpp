#include<iostream>
using namespace std;
class GraphNode {
public:
    int vertex;
    int weight;
 GraphNode * next;
    GraphNode() {
       vertex = 0;
       weight = 0;
       next = nullptr;
 }
};
class Graph{
    int max;
    GraphNode** headnodes;
    int n;
    int * visited;

    Graph(){
        max=0;
        n=0;
        headnodes=new GraphNode*[max];
        visited=new int[max];
    }
    Graph(int m){
        max=m;
        headnodes=new GraphNode*[max];
        visited=new int[max];
        initialize_visit();

    }
    ~Graph(){
        GraphNode** temp=headnodes;
        for(int i=0;i<max;i++){
            GraphNode* current=headnodes[i];
            current=current->next;
            delete temp;
        }
        delete[] headnodes;
        delete[] visited;
    }
    void initialize_visit(){
        for(int i=0;i<max;i++){
            visited[i]=0;
        }
    }
    void addVertex(int v){
        if(v>=0 && v<max){
            GraphNode* curr=curr->next;
        }
        else{
            throw invalid_argument("Invalid Vertex");
        }
    }
    void removevertex(int v){
        if(v>=0 && v<max){

        }
        else{
            throw invalid_argument("invalid vertex");
        }
    }
    void addEdge(int u,int v){
        if(u>=0 && u<max && v>=0 && v<max){

        }
        else{
            throw invalid_argument("Invalid vertex.");
            
        }
    }
    bool vertexExist(int v){
         for(int i=0;max;i++){
            for(int j=0;j<max;j++){
                if(headnodes[i][j]==1){
                    return true;
                }
            }
         }
         return false;
    }
    int examine(){
        return n;
    }
    int getweight(int v1,int v2){
        if(v1>=0 && v1<max && v2>=0 && v2<max){
            
        }
        else{
            throw invalid_argument("Invalid Vertices.");
        }
    }
    void printGraph(){
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                cout<<headnodes[i][j]<<" ";
            }
        }
    }
};