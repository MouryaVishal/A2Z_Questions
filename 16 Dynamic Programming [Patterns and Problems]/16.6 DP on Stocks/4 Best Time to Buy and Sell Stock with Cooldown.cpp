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
    int solRec(int i,int by,vector<int>& p){
        if(i>=p.size())return 0;
        if(i==p.size()-1){
            if(!by)return p[i];
            return 0;
        }
        int profit=0;
        if(by){
            profit=max(solRec(i+1,by,p),-p[i]+solRec(i+1,0,p));
        }else{
            profit=max(solRec(i+1,0,p),p[i]+solRec(i+1,1,p));
        }
        return profit;
    }
    int solRec(int i,int by,vector<int>& p,vector<vector<int>>&dp){
        if(i>=p.size())return 0;
        if(i==p.size()-1){
            if(!by)return p[i];
            return 0;
        }
        if(dp[i][by]!=-1)return dp[i][by];
        int profit=0;
        if(by){
            profit=max(solRec(i+1,by,p,dp),-p[i]+solRec(i+1,0,p,dp));
        }else{
            profit=max(solRec(i+1,0,p,dp),p[i]+solRec(i+2,1,p,dp));
        }
        return dp[i][by]=profit;
    }

    int solMemo(vector<int>&p){
        int n=p.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n-1][0]=p[n-1];
        for(int i=n-2;i>=0;i--){
            for(int by=0;by<2;by++){
                int profit=0;
                if(by){
                    profit=max(dp[i+1][by],-p[i]+dp[i+1][0]);
                }else{
                    profit=max(dp[i+1][0],p[i]+dp[i+2][1]);
                }
                dp[i][by]=profit;
            }
        }

        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& p) {
        // return solRec(0,1,p);
        vector<vector<int>> dp(p.size(),vector<int>(2,-1));
        return solRec(0,1,p,dp);

        // return solMemo(p);

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