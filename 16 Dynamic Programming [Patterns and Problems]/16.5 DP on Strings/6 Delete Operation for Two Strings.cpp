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
    int solRec(int i,int j,string &w1,string&w2,vector<vector<int>>&dp){
        if(i>=w1.size()|| j>=w2.size()){
            if(i>=w1.size()&& j>=w2.size())return 0;
            if(i==w1.size()){
                return w2.size()-j;
            }
            return w1.size()-i;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(w1[i]==w2[j]){
            ans=solRec(i+1,j+1,w1,w2,dp);
        }else{
            ans=1+min(solRec(i+1,j,w1,w2,dp),solRec(i,j+1,w1,w2,dp));
        }
        return dp[i][j]=ans;
    }
    int solTab(string&w1,string&w2){
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(w1.size()+1,vector<int>(w2.size()+1,0));

        for(int i=0;i<m;i++)
        {
            dp[n][i]=m-i;
        }
        for(int i=0;i<n;i++)
        {
            dp[i][m]=n-i;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(w1[i]==w2[j]){
                    ans=dp[i+1][j+1];
                }else{
                    ans=1+min(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
public:
    int minDistance(string w1, string w2) {
        // vector<vector<int>> dp(w1.size(),vector<int>(w2.size(),-1));

        // return solRec(0,0,w1,w2,dp);
        return solTab(w1,w2);

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