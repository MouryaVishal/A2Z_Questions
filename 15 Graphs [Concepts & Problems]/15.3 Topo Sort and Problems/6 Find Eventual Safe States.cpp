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
    void dfs(int i,vector<int>&vis,unordered_map<int,vector<int>>&adj,vector<int>&vec,bool &flag){
        vis[i]+=2;
        for(auto&a:adj[i]){
            if(!vis[a]){
                dfs(a,vis,adj,vec,flag);
            }else if(vis[a]==2){
                vec[a]=1;
            }
            if(vec[a]==1){
                vec[i]=1;
            }
        }
        vis[i]--;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        unordered_map<int,vector<int>> adj;
        int n=g.size();
        for(int i=0;i<g.size();i++){
            for(auto&a:g[i])
                adj[i].push_back(a);
        }
        vector<int> vis(n,0);
        vector<int>vec(n,0);
        bool flag=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,vec,flag);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++ ){
            if(vec[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
        
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