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
    bool possible(int i,int j,vector<vector<int>>& g,vector<vector<bool>>& vis){
        return i>=0 && j>=0 && j<g[0].size() && i<g.size() && g[i][j]==1 && !vis[i][j];
    }
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void dfs(int i,int j,vector<vector<int>>& g,vector<pair<int,int>>&vec,vector<vector<bool>>& vis,int &bi,int &bj){
        vis[i][j]=true;
        vec.push_back({i-bi,j-bj});
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(possible(nx,ny,g,vis)){
                dfs(nx,ny,g,vec,vis,bi,bj);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i,j,g,vec,vis,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
        
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