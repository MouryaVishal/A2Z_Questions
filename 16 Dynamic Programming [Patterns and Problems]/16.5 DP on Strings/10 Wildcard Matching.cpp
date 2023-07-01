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
    int solRec(int i,int j,string&s,string&p,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size())return 1;
        if(i==s.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*')return false;
            }
            return 1;
        }
        if(j==p.size())return false;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=false;
        if(s[i]==p[j] || p[j]=='?'){
            ans=solRec(i+1,j+1,s,p,dp);
        }else if(p[j]=='*'){
            ans=solRec(i,j+1,s,p,dp);
            for(int ind=i;ind<s.size();ind++){
                ans=ans||solRec(ind+1,j+1,s,p,dp);
            }
        }
        return dp[i][j]=ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return solRec(0,0,s,p,dp);
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