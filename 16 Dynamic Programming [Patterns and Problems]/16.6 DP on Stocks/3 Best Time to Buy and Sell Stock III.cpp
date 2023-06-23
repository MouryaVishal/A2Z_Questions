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
    int solRec(int i,int by,int tr,vector<int>& p){
        if(tr==0)return 0;
        if(i==p.size()-1){
            if(!by)return p[i];
            return 0;
        }
        int profit=0;
        if(by){
            profit=max(solRec(i+1,by,tr,p),-p[i]+solRec(i+1,0,tr,p));
        }else{
            profit=max(solRec(i+1,0,tr,p),p[i]+solRec(i+1,1,tr-1,p));
        }
        return profit;
    }
    int solRec(int i,int by,int tr,vector<int>& p,vector<vector<vector<int>>>&dp){
        if(tr==0)return 0;
        if(i==p.size()-1){
            if(!by)return p[i];
            return 0;
        }
        if(dp[i][by][tr]!=-1)return dp[i][by][tr];
        int profit=0;
        if(by){
            profit=max(solRec(i+1,by,tr,p,dp),-p[i]+solRec(i+1,0,tr,p,dp));
        }else{
            profit=max(solRec(i+1,0,tr,p,dp),p[i]+solRec(i+1,1,tr-1,p,dp));
        }
        return dp[i][by][tr]=profit;
    } 
public:
    int maxProfit(vector<int>& p) {
        // return solRec(0,1,2,p);
        vector<vector<vector<int>>> dp(p.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solRec(0,1,2,p,dp);
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