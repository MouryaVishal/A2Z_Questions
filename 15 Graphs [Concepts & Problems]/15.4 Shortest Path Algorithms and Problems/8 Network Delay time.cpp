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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto &a: times){
            mp[a[0]].push_back({a[1],a[2]});
        }
        vector<int> dis(n+1,1e9);
        set<pair<int,int>> st;
        // dis,node;
        st.insert({0,k});
        dis[k]=0;
        while(st.size()!=0){
            auto b=*st.begin();
            st.erase(st.begin());
            int currN=b.second;
            int currDis=b.first;
            for(auto &ng:mp[currN]){
                int nextNode=ng.first;
                int nodeDis=ng.second;
                if(nodeDis+currDis<dis[nextNode]){
                    dis[nextNode]=nodeDis+currDis;
                    st.insert({dis[nextNode],nextNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<dis.size();i++){
            ans=max(ans,dis[i]);
        }
        return ans==1e9?-1:ans;
    }
};
#define fr(i,num) for(int i=0;i<num;i++)
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