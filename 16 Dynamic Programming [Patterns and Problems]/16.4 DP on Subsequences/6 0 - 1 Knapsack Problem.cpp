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
    public:
    int solRec(int i,int w,int n,int wt[], int val[]){
        if(i==n-1){
            if(wt[i]<=w){
                return val[i];
            }
            return 0;
        }
        int notpick=solRec(i+1,w,n,wt,val);
        int pick=0;
        if(wt[i]<=w){
            pick+=val[i]+solRec(i+1,w-wt[i],n,wt,val);
        }
        
        return max(pick,notpick);
    }
    
    int solDp(int i,int w,int n,int wt[], int val[],vector<vector<int>>&dp){
        if(i==n-1){
            if(wt[i]<=w){
                return val[i];
            }
            return 0;
        }
        if(dp[i][w]!=-1)return dp[i][w];
        int notpick=solDp(i+1,w,n,wt,val,dp);
        int pick=0;
        if(wt[i]<=w){
            pick+=val[i]+solDp(i+1,w-wt[i],n,wt,val,dp);
        }
        
        return dp[i][w]=max(pick,notpick);
    }
    
    int solTab(int wgive, int wt[], int val[], int n){
        vector<vector<int>> dp(n+1,vector<int>(wgive+5,0));
        
        for(int i=wt[n-1];i<=wgive;i++){
            dp[n-1][i]=val[n-1];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int w=0;w<=wgive;w++){
                int notpick=dp[i+1][w];
                int pick=0;
                if(wt[i]<=w){
                    pick+=val[i]+dp[i+1][w-wt[i]];
                }
                dp[i][w]=max(pick,notpick);
            }
        }
        
        return dp[0][wgive];
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        // return solRec(0,w,n,wt,val);
        // vector<vector<int>> dp(n,vector<int>(w+1,-1));
        // return solDp(0,w,n,wt,val,dp);
        
        
        return solTab(w,wt,val,n);
       // Your code here
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