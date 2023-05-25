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
    int func(int i,vector<int>&nums,int k,vector<vector<int>>&dp){
        if(k==0 && i==nums.size()){
            return 0;
        }
        if(k==0 || i==nums.size()){
            return 1e9;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=1e9;
        int leftSum=0;
        for(int ind=i;ind<nums.size();ind++){
            leftSum+=nums[ind];
            int nextSum=func(ind+1,nums,k-1,dp);
            ans=min(ans,max(leftSum,nextSum));
        }

        return dp[i][k]=ans;

    }
public:
    int splitArray(vector<int>& nums, int k) {
        // vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
        // return func(0,nums,k,dp);

        int st=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        while(st<=end){
            int mid=st+(end-st)/2;
            int count=0;
            int currSum=0;
            for(int i=0;i<nums.size();i++){
                if(currSum+nums[i]<=mid){
                    currSum+=nums[i];
                }else{
                    count++;
                    currSum=nums[i];
                }
            }
            count++;
            if(count<=k){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;


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