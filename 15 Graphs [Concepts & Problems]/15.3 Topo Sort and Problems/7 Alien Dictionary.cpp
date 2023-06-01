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

class Solution{
    vector<int> findTopologicalSort(int n,vector<int>adj[]){
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto&a:adj[i]){
                indegree[a]++;
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
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        for(int i=0;i<n-1;i++){
            string s=dict[i];
            string s2=dict[i+1];
            int len=min(s.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s[j]!=s2[j]){
                    adj[s[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo=findTopologicalSort(k,adj);
        string ans="";
        for(auto&a:topo){
            ans+=(a+'a');
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