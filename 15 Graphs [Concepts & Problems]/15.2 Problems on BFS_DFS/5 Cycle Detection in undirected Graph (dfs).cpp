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
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<bool>&vis,vector<int>adj[]){
        vis[node]=true;
        for(auto&a:adj[node]){
            if(!vis[a]){
                bool temp=dfs(a,node,vis,adj);
                if(temp)return true;
            }else if(parent!=a){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                bool temp=dfs(i,-1,vis,adj);
                if(temp)return true;
            }
        }
        return false;
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