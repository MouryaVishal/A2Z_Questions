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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto&a:flights){
            adj[a[0]].push_back({a[1],a[2]});
        }
        vector<int> dis(n,1e9);
        set<pair<int,pair<int,int>>> q;
        q.insert({0,{0,src}});
        dis[src]=0;
        while(!q.empty()){
            auto a=*(q.begin());
            q.erase(q.begin());
            if(a.first>k)continue;
            for(auto&ng:adj[a.second.second]){
                if(ng.second+a.second.first<dis[ng.first] ){
                    dis[ng.first]=ng.second+a.second.first;
                    q.insert({a.first+1,{dis[ng.first],ng.first}});
                }
            }
        }

        return dis[dst]!=1e9?dis[dst]:-1;
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