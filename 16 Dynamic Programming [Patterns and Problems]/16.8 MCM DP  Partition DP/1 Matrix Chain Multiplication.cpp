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
    int solRec(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e9;
        for(int k=i;k<j;k++){
            int curr=arr[i-1]*arr[k]*arr[j]+solRec(i,k,arr,dp)+solRec(k+1,j,arr,dp);
            ans=min(curr,ans);
        }
        return dp[i][j]=ans;
    }
    int solMemo(int n,int arr[]){
        vector<vector<int>> dp(n+6,vector<int>(n+2,0));
        
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int ans=1e9;
                for(int k=i;k<j;k++){
                    int curr=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    ans=min(curr,ans);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
    }
public:
    int matrixMultiplication(int n, int arr[])
    {
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        
        // return solRec(1,n-1,arr,dp);
        
        return solMemo(n,arr);
        // code here
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