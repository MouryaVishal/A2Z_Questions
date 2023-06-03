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
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int> dis(n,1e9);
        vector<int> adj[n];
        for(auto&a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        
        queue<int> q;
        q.push(src);
        dis[src]=0;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            for(auto&ng:adj[a]){
                if(dis[a]+1<dis[ng]){
                    dis[ng]=dis[a]+1;
                    q.push(ng);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        
        return dis;
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