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
    int solRec(int i,int sell,vector<int>&p,int &fee){
        if(i==p.size()) {
            return 0;
        }
        int price=0;
        if(!sell){
            price=max(solRec(i+1,0,p,fee),-p[i]+solRec(i+1,1,p,fee));
        }else{
            price=max(p[i]-fee+solRec(i+1,0,p,fee),solRec(i+1,1,p,fee));
        }
        return price;
    }

    int solDp(int i,int sell,vector<int>&p,int &fee,vector<vector<int>>&dp){
        if(i==p.size()) {
            return 0;
        }
        if(dp[i][sell]!=-1)return dp[i][sell];
        int price=0;
        if(!sell){
            price=max(solDp(i+1,0,p,fee,dp),-p[i]+solDp(i+1,1,p,fee,dp));
        }else{
            price=max(p[i]-fee+solDp(i+1,0,p,fee,dp),solDp(i+1,1,p,fee,dp));
        }
        return dp[i][sell]=price;
    }

    int solTab(vector<int>&p,int &fee){
        vector<vector<int>> dp(p.size()+1,vector<int>(2,0));

        for(int i=p.size()-1;i>=0;i--){
            for(int sell=0;sell<2;sell++){
                int price=0;
                if(!sell){
                    price=max(dp[i+1][0],-p[i]+dp[i+1][1]);
                }else{
                    price=max(p[i]-fee+dp[i+1][0],dp[i+1][1]);
                }
                dp[i][sell]=price;
            }
        }

        return dp[0][0];
    }

    int spaceOpt(vector<int>&p,int &fee){
        vector<int> prev(2,0),curr(2,0);

        for(int i=p.size()-1;i>=0;i--){
            for(int sell=0;sell<2;sell++){
                int price=0;
                if(!sell){
                    price=max(prev[0],-p[i]+prev[1]);
                }else{
                    price=max(p[i]-fee+prev[0],prev[1]);
                }
                curr[sell]=price;
            }
            prev=curr;
        }

        return prev[0];
    }

public:
    int maxProfit(vector<int>& p, int fee) {
        // return solRec(0,0,p,fee);

        // vector<vector<int>> dp(p.size(),vector<int>(2,-1));
        // return solDp(0,0,p,fee,dp);

        // return solTab(p,fee);
        return spaceOpt(p,fee);
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