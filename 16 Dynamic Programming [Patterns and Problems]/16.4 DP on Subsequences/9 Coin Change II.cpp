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
                return 1;
            }
            return 0;
        }
        int notpick=solRec(i+1,amt,c);
        int pick=0;
        if(c[i]<=amt){
            pick=solRec(i,amt-c[i],c);
        }
        return pick+notpick;
    }
     int solDp(int i,int amt,vector<int>&c,vector<vector<int>>&dp){
        if(i==c.size()-1){
            if(amt%c[i]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int notpick=solDp(i+1,amt,c,dp);
        int pick=0;
        if(c[i]<=amt){
            pick=solDp(i,amt-c[i],c,dp);
        }
        return dp[i][amt]=(pick+notpick);
    }
    int solTab(int money, vector<int>& c){
        vector<vector<int>> dp(c.size(),vector<int>(money+1,0));
        int n=c.size();
        for(int i=0;i<=money;i++)
            if(i%c[n-1]==0){
                dp[n-1][i]=1;
            }
        
        for(int i=n-2;i>=0;i--){
            for(int amt=0;amt<=money;amt++){
                int notpick=dp[i+1][amt];
                int pick=0;
                if(c[i]<=amt){
                    pick=dp[i][amt-c[i]];
                }
                dp[i][amt]=(pick+notpick);
            }
        }

        return dp[0][money];
    }
public:
    int change(int amt, vector<int>& c) {
        // return solRec(0,amt,c);

        // vector<vector<int>> dp(c.size(),vector<int>(amt+1,-1));
        // return solDp(0,amt,c,dp);

        return solTab(amt,c);
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