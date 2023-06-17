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
    int funcDP(int i,vector<int>&h,vector<int>&dp){
        if(i>=h.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int step1=1e9,step2=1e9;
        if(i+1<h.size()){
            step1=abs(h[i]-h[i+1])+funcDP(i+1,h,dp);
        }
        if(i+2<h.size()){
            step2=abs(h[i]-h[i+2])+funcDP(i+2,h,dp);
        }
        return dp[i]=min(step1,step2);
    }
    int funcMemo(vector<int>&h,int n){
        vector<int> dp(n+2,0);
        
        for(int i=n-2;i>=0;i--){
            int step1=1e9,step2=1e9;
            step1=abs(h[i]-h[i+1])+dp[i+1];
            if(i+2<n)
                step2=abs(h[i]-h[i+2])+dp[i+2];
            dp[i]=min(step1,step2);
        }
        
        return dp[0];
    }
    
    int SpaceOpt(vector<int>&h,int n){
        int last=0;
        int prev=0;
        int curr=0;
        for(int i=n-2;i>=0;i--){
            int step1=1e9,step2=1e9;
            step1=abs(h[i]-h[i+1])+prev;
            if(i+2<n)
                step2=abs(h[i]-h[i+2])+last;
            curr=min(step1,step2);
            last=prev;
            prev=curr;
        }
        
        return curr;
    }
  public:
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        
        // vector<int> dp(n,-1);
        // return funcDP(0,h,dp);
        
        return SpaceOpt(h,n);
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