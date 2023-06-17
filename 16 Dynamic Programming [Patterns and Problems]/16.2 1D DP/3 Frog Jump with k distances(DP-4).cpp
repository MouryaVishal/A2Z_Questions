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

class Solution {
    int solRecusion(int ind,vector<int>& h, int n, int k){
        if(ind>=n-1)return 0;
        int ans=1e9;
        for(int i=ind+1;i<=ind+k && i<n;i++){
            ans=min(ans,(abs(h[i]-h[ind])+solRecusion(i,h,n,k)) );
        }
        
        return ans;
    }
    
    int solDp(int ind,vector<int>& h, int n, int k,vector<int>&dp){
        if(ind>=n-1)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=1e9;
        for(int i=ind+1;i<=ind+k && i<n;i++){
            ans=min(ans,(abs(h[i]-h[ind])+solDp(i,h,n,k,dp)) );
        }
        
        return dp[ind]=ans;
    }
    
    int solMemo(vector<int>& h, int n, int k){
        vector<int> dp(n+1,0);
        
        for(int ind=n-2;ind>=0;ind--){
            int ans=1e9;
            for(int i=ind+1;i<=ind+k && i<n;i++){
                ans=min(ans,(abs(h[i]-h[ind])+dp[i]));
            }
            dp[ind]=(ans==1e9?0:ans);
        }
        
        return dp[0];
    }
    
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        // return solRecusion(0,h,n,k);
        
        // vector<int> dp(n,-1);
        // return solDp(0,h,n,k,dp);
        
        return solMemo(h,n,k);
        
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