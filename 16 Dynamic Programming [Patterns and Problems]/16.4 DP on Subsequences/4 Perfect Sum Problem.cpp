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
class Solution{
    int mod=1e9+7;
	public:
	int solRec(int i,int sum,int n,int *arr){
	    if(sum==0){
	        return 1;
	    }
	    if(i==n-1){
	        if(sum==arr[i])return 1;
	        return 0;
	    }
	    int notpick=solRec(i+1,sum,n,arr);
	    int pick=0;
	    if(arr[i]<=sum){
	        pick=solRec(i+1,sum-arr[i],n,arr);
	    }
	    
	    return pick+notpick;
	}
	
	int solDp(int i,int sum,int n,int *arr,vector<vector<int>>&dp){
	    if(sum==0){
	        return 1;
	    }
	    if(i==n-1){
	        if(sum==arr[i])return 1;
	        return 0;
	    }
	    if(dp[i][sum]!=-1)return dp[i][sum]%mod;
	    int notpick=solDp(i+1,sum,n,arr,dp)%mod;
	    int pick=0;
	    if(arr[i]<=sum){
	        pick=solDp(i+1,sum-arr[i],n,arr,dp)%mod;
	    }
	    
	    return dp[i][sum]=(pick+notpick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    sort(arr,arr+n);
	   // return solRec(0,sum,n,arr);
	   vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	   return solDp(0,sum,n,arr,dp);
    //     // Your code goes here
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