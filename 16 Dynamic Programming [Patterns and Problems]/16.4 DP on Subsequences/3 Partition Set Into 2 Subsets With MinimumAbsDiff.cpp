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
    int ans=1e9;
    bool solDp(int i,int n,int arr[], int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(i==n-1){
            return arr[i]==sum;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool notpick=solDp(i+1,n,arr,sum,dp);
        int pick=false;
        if(arr[i]<=sum){
            pick=solDp(i+1,n,arr,sum-arr[i],dp);
        }
        return dp[i][sum]=pick||notpick;
    }
  public:
	int minDifference(int arr[], int n){
	    int s=accumulate(arr,arr+n,0);
	    vector<vector<int>> dp(n,vector<int>(s+1,0));
	    for(int i=0;i<n;i++){
	        dp[i][0]=1;
	    }
	    dp[n-1][arr[n-1]]=1;
	    
	    for(int i=n-2;i>=0;i--){
	        for(int sum=1;sum<=s;sum++){
	            bool notpick=dp[i+1][sum];
                int pick=false;
                if(arr[i]<=sum){
                    pick=dp[i+1][sum-arr[i]];
                }
                dp[i][sum]=pick||notpick;
	        }
	    }
	
	    int ans=1e9;
	    for(int i=0;i<=s/2;i++){
	        if(dp[0][i]){
	            ans=min(ans,abs(i-(s-i)));
	        }
	    }
	    
	    return ans;
	    
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