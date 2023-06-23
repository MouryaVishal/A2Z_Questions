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
    int solrec(int i,int w,int n, int val[], int wt[],vector<vector<int>>&dp){
        if(i==n-1){
            int t=w/wt[n-1];
            return val[n-1]*t;
        }
        if(dp[i][w]!=-1)return dp[i][w];
        int notpick=solrec(i+1,w,n,val,wt,dp);
        int pick=0;
        if(wt[i]<=w){
            pick=val[i]+solrec(i,w-wt[i],n,val,wt,dp);
        }
        return dp[i][w]=max(pick,notpick);
    }
public:
    int knapSack(int n, int w, int val[], int wt[])
    {   
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
        return solrec(0,w,n,val,wt,dp);
        
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