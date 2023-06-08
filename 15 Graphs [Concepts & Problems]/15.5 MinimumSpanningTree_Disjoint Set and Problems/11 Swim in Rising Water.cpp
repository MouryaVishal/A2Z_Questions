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
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)

class SolutionDFS {
    vector<int> dx={0,0,-1,1};
    vector<int> dy={-1,1,0,0};
    bool isValid(int i,int j,vector<vector<int>>& g,vector<vector<int>>& vis,int mid){
        return i>=0 && j>=0 && i<g.size() && j<g.size() && g[i][j]<=mid && vis[i][j]==0;
    }
    bool dfs(int i,int j,vector<vector<int>>& g,vector<vector<int>>& vis,int mid){
        if(i==g.size()-1 && j==g.size()-1)return true;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            // cout<<nx<<" "<<ny<<endl;
            if(isValid(nx,ny,g,vis,mid)){
                // cout<<"sd"<<" "<<nx<<" "<<ny<<endl;
                bool temp=dfs(nx,ny,g,vis,mid);
                if(temp)return temp;
            }
        }
        return false;

    }
    bool possible(vector<vector<int>>& g,int mid){
        vector<vector<int>> vis(g.size(),vector<int>(g.size(),0));
        // return 0;
        return dfs(0,0,g,vis,mid);
    }
public:
    int swimInWater(vector<vector<int>>& g) {
        int maxi=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                maxi=max(maxi,g[i][j]);
            }
        }
        int st=g[0][0];
        int end=maxi;
        int ans=0;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(g,mid)){
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
    SolutionDFS obj;
}