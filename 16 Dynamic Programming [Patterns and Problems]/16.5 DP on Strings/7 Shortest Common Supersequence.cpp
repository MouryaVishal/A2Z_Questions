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
    string  solTab(string &t1,string &t2){
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(t1[i]==t2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        int len=dp[0][0];
        string ans="";
        int i(0),j(0),ind(0);
        while(i<n && j<m ){
            if(t1[i]==t2[j]){
                ans+=t1[i];
                i++,j++;
            }else if(dp[i][j+1]>dp[i+1][j]){
                ans+=t2[j];
                j++;
            }else{
                ans+=t1[i];
                i++;
            }
        }
        while(i<n){
            ans+=t1[i];
            i++;
        }
        while(j<m){
            ans+=t2[j];
            j++;
        }
        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return solTab(str1,str2);
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