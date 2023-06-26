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
    int solRec(int i,int j,string &t1,string &t2){
        if(i>=t1.size() || j>=t2.size()){
            return 0;
        }
        int ans=0;
        if(t1[i]==t2[j]){
            ans=1+solRec(i+1,j+1,t1,t2);
        }else{
            ans=max(solRec(i+1,j,t1,t2),solRec(i,j+1,t1,t2));
        }
        return ans;
    }

    int solRec(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        if(i>=t1.size() || j>=t2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(t1[i]==t2[j]){
            ans=1+solRec(i+1,j+1,t1,t2,dp);
        }else{
            ans=max(solRec(i+1,j,t1,t2,dp),solRec(i,j+1,t1,t2,dp));
        }
        return dp[i][j]=ans;
    }
    int solTab(string &t1,string &t2){
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(t1[i]==t2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
public:
    int longestCommonSubsequence(string t1, string t2) {
        // return solRec(0,0,t1,t2);
        // vector<vector<int>> dp(t1.size(),vector<int>(t2.size(),-1));
        // return solRec(0,0,t1,t2,dp);

        return solTab(t1,t2);
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