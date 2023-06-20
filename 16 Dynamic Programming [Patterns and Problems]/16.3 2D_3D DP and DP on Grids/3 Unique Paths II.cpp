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
    int solRec(int i,int j,vector<vector<int>>& ob){
        if(i==ob.size()-1 && j==ob[0].size()-1){
            return 1;
        }
        int right=0;
        int down=0;
        if(i+1<ob.size() && !ob[i+1][j]){
            right=solRec(i+1,j,ob);
        }
        if(j+1<ob[0].size() && !ob[i][j+1]){
            down=solRec(i,j+1,ob);
        }

        return right+down;
    }

    int solDp(int i,int j,vector<vector<int>>& ob,vector<vector<int>>&dp){
        if(i==ob.size()-1 && j==ob[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=0;
        int down=0;
        if(i+1<ob.size() && !ob[i+1][j]){
            right=solDp(i+1,j,ob,dp);
        }
        if(j+1<ob[0].size() && !ob[i][j+1]){
            down=solDp(i,j+1,ob,dp);
        }

        return dp[i][j]=right+down;
    }

    int solMemo(vector<vector<int>>&ob){
        int n=ob.size();
        int m=ob[0].size();
        vector<vector<long long >> dp(n,vector<long long >(m,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    continue;
                }
                long long  right=0;
                long long  down=0;
                if(i+1<ob.size() && !ob[i+1][j]){
                    right=dp[i+1][j];
                }
                if(j+1<ob[0].size() && !ob[i][j+1]){
                    down=dp[i][j+1];
                }
                dp[i][j]=right+down;
            }
        }

        return (int)dp[0][0];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        if(ob[0][0] || ob[ob.size()-1][ob[0].size()-1])return 0;
        // return solRec(0,0,ob);

        // vector<vector<int>> dp(ob.size(),vector<int>(ob[0].size(),-1));
        // return solDp(0,0,ob,dp);

        return solMemo(ob);

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