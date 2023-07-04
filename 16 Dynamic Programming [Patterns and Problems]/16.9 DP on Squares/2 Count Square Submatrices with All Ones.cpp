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
public:
    int countSquares(vector<vector<int>>& mt) {
        int n=mt.size();
        int m=mt[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i][0]=mt[i][0];
            ans+=dp[i][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j]=mt[0][j];
            ans+=dp[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mt[i][j]){
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
                ans+=dp[i][j];
            }
        }

        return ans;

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