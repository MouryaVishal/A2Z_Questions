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
    bool solRec(int ind,string &s,unordered_set<string>&st,vector<int> &dp){
        if(ind==s.size()){
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<s.size();i++){
            string req=s.substr(ind,i-ind+1);
            if(st.count(req)){
                bool curr=solRec(i+1,s,st,dp);
                if(curr) return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
public:
    bool wordBreak(string s, vector<string>& w) {
        vector<int> dp(s.size()+1,-1);
        unordered_set<string> st;
        for(auto a:w){
            st.insert(a);
        }
        return solRec(0,s,st,dp);
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