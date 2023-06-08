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
class disJointSet{
    public:
    vector<int> rank,parent;
    disJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findultimateParent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findultimateParent(parent[x]);
    }

    bool unionByRank(int u,int v){
        int pu=findultimateParent(u);
        int pv=findultimateParent(v);
        if(pu==pv)return true;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
        return false;
    }
};


class Solution {
    bool possible(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disJointSet obj(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        vector<int> ans;
        vector<int> dx={0,0,-1,1};
        vector<int> dy={-1,1,0,0};
        for(auto&a:operators){
            int i=a[0];
            int j=a[1];
            if(vis[i][j]){
                ans.push_back(count);
                continue;
            }
            count++;
            vis[i][j]=1;
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(possible(nx,ny,n,m)){
                    if(vis[nx][ny] && obj.findultimateParent(i*m+j)!=obj.findultimateParent(nx*m+ny)){
                        count--;
                        obj.unionByRank(i*m+j,nx*m+ny);
                    }
                }
            }
            ans.push_back(count);
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