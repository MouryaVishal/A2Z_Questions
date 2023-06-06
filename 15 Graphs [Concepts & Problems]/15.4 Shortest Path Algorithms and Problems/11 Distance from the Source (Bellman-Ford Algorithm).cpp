#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node{
   int data;
   Node* left, * right;
};
#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int s) {
        vector<int>dist(v,1e8);
        dist[s]=0;
        for(int i=0;i<v;i++){
            for(auto&a:edges){
                int u=a[0];
                int v=a[1];
                int w=a[2];
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        for(auto&a:edges){
            int u=a[0];
            int v=a[1];
            int w=a[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                return {-1};
            }
        }
        
        return dist;
    
    }
};


int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}