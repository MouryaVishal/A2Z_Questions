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
    int solRec(int i,int j,vector<vector<int>>&g){
        if(i==g.size()-1 && g[0].size()-1==j){
            return g[i][j];
        }
        int right=1e9;
        int down=1e9;
        if(i+1<g.size()){
            right=g[i][j]+solRec(i+1,j,g);
        }
        if(j+1<g[0].size()){
            down=g[i][j]+solRec(i,j+1,g);
        }

        return min(right,down);
    }

    int solDp(int i,int j,vector<vector<int>>&g,vector<vector<int>>&dp){
        if(i==g.size()-1 && g[0].size()-1==j){
            return g[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=1e9;
        int down=1e9;
        if(i+1<g.size()){
            right=g[i][j]+solDp(i+1,j,g,dp);
        }
        if(j+1<g[0].size()){
            down=g[i][j]+solDp(i,j+1,g,dp);
        }

        return dp[i][j]=min(right,down);
    }

    int solMemo(vector<vector<int>>&g){
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        dp[n-1][m-1]=g[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1 && i==n-1){
                    continue;
                }
                int right=1e9;
                int down=1e9;
                if(i+1<g.size()){
                    right=g[i][j]+dp[i+1][j];
                }
                if(j+1<g[0].size()){
                    down=g[i][j]+dp[i][j+1];
                }
                dp[i][j]=min(right,down);
            }
        }

        return dp[0][0];
    }

    int spaceOpt(vector<vector<int>>&g){
        int n=g.size();
        int m=g[0].size();
        vector<int> prev(m,0),curr(m,0);

        curr[m-1]=g[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1 && i==n-1){
                    continue;
                }
                int right=1e9;
                int down=1e9;
                if(i+1<g.size()){
                    right=g[i][j]+prev[j];
                }
                if(j+1<g[0].size()){
                    down=g[i][j]+curr[j+1];
                }
                curr[j]=min(right,down);
            }
            prev=curr;
        }

        return prev[0];
    }


public:
    int minPathSum(vector<vector<int>>& grid) {
        // return solRec(0,0,grid);

        // vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return solDp(0,0,grid,dp);

        return spaceOpt(grid);
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