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
    int solRec(int i,int n,int p[],int num,vector<vector<int>>&dp){
        if(i==num-1){
            if(n%(num)==0){
                return (n/(num))*p[i];
            }
            return 0;
        }
        if(dp[i][n]!=-1)return dp[i][n];
        int notpick=0+solRec(i+1,n,p,num,dp);
        int pick=0;
        if((i+1)<=n){
            pick=p[i]+solRec(i,n-(i+1),p,num,dp);
        }
        return dp[i][n]=max(pick,notpick);
    }
    
    int solMemo(int p[],int num){
        vector<vector<int>> dp(num+1,vector<int>(num+1,0));
        for(int i=0;i<=num;i++){
            if(i%(num)==0){
                dp[num-1][i]=(i/(num))*p[num-1];
            }
        }
        
        for(int i=num-2;i>=0;i--){
            for(int n=0;n<=num;n++){
                int notpick=0+dp[i+1][n];
                int pick=0;
                if((i+1)<=n){
                    pick=p[i]+dp[i][n-(i+1)];
                }
                dp[i][n]=max(pick,notpick);
            }
        }
        
        return dp[0][num];
    }
    
  public:
    int cutRod(int p[], int n) {
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solRec(0,n,p,n,dp);
        
        return solMemo(p,n);
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