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
class Solution
{
	public:
	void dfs(int node,vector<bool>&vis,stack<int>&st,vector<int> adj[]){
	    vis[node]=true;
	    for(auto&a:adj[node]){
	        if(!vis[a])dfs(a,vis,st,adj);
	    }
	    st.push(node);
	} 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // stack<int> st;
	    // vector<bool> vis(v,0);
	    // for(int i=0;i<v;i++){
	    //     if(!vis[i]){
	    //         dfs(i,vis,st,adj);
	    //     }
	    // }
	    // vector<int> ans;
	    // while(!st.empty()){
	    //     ans.push_back(st.top());
	    //     st.pop();
	    // }
	    
	    // return ans;
	   
	   
	   vector<int> indegree(v,0);
	   for(int i=0; i<v; i++){
	      for(int j=0;j<adj[i].size();j++){
	          indegree[adj[i][j]]++;
	      }
	   }
	   queue<int> q;
	   for(int i=0;i<v;i++){
	      if(indegree[i]==0)q.push(i);
	   }
	   
	   vector<int> ans;
	   while(!q.empty()){
	      auto a=q.front();
	      q.pop();
	      ans.push_back(a);
	      for(auto&ng:adj[a]){
	          indegree[ng]--;
	          if(indegree[ng]==0){
	              q.push(ng);
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