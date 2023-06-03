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
    void dfs(int node,vector<int>&vis,unordered_map<int,vector<pair<int,int>>>&adj,stack<int>&st){
        vis[node]=1;
        for(auto&ng:adj[node]){
            if(!vis[ng.first]){
                dfs(ng.first,vis,adj,st);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        stack<int> st;
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> vis(n,0);
        
        for(auto&a:edges){
            adj[a[0]].push_back({a[1],a[2]});
        }
        
        dfs(0,vis,adj,st);
        
        vector<int> dis(n,1e9);
        dis[0]=0;
        while(!st.empty()){
            int a=st.top();
            st.pop();
            for(auto&ng:adj[a]){
                if(dis[a]+ng.second<dis[ng.first]){
                    dis[ng.first]=dis[a]+ng.second;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        
        return dis;
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