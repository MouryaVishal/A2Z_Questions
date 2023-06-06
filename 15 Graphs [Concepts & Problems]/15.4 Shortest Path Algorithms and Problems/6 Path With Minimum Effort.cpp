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
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    bool dfs(int i,int j,vector<vector<int>>& h,vector<vector<int>> &vis,int mid){
        if(i==h.size()-1 && j==h[0].size()-1)return true;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && ny>=0 && nx<h.size() && ny<h[0].size() && !vis[nx][ny] && abs(h[i][j]-h[nx][ny])<=mid){
                bool temp=dfs(nx,ny,h,vis,mid);
                if(temp)return temp;
            }
        }
        // vis[i][j]=0;
        return false;
    }
    bool possible(vector<vector<int>>& h,int mid){
        vector<vector<int>> vis(h.size(),vector<int>(h[0].size(),0));
        return dfs(0,0,h,vis,mid);
    }
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int maxi=0;
        int mini=1e6+2;
        int n=h.size();
        int m=h[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,h[i][j]);
                mini=min(mini,h[i][j]);
            }
        }

        int st=0;
        int end=maxi-mini;
        int ans=0;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(h,mid)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
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