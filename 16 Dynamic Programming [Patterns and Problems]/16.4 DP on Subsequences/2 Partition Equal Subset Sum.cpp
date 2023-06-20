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
    bool solRec(int i,int sum,vector<int>&arr){
        if(sum==0)return true;
        if(i==arr.size()-1){
            return sum==arr[i];
        }

        int notpick=solRec(i+1,sum,arr);
        int pick=false;
        if(arr[i]<=sum){
            pick=solRec(i+1,sum-arr[i],arr);
        }

        return pick||notpick;
    }

    bool solDp(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i==arr.size()-1){
            return sum==arr[i];
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int notpick=solDp(i+1,sum,arr,dp);
        int pick=false;
        if(arr[i]<=sum){
            pick=solDp(i+1,sum-arr[i],arr,dp);
        }

        return dp[i][sum]=pick||notpick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        // return solRec(0,sum/2,nums);
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        return solDp(0,sum/2,nums,dp);
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