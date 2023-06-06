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

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto&a:roads){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        set<pair<int,int>> st;
        st.insert({0,0});
        vector<long long> dis(n,LLONG_MAX);
        vector<int> ways(n,0);
        ways[0]=1;
        dis[0]=0;
        int mod=1e9+7;
        
        while(!st.empty()){
            auto a=*(st.begin());
            st.erase(st.begin());
            int currNode=a.second;
            long long currDis=a.first;
            for(auto&ng:adj[currNode]){
                if(ng.second+currDis<dis[ng.first]){
                    dis[ng.first]=(long long)ng.second+currDis;
                    st.insert({dis[ng.first],ng.first});
                    ways[ng.first]=(ways[currNode])%mod;
                }else if((long long)ng.second+currDis==dis[ng.first]){
                    ways[ng.first]=(ways[ng.first]+ways[currNode]+mod)%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
        
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