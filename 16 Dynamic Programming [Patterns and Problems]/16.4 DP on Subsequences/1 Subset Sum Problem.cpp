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
    bool solRec(int i,vector<int>&arr,int sum){
        if(sum==0){
            return true;
        }
        if(i==arr.size()-1){
            if(sum==arr[i])return true;
            return false;
        }
        
        bool  pick=false;
        if(sum>=arr[i])
            pick=solRec(i+1,arr,sum-arr[i]);
        bool notpick=solRec(i+1,arr,sum);
        
        return notpick|| pick;
    }
    
    bool solDp(int i,vector<int>&arr,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(i==arr.size()-1){
            if(sum==arr[i])return true;
            return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool pick=false;
        if(sum>=arr[i])
            pick=solDp(i+1,arr,sum-arr[i],dp);
        bool notpick=solDp(i+1,arr,sum,dp);
        
        return dp[i][sum]=notpick|| pick;
    }
    
    bool solTab(vector<int>&arr, int s){
        vector<vector<int>> dp(arr.size()+1,vector<int>(s+1,0));
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        dp[n-1][arr[n-1]]=1;
        
        for(int i=arr.size()-2;i>=0;i--){
            for(int sum=1;sum<=s;sum++){
                bool  pick=false,notpick=notpick=dp[i+1][sum];;
                if(sum>=arr[i])
                    pick=dp[i+1][sum-arr[i]];
                dp[i][sum]=notpick|| pick;
            }
        }
        return dp[0][s];
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // return solRec(0,arr,sum);
        // vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        // return solDp(0,arr,sum,dp);
        
        return solTab(arr,sum);
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