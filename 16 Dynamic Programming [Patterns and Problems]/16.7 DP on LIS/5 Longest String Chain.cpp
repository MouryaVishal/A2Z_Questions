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
    bool possible(string &next,string &pr){
        if((next.size()-pr.size())!=1)return false;
        int i(0),j(0);
        while(i<next.size()){
            if(next[i]!=pr[j]){
                i++;
            }else{
                j++,i++;
            }
        }
        return j==pr.size() ;

    }
    int solRec(int i,int pr,vector<string>&w ,vector<vector<int>>&dp){
        if(i==w.size())return 0;
        if(dp[i][pr+1]!=-1)return dp[i][pr+1];
        int notpick=solRec(i+1,pr,w,dp);
        int pick=0;
        if(pr==-1 ||possible(w[i],w[pr])){
            pick=1+solRec(i+1,i,w,dp);
        }

        return dp[i][pr+1]=max(pick,notpick);
    }
public:
    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),[&](string&w1,string&w2){
            return w1.size()<w2.size();
        });

        // for(auto a:w){
        //     cout<<a<<" ";
        // }
        vector<vector<int>>dp(w.size()+1,vector<int>(w.size()+1,-1));
        return solRec(0,-1,w,dp);
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