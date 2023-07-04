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
class Solution{
    int solRec(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>> &dp){
        if(i>j)return 0;
        if(i==j){
            if(isTrue)return s[i]=='T';
            return s[i]=='F';
        }
        
        if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
        
        int ways=0;
        for(int ind=i+1;ind<=j-1;ind=ind+2){
            int lfalse=solRec(i,ind-1,false,s,dp);
            int ltrue=solRec(i,ind-1,true,s,dp);
            int rfalse=solRec(ind+1,j,false,s,dp);
            int rtrue=solRec(ind+1,j,true,s,dp);
            if(s[ind]=='|'){
                if(isTrue){
                    ways+=(lfalse*rtrue+ltrue*rfalse+rtrue*ltrue)%1003;
                }else{
                    ways+=(lfalse*rfalse)%1003;
                }
            }else if(s[ind]=='&'){
                if(isTrue){
                    ways+=(rtrue*ltrue)%1003;
                }else{
                    ways+=(lfalse*rtrue+ltrue*rfalse+lfalse*rfalse)%1003;
                }
            }else if(s[ind]=='^'){
                if(isTrue){
                    ways+=(lfalse*rtrue+ltrue*rfalse)%1003;
                }else{
                    ways+=(rtrue*ltrue+lfalse*rfalse)%1003;
                }
            }
        }
        
        return dp[i][j][isTrue]=ways%1003;
    }
public:
    int countWays(int n, string s){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solRec(0,n-1,true,s,dp);
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