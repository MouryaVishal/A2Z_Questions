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
class SolutionBFS {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int v=g.size();
        vector<bool> vis(v,false);
        vector<int> color(v,-1);
        queue<int> q;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                color[i]=1;
                while(!q.empty()){
                    auto a=q.front();
                    q.pop();
                    int c=color[a];
                    for(auto&ng:g[a]){
                        if(vis[ng]){
                            if(color[ng]==c)return false;
                        }else{
                            color[ng]=!c;
                            vis[ng]=true;
                            q.push(ng);
                        }
                    }
                }
            }
        }

        return true;
    }
};

class Solution {
    bool dfs(int node,int par,vector<bool>&vis,vector<vector<int>>& g,vector<int>&color){
        vis[node]=1;
        int c=color[node];
        for(auto&ng:g[node]){
            if(vis[ng]){
                if(color[ng]==c)return false;
            }else{
                color[ng]=!c;
                bool temp=dfs(ng,node,vis,g,color);
                if(!temp)return temp;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& g) {
        int v=g.size();
        vector<bool> vis(v,false);
        vector<int> color(v,-1);
        queue<int> q;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                color[i]=0;
                bool temp=dfs(i,-1,vis,g,color);
                if(!temp) return temp;
            }
        }
        return true;
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