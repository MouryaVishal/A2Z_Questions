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
	bool topoSort(int v, vector<int> adj[]) 
	{
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
	   
	   int count;
	   while(!q.empty()){
	      auto a=q.front();
	      q.pop();
	      count++;
	      for(auto&ng:adj[a]){
	          indegree[ng]--;
	          if(indegree[ng]==0){
	              q.push(ng);
	          }
	      }
	   }
	   return count==v;
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