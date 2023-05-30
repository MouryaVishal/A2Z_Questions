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
    bool possible(int i,int j,vector<vector<int>>& b,vector<vector<bool>>& vis){
        return i>=0 && j>=0 && j<b[0].size() && i<b.size() && !vis[i][j] && b[i][j]==1;
    }
    void dfs(int i,int j,vector<vector<int>>& b,vector<vector<bool>>& vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(possible(nx,ny,b,vis)){
                dfs(nx,ny,b,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1) || j==0 || j==m-1){
                    if(b[i][j]==1 && !vis[i][j]){
                        dfs(i,j,b,vis);
                    }
                }
            }
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(b[i][j]==1 && !vis[i][j]) count++;
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