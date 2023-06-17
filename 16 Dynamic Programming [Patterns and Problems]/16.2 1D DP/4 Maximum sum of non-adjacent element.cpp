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
public:	
    int solRec(int i,int *arr,int n){
        if(i>=n)return 0;
        
        int pick=arr[i]+solRec(i+2,arr,n);
        int notpick=solRec(i+1,arr,n);
        return max(pick,notpick);
    }
    
    int solDp(int i,int *arr,int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=arr[i]+solDp(i+2,arr,n,dp);
        int notpick=solDp(i+1,arr,n,dp);
        return dp[i]=max(pick,notpick);
    }
    
    int solMemo(int *arr, int n){
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            int pick=arr[i]+(i+2<n?dp[i+2]:0);
            int notpick=(i+1<n?dp[i+1]:0);
            dp[i]=max(pick,notpick);
        }
        return dp[0];
    }
    
    int solSpaceOpt(int *arr, int n){
        int last=0;
        int prev=0;
        int curr=0;
        for(int i=n-1;i>=0;i--){
            int pick=arr[i]+(i+2<n?last:0);
            int notpick=(i+1<n?prev:0);
            curr=max(pick,notpick);
            last=prev;
            prev=curr;
        }
        return prev;
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   // return solRec(0,arr,n);
	   // vector<int> dp(n,-1);
	   // return solDp(0,arr,n,dp);
	   
	   return solSpaceOpt(arr,n);
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