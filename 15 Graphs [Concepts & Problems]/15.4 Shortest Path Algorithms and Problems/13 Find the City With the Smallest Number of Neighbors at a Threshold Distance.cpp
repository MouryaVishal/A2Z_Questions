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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> dist(n,1e9);
        vector<pair<int,int>> adj[n];
        for(auto&a:edges){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        int ans=0;
        int count=n;
        set<pair<int,int>> st;
        for(int i=0;i<n;i++){
            st.insert({0,i});
            dist[i]=0;
            int curr=0;
            while(!st.empty()){
                auto a=*(st.begin());
                st.erase(st.begin());
                int currDis=a.first;
                int currNode=a.second;
                for(auto&ng:adj[currNode]){
                    if(ng.second+currDis<dist[ng.first] && ng.second+currDis<=distanceThreshold){
                        if(dist[ng.first]==1e9)curr++;
                        dist[ng.first]=ng.second+currDis;
                        st.insert({dist[ng.first],ng.first});
                    }
                }
            }
            // for(auto&a:dist){
            //     if(a<=distanceThreshold)curr++;
            // }
            // cout<<i<<" "<<curr<<" "<<count<<" "<<ans<<endl;
            if(curr<=count){
                ans=i;
                count=curr;
            }
            fill(begin(dist),end(dist),1e9);
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