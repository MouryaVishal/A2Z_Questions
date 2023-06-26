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
    int solRec(int i,int j,string &s,vector<vector<int>>&dp){
        if(j<i)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==s[j]){
            ans=solRec(i+1,j-1,s,dp);
        }else{
            ans=1+min(solRec(i+1,j,s,dp),solRec(i,j-1,s,dp));
        }
        return dp[i][j]=ans;
    }
    int solTab(string &s){
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j<i){
                    continue;
                }
                int ans=0;
                if(s[i]==s[j] && j-1>=0){
                    ans=dp[i+1][j-1];
                }else if( j-1>=0){
                    ans=1+min(dp[i+1][j],dp[i][j-1]);
                }
                dp[i][j]=ans;
            }
        }

        return dp[0][n-1];
    }
public:
    int minInsertions(string s) {
        // int n=s.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solRec(0,n-1,s,dp);
        return solTab(s);
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