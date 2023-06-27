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
    int solRec(int i,int j,string &s,string&t,vector<vector<int>>&dp){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int notpick=solRec(i+1,j,s,t,dp);
        int pick=0;
        if(s[i]==t[j]){
            pick=solRec(i+1,j+1,s,t,dp);
        }
        return dp[i][j]=pick+notpick;
    }
    int solMemo(string &s,string &t){
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m]=1;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                double notpick=dp[i+1][j];
                double pick=0;
                if(s[i]==t[j]){
                    pick=dp[i+1][j+1];
                }
                dp[i][j]=pick+notpick;
            }
        }

        return (int)dp[0][0];
    }
public:
    int numDistinct(string s, string t) {
        // int n=s.size();
        // int m=t.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solRec(0,0,s,t,dp);

        return solMemo(s,t);
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