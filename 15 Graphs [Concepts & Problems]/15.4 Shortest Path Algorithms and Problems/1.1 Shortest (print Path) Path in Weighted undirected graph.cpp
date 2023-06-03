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
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> dis(n+1,1e9);
        vector<int> parent(n+1);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto&a:edges){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dis[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
        q.push({0,1});
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            int node=a.second;
            int currDis=a.first;
            for(auto&ng:adj[node]){
                if(ng.second+currDis<dis[ng.first]){
                    parent[ng.first]=node;
                    dis[ng.first]=ng.second+currDis;
                    q.push({dis[ng.first],ng.first});
                }
            }
        }
        
        vector<int> ans;
        if(n==parent[n]) return {-1};
        int node=n;
        while(node!=parent[node]){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(node);
        reverse(ans.begin(),ans.end());
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