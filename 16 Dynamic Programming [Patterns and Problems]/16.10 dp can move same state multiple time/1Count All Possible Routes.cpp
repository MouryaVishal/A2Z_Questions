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
    int mod=1e9+7;
    int solRec(int ind,int fl,int s,int f,vector<int>&c,vector<vector<int>>&dp){
        if(fl<0)return 0;
        // if(f==ind){
        //     int temp=1;
        //     for(int i=0;i<c.size();i++){
        //         if(i!=ind){
        //             temp=(temp%mod+solRec(i,fl-abs(c[ind]-c[i]),s,f,c,dp)%mod)%mod;
        //         }
        //     }
        //     return temp;
        // }
        if(dp[ind][fl]!=-1)return dp[ind][fl];
        int ans=f==ind?1:0;
        for(int i=0;i<c.size();i++){
            if(i!=ind){
                ans=(ans+solRec(i,fl-abs(c[ind]-c[i]),s,f,c,dp)%mod)%mod;
            }
        }
        return dp[ind][fl]=ans%mod;
    }
public:
    int countRoutes(vector<int>& l, int s, int f, int fl) {
        vector<vector<int>> dp(l.size(),vector<int>(fl+5,-1));
        return solRec(s,fl,s,f,l,dp);
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