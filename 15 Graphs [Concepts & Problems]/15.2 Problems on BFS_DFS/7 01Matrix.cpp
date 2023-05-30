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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<bool>> vis(mat.size(),vector<bool>(mat[0].size(),0));
        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,{j,0}});
                    vis[i][j]=1;
                }
            }
        }

        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.first;
            int y=a.second.first;
            int c=a.second.second;
            ans[x][y]=c;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<mat.size() && ny<mat[0].size() && !vis[nx][ny]){
                    q.push({nx,{ny,c+1}});
                    vis[nx][ny]=true;
                }
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