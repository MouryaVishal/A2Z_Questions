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
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    bool possible(int i,int j,vector<vector<char>>& b,vector<vector<bool>>& vis){
        return i>=0 && j>=0 && j<b[0].size() && i<b.size() && !vis[i][j] && b[i][j]=='O';
    }
    void dfs(int i,int j,vector<vector<char>>& b,vector<vector<bool>>& vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(possible(nx,ny,b,vis)){
                dfs(nx,ny,b,vis);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1) || j==0 || j==m-1){
                    if(b[i][j]=='O' && !vis[i][j]){
                        dfs(i,j,b,vis);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && b[i][j]=='O') b[i][j]='X';
            }
        }
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