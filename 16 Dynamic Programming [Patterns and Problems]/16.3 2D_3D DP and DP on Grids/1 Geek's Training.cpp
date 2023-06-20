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
    int solRec(int i,int last,vector<vector<int>>& p, int n){
        if(i==n-1){
            int maxi=0;
            for(int ind=0;ind<3;ind++){
                if(ind!=last){
                    maxi=max(maxi,p[i][ind]);
                }
            }
            return maxi;
        }
        
        int maxi=0;
        for(int ind=0;ind<3;ind++){
            if(ind!=last){
                int curr=p[i][ind]+solRec(i+1,ind,p,n);
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
    
    
    int solDp(int i,int last,vector<vector<int>>& p, int n,vector<vector<int>>&dp){
        if(i==n-1){
            int maxi=0;
            for(int ind=0;ind<3;ind++){
                if(ind!=last){
                    maxi=max(maxi,p[i][ind]);
                }
            }
            return maxi;
        }
        if(dp[i][last]!=-1)return dp[i][last];
        int maxi=0;
        for(int ind=0;ind<3;ind++){
            if(ind!=last){
                int curr=p[i][ind]+solDp(i+1,ind,p,n,dp);
                maxi=max(maxi,curr);
            }
        }
        return dp[i][last]=maxi;
    }
    
    int solMemo(vector<vector<int>>& p, int n){
        vector<vector<int>> dp(n+1,vector<int>(4,0));
        for(int last=0;last<4;last++){
            for(int ind=0;ind<3;ind++){
                if(ind!=last){
                    int curr=p[n-1][ind]+dp[n-1+1][ind];
                    dp[n-1][last]=max(dp[n-1][last],curr);
                }
            }
        }
          for(int i=n-2;i>=0;i--){
              for(int last=0;last<4;last++){
                for(int ind=0;ind<3;ind++){
                    if(ind!=last){
                        int curr=p[i][ind]+dp[i+1][ind];
                        dp[i][last]=max(dp[i][last],curr);
                    }
                }
              }
          }
       
          return dp[0][3];
          
    }
    
  public:
    int maximumPoints(vector<vector<int>>& p, int n) {
        // Code here
        // return solRec(0,3,p,n);
        
        // vector<vector<int>> dp(n,vector<int>(4,-1));
        // return solDp(0,3,p,n,dp);
        
        return solMemo(p,n);
        
        // return solMemo(p,n);
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