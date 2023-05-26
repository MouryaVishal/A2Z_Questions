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
    void dfs(int node,vector<bool>&vis,vector<int>*adj){
        vis[node]=1;
        for(auto&a:adj[node]){
            if(!vis[a]){
                dfs(a,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& c) {
        int v=c.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(c[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
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