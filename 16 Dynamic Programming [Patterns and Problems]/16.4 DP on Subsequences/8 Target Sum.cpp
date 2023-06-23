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
    int ans=0;
    int solRec(int i,int curr,int tr,vector<int>&nums ){
        if(i==nums.size()){
            if(curr==tr){
                return 1;
            }
            return 0;
        }
        int mis=solRec(i+1,curr-1*nums[i],tr,nums);
        int plus=solRec(i+1,curr+1*nums[i],tr,nums);
        return mis+plus;
    }

    int solDp(int i,int curr,int tr,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(curr==tr){
                return 1;
            }
            return 0;
        }
        if(dp[i][curr+1000]!=-1)return dp[i][curr+1000];
        int mis=solDp(i+1,curr-1*nums[i],tr,nums,dp);
        int plus=solDp(i+1,curr+1*nums[i],tr,nums,dp);
        return dp[i][curr+1000]=mis+plus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int tr) {
        // return solRec(0,0,tr,nums);
        vector<vector<int>> dp(nums.size()+1,vector<int>(2001,-1));
        return solDp(0,0,tr,nums,dp);

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