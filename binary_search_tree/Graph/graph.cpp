#include<iostream>
#include<vector>
using namespace std;

class bfsNode{
    public:
    int data;
    char color;
    int dist;
    bfsNode* parent;
    bfsNode(int d){
        data = d;
        color = 'w';
        dist = INT_MAX;
        parent = NULL;
        }
};

class dfsNode{
    public:
    char color;
    int dist;
    int finDist;
    dfsNode* parent;
    dfsNode(){
        color = 'w'; 
        parent = NULL;
    }
};

class Graph{
    public:
    int noOfNode;
    int noOfEdge;
    vector<vector<bfsNode>> adj(int noOfNode, vector<bfsNode>(int noOfNode));
    Graph(int Node, int Edge){
        noOfEdge = Edge;
        noOfNode = Node;
    }
    void InsertData(){
        int data1, data2;
        vector<int> arr(noOfNode);
        cout<<"Enter node connected by edges"<<endl;
        for(int i=0; i<noOfEdge; i++){
            cin>>data1>>data2;

            bfsNode* n1 = new bfsNode(data1);
            bfsNode* n2 = new bfsNode(data2);
            adj[n1].push_back(n2);
            }
    }
};