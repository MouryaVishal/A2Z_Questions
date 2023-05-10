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

class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        unordered_map<int,int> mp;
        int maxi=0;
        mp[0]=-1;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            int req=curr-k;
            if(mp.find(req)!=mp.end()){
                maxi=max(maxi,i-mp[req]);
            }
            if(mp.find(curr)==mp.end())
                mp[curr]=i;
        }
        
        return maxi;
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