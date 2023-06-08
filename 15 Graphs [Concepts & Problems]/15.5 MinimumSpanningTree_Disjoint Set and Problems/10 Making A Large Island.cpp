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
    vector<int> rank,parent,size;
    disJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
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

    bool unionBySize(int u,int v){
        int pu=findultimateParent(u);
        int pv=findultimateParent(v);
        if(pu==pv)return true;

        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv]; 
        }
        return false;
    }
};


class Solution {
    bool possible(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
public:
    int largestIsland(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        disJointSet obj(n*m);
        vector<int> dx={0,0,-1,1};
        vector<int> dy={-1,1,0,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]){
                    vis[i][j]=1;
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(possible(nx,ny,n,m) && g[nx][ny] && !vis[nx][ny]){
                            if(obj.findultimateParent(i*m+j)!=obj.findultimateParent(nx*m+ny)){
                                obj.unionBySize(i*m+j,nx*m+ny);
                                // vis[nx][ny]=1;
                            }
                        }
                    }
                }
            }
        }

        int ans=*max_element(obj.size.begin(),obj.size.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!g[i][j]){
                    int curr=1;
                    unordered_map<int,int> mp;
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(possible(nx,ny,n,m) && g[nx][ny]){
                            int par=obj.findultimateParent(nx*m+ny);
                            if(mp.find(par)==mp.end()){
                                mp[par]++;
                                curr+=obj.size[par];
                            }
                        }
                    }
                    ans=max(ans,curr);
                }
            }
        }
        // for(int i=0;i<obj.size.size();i++){
        //     cout<<obj.size[i]<<" "<<endl;
        // }
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