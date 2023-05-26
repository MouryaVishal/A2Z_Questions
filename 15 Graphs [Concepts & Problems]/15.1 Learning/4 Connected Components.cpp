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
    
    void dfs(int i,vector<int>&vis, vector<int>adjlst[]){
        vis[i]=1;
        for(auto&a:adjlst[i]){
            if(vis[a]==0){
                dfs(a,vis,adjlst);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        vector<int> adjlst[v+1];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1&& j!=i){
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(v+1,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                dfs(i,vis,adjlst);
                count++;
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