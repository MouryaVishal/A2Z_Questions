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

class Solution{
    
    int mod=1e9+7;
	public:
	int func(int i,int &n,int arr[],int sum,vector<vector<int>>&dp){
	    if(i==n){
	        if(sum==0){
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[i][sum]!=-1)return dp[i][sum]%mod;
	    int pick=0;
	    int notpick=func(i+1,n,arr,sum,dp);
	    if(arr[i]<=sum){
	        pick=func(i+1,n,arr,sum-arr[i],dp);
	    }
	    
	    return dp[i][sum]=(pick+notpick)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    return func(0,n,arr,sum,dp);
        // Your code goes here
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