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
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]++;
        vis[node]++;
        for(auto&a:adj[node]){
            if(!vis[a]){
                bool temp=dfs(a,vis,adj);
                if(temp)return true;
            }else if(vis[a]==2){
                return true;
            }
        }
        vis[node]--;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]&& dfs(i,vis,adj)){
                return true;
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