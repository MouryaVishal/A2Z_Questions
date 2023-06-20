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
    int solRec(int i,int j,vector<vector<int>>&m){
        if(i<0 || j>=m.size() || i>=m.size())return 1e9;
        if(i==m.size()-1)return m[i][j];
        int justDown=m[i][j]+solRec(i+1,j,m);
        int downleft=m[i][j]+solRec(i+1,j-1,m);
        int downright=m[i][j]+solRec(i+1,j+1,m);
        return min(justDown,min(downleft,downright));
    }

    int solDp(int i,int j,vector<vector<int>>&m,vector<vector<int>>&dp){
        if(i<0 || j>=m.size() || i>=m.size())return 1e9;
        if(i==m.size()-1)return m[i][j];
        if(dp[i][j]!=-1e9)return dp[i][j];
        int justDown=m[i][j]+solDp(i+1,j,m,dp);
        int downleft=m[i][j]+solDp(i+1,j-1,m,dp);
        int downright=m[i][j]+solDp(i+1,j+1,m,dp);
        return dp[i][j]=min(justDown,min(downleft,downright));
    }


    int solTab(vector<vector<int>>& m){
        vector<vector<int>> dp(m.size(),vector<int>(m.size(),0));
        int n=m.size();
        for(int i=0;i<n;i++){
            dp[n-1][i]=m[n-1][i];
        }
        int ans=1e9;
        for(int col=0;col<m.size();col++){
            dp[0][col]=m[0][col];
            for(int i=n-2;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    int justDown=m[i][j]+dp[i+1][j];
                    int downleft=m[i][j];
                    if(j-1>=0)
                    downleft+=dp[i+1][j-1];
                    else{
                        downleft+=1e9;
                    }
                    int downright=m[i][j];
                    if(j+1<n)
                    downright+=dp[i+1][j+1];
                    else{
                        downright+=1e9;
                    }
                    dp[i][j]=min(justDown,min(downleft,downright));
                }
            }
            ans=min(ans,dp[0][col]);
        }

        return ans;
    }

    int solSpaceOpt(vector<vector<int>>&m){
        vector<int> prev(m.size(),0),curr(m.size(),0);
        int n=m.size();
        for(int i=0;i<n;i++){
            prev[i]=m[n-1][i];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int justDown=m[i][j]+prev[j];
                int downleft=m[i][j];
                if(j-1>=0)
                downleft+=prev[j-1];
                else{
                    downleft+=1e9;
                }
                int downright=m[i][j];
                if(j+1<n)
                downright+=prev[j+1];
                else{
                    downright+=1e9;
                }
                curr[j]=min(justDown,min(downleft,downright));
            }
            prev=curr;
        }
        int ans=1e9;
        for(int j=0;j<n;j++){
            ans=min(ans,prev[j]);
        }

        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        // int ans=1e9;
        // // for(int j=0;j<m.size();j++){
        // //     ans=min(ans,solRec(0,j,m));
        // // }
        // // return ans;
        // vector<vector<int>> dp(m.size(),vector<int>(m.size(),-1e9));
        // for(int j=0;j<m.size();j++){
        //     ans=min(ans,solDp(0,j,m,dp));
        // }
        // return ans;

        // return solTab(m);

        return solSpaceOpt(m);
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