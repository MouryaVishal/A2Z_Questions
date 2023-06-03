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
    bool possible(int i,int j,vector<vector<int>>&g,vector<vector<bool>>&vis){
        return i>=0 && j>=0 && i<g.size() && j<g.size() && !g[i][j] && !vis[i][j];
    }
    int dx[8]={0,0,-1,1,1,1,-1,-1};
    int dy[8]={-1,1,0,0,-1,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        if(g[0][0]==1 || g[n-1][n-1]==1) return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        vis[0][0]=1;

        while(!q.empty()){
            auto a=q.front();
            q.pop();
            if(a.second.first==n-1 && a.second.second==n-1)return a.first;
            for(int i=0;i<8;i++){
                int nx=a.second.first+dx[i];
                int ny=a.second.second+dy[i];
                if(possible(nx,ny,g,vis)){
                    q.push({a.first+1,{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }

        return -1;
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