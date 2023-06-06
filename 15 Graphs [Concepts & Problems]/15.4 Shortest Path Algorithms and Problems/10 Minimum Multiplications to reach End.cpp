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
  int mod=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        set<pair<int,int>> st;
        st.insert({0,start});
        vector<int> vis(1e5+4,0);
        while(!st.empty()){
            auto a=*(st.begin());
            st.erase(st.begin());
            if(a.second==end)return a.first;
            for(auto&ng:arr){
                int newNum=(ng*a.second)%mod;
                if(!vis[newNum]){
                    st.insert({a.first+1,newNum});
                    vis[newNum]=1;
                }
            }
        }
        
        return -1;
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