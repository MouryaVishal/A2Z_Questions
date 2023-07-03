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
    int solRec(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            int curr=nums[i-1]*nums[k]*nums[j+1]+solRec(i,k-1,nums,dp)+solRec(k+1,j,nums,dp);
            ans=max(ans,curr);
        }
        return dp[i][j]=ans;
    }
    int solMemo(vector<int>&nums){
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        int n=nums.size();
        for(int i=n-2;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int ans=0;
                for(int k=i;k<=j;k++){
                    int curr=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    ans=max(ans,curr);
                }
                dp[i][j]=ans;
            }
        }

        return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return solRec(1,nums.size()-2,nums,dp);
        return solMemo(nums);
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