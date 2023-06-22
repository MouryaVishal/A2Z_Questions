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
    int mod=(int)1e9+7;
    int solRec(int i,vector<int>&arr,int sum){
        if(i==arr.size()-1){
            if(sum==0 && arr[i]==sum){
                return 2;
            }
            if(sum==0 || arr[i]==sum)return 1;
            return 0;
        }
        if(sum==0)return 1;
        int np=solRec(i+1,arr,sum);
        int p=0;
        if(arr[i]<=sum)
        p=solRec(i+1,arr,sum-arr[i]);
        return np+p;
    }
    
    int solDp(int i,vector<int>&arr,int sum,vector<vector<int>>&dp){
        if(i==arr.size()-1){
            if(sum==0 && arr[i]==0){
                return 2;
            }
            if(sum==0 || arr[i]==sum)return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        int np=solDp(i+1,arr,sum,dp);
        int p=0;
        if(arr[i]<=sum)
            p=solDp(i+1,arr,sum-arr[i],dp);
        return dp[i][sum]=(np+p)%mod;
    }
    
    int solTab(vector<int>&arr,int &s){
        vector<vector<int>>dp(arr.size()+1,vector<int>(s+1,0));
        int n=arr.size();
        
        if(arr[n-1]==0){
            dp[n-1][0]=2;
        }else{
            dp[n-1][0]=1;
        }
        
        if(arr[n-1]!=0 && arr[n-1]<=s){
            dp[n-1][arr[n-1]]=1;
        }
        
        for(int i=n-2;i>=0;i--){
            for(int sum=0;sum<=s;sum++){
                int np=dp[i+1][sum];
                int p=0;
                if(arr[i]<=sum)
                    p=dp[i+1][sum-arr[i]];
                dp[i][sum]=(np+p)%mod;
            }
        }
        
        return dp[0][s];
        
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if((sum-d)<0 || (sum-d)%2)return 0;
        int req=(sum-d)/2;
        // return solRec(0,arr,req);
        
        // vector<vector<int>> dp(n+1,vector<int>(req+8,-1));
        // return solDp(0,arr,req,dp);
        
        return solTab(arr,req);
        
        
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