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
    bool dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        vis[node]+=2;
        for(auto&a:adj[node]){
            if(!vis[a]) {
                bool temp=dfs(a,adj,vis);
                if(temp)return true;
            }
            else if(vis[a]==2){
                return true;
            }
        }
        vis[node]--;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> adj;
        for(auto&a:p){
            adj[a[0]].push_back(a[1]);
        }

        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bool temp=dfs(i,adj,vis);
                if(temp)return false;
            }
        }
        return true; 
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