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
    int solRec(int i,int j,vector<vector<int>>& t){
        if(j>=t[i].size())return 1e9;
        if(i==t.size()-1){
            return t[i][j];
        }
        int down=t[i][j]+solRec(i+1,j,t);
        int downRight=t[i][j]+solRec(i+1,j+1,t);

        return min(down,downRight);
    }

    int solDp(int i,int j,vector<vector<int>>&t,vector<vector<int>>&dp){
        if(j>=t[i].size())return 1e9;
        if(i==t.size()-1){
            return t[i][j];
        }
        if(dp[i][j]!=-1e9)return dp[i][j];
        int down=t[i][j]+solDp(i+1,j,t,dp);
        int downRight=t[i][j]+solDp(i+1,j+1,t,dp);

        return dp[i][j]=min(down,downRight);
    }

    int solTab(vector<vector<int>>&t){
        vector<vector<int>> dp(t.size(),vector<int>(t.size()+2,0));
        for(int i=0;i<t[t.size()-1].size();i++){
            dp[t.size()-1][i]=t[t.size()-1][i];
        }
        for(int i=t.size()-2;i>=0;i--){
            for(int j=t[i].size()-1;j>=0;j--){
                int down=t[i][j]+dp[i+1][j];
                int downRight=t[i][j]+(j+1<t[i+1].size()?dp[i+1][j+1]:1e9);
                dp[i][j]=min(down,downRight);
            }
        }

        return dp[0][0];
    }

    int solSpaceObt(vector<vector<int>>&t){
        vector<int> prev(t.size()+2,1e9),curr(t.size()+2,1e9);

        for(int i=0;i<t[t.size()-1].size();i++){
            prev[i]=t[t.size()-1][i];
        }
        for(int i=t.size()-2;i>=0;i--){
            for(int j=t[i].size()-1;j>=0;j--){
                int down=t[i][j]+prev[j];
                int downRight=t[i][j]+prev[j+1];
                curr[j]=min(down,downRight);
            }
            prev=curr;
        }

        return prev[0];
    }
public:
    int minimumTotal(vector<vector<int>>& t) {
        // return solRec(0,0,t);

        // vector<vector<int>> dp(t.size(),vector<int>(t.size()+2,-1e9));
        // return solDp(0,0,t,dp);

        // return solTab(t);

        return solSpaceObt(t);


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