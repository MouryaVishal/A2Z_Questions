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
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> adj;
        for(auto&a:p){
            adj[a[0]].push_back(a[1]);
        }

        vector<int> indegree(n,0);
        for(auto&a:adj){
            for(auto&b:a.second){
                indegree[b]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            for(auto&ng:adj[a]){
                indegree[ng]--;
                if(indegree[ng]==0){
                    q.push(ng);
                }
            }
        }
        if(ans.size()!=n )return {};
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