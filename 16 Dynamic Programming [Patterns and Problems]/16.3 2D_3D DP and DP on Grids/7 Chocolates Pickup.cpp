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
    int solRec(int i,int j,int k,vector<vector<int>>& g,vector<vector<vector<int>>> &dp){
        if(j<0 || k<0 || j>=g[0].size()|| k>=g[0].size()){
            return -1e8;
        }
        if(i==g.size()-1){
           return (j==k?g[i][j]:g[i][j]+g[i][k]);
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int maxi=0;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                int curr=0;
                if(j==k){
                    curr=g[i][k];
                }else{
                    curr=g[i][k]+g[i][j];
                }
                curr+=solRec(i+1,j+a,k+b,g,dp);
                maxi=max(maxi,curr);
            }
        }
        
        return dp[i][j][k]=maxi;
    }
    
    int solTab(int n, int m, vector<vector<int>>& g){
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
         
         for(int j=0;j<m;j++){
             for(int k=0;k<m;k++){
                 dp[n-1][j][k]=(j==k?g[n-1][j]:g[n-1][j]+g[n-1][k]);
             }
         }
         
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    int maxi=0;
                    for(int a=-1;a<=1;a++){
                        for(int b=-1;b<=1;b++){
                            int curr=0;
                            if(j==k){
                                curr=g[i][k];
                            }else{
                                curr=g[i][k]+g[i][j];
                            }
                            if(j+a<0 || j+a>=m ||k+b<0 || k+b>=m){
                                curr+=-1e8;
                            }else{
                                curr+=dp[i+1][j+a][k+b];
                            }
                            maxi=max(maxi,curr);
                        }
                    }
                    dp[i][j][k]=maxi;
                }
            } 
        }
        
        return dp[0][0][m-1];
    }
    
    int solSpaceOpt(int n, int m, vector<vector<int>>& g){
        vector<vector<int>> prev(m,vector<int>(m,0)),curr(m,vector<int>(m,0));
         
         for(int j=0;j<m;j++){
             for(int k=0;k<m;k++){
                 prev[j][k]=(j==k?g[n-1][j]:g[n-1][j]+g[n-1][k]);
             }
         }
         
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    int maxi=0;
                    for(int a=-1;a<=1;a++){
                        for(int b=-1;b<=1;b++){
                            int currVal=0;
                            if(j==k){
                                currVal=g[i][k];
                            }else{
                                currVal=g[i][k]+g[i][j];
                            }
                            if(j+a<0 || j+a>=m ||k+b<0 || k+b>=m){
                                currVal+=-1e8;
                            }else{
                                currVal+=prev[j+a][k+b];
                            }
                            maxi=max(maxi,currVal);
                        }
                    }
                    curr[j][k]=maxi;
                }
            }
            prev=curr;
        }
        
        return prev[0][m-1];
    }
  public:
    int solve(int n, int m, vector<vector<int>>& g) {
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // return solRec(0,0,m-1,g,dp);
        
        
        // return solTab(n,m,g);
        
        return solSpaceOpt(n,m,g);
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