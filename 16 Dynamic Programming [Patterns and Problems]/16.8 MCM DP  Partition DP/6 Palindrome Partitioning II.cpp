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
    bool palindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++,j--;
        }
        return true;
    }
    int solRec(int i,string &s,vector<int>&dp){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=1e9;
        for(int ind=i;ind<s.size();ind++){
            if(palindrome(i,ind,s)){
                int curr=1+solRec(ind+1,s,dp);
                ans=min(curr,ans);
            }
        }
        return dp[i]=ans;
    }
public:
    int minCut(string &s) {
        vector<int> dp(s.size()+1,-1);
        return solRec(0,s,dp)-1;
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