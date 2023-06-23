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
    int solRec(int i,int amt,vector<int>&c){
        if(i==c.size()-1){
            if(amt%c[i]==0){
                return amt/c[i];
            }
            return 1e9;
        }
        int notpick=0+solRec(i+1,amt,c);
        int pick=1e9;
        if(c[i]<=amt){
            pick=1+solRec(i,amt-c[i],c);
        }
        return min(pick,notpick);
    }

    int solDp(int i,int amt,vector<int>&c,vector<vector<int>>&dp){
        if(i==c.size()-1){
            if(amt%c[i]==0){
                return amt/c[i];
            }
            return 1e9;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int notpick=solDp(i+1,amt,c,dp);
        int pick=1e9;
        if(c[i]<=amt){
            pick=1+solDp(i,amt-c[i],c,dp);
        }
        return dp[i][amt]=min(pick,notpick);
    }


public:
    int coinChange(vector<int>& c, int amt) {
        // int ans=solRec(0,amt,c);
        vector<vector<int>> dp(c.size(),vector<int>(amt+1,-1));
        int ans=solDp(0,amt,c,dp);
        return ans==1e9?-1:ans;
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