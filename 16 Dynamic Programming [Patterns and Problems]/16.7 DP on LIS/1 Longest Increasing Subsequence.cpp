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
    Node* prev;
    int data;
    Node* next;
    Node()
    { 
    prev = NULL;
    data = 0;
    next = NULL;
    }
    
    Node(int value)
    {
    prev = NULL;
    data = value;
    next = NULL;
    }
  };
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)


// !Solution 
class Solution {
    int solRec(int i,int pr,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size()-1){
            if(pr==-1 || nums[pr]<nums[i])return 1;
            return 0;
        }
        if(dp[i][pr+1]!=-1)return dp[i][pr+1];
        int notpick=solRec(i+1,pr,nums,dp);
        int pick=0;
        if(pr==-1|| nums[pr]<nums[i]){
            pick=1+solRec(i+1,i,nums,dp);
        }
        return dp[i][pr+1]=max(pick,notpick);
    }
    int solTab(vector<int>&nums){
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,0));
        int n=nums.size();
        for(int pr=-1;pr<n-1;pr++){
            if(pr==-1 || nums[pr]<nums[n-1])dp[n-1][pr+1]=1;
        }

        for(int i=n-2;i>=0;i--){
            for(int pr=n-2;pr>=-1;pr--){
                int notpick=dp[i+1][pr+1];
                int pick=0;
                if(pr==-1|| nums[pr]<nums[i]){
                    pick=1+dp[i+1][i+1];
                }
                dp[i][pr+1]=max(pick,notpick);
            }
        }
        return dp[0][0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return solRec(0,-1,nums,dp);

        return solTab(nums);
    }
};

// !Solution 
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}