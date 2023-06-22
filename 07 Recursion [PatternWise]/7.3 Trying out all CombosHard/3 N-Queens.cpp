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
    vector<bool> left,downCheck,upPrev;
    bool  possible (int i,int j,vector<string>&curr){
        int x=i;
        int y=j;
        while(x>=0 && y>=0){
            if(curr[x][y]=='Q') return false;
            x--,y--;
        }
        x=i,y=j;
        while(y>=0){
            if(curr[x][y]=='Q')return false;
            y--;
        }
        x=i,y=j;
        while(x<curr.size() && y>=0){
            if(curr[x][y]=='Q')return false;
            x++,y--;
        }
        return true;
    }
    void dfs(int j,int cnt,int n,vector<string>&curr,vector<vector<string>>&ans){
        if(cnt==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(possible(i,j,curr)){
                curr[i][j]='Q';
                dfs(j+1,cnt+1,n,curr,ans);
                curr[i][j]='.';
            }
        }
    }
    bool spaceOptPossible(int i,int j){
        return !left[i] && !downCheck[i+j] && !upPrev[left.size()-1+j-i];
    }
    void spaceOpt(int j,int cnt,int n,vector<string>&curr,vector<vector<string>>&ans){
        if(cnt==n){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(spaceOptPossible(i,j)){
                curr[i][j]='Q';
                left[i]=1;
                downCheck[i+j]=1;
                upPrev[left.size()-1+j-i]=1;
                spaceOpt(j+1,cnt+1,n,curr,ans);
                curr[i][j]='.';
                left[i]=0;
                downCheck[i+j]=0;
                upPrev[left.size()-1+j-i]=0;
                curr[i][j]='.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr;
        string s(n,'.');
        for(int i=0;i<n;i++){
            curr.push_back(s);
        }

        left.resize(n,0);
        downCheck.resize(2*n-1,0);
        upPrev.resize(2*n-1,0);
        spaceOpt(0,0,n,curr,ans);
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