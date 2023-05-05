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
class Solution2 {
    int func(int i,vector<int>&a,int &k,int x,vector<vector<int>>&dp){
        if(i==a.size()){ 
            if(x==k)return 1;
            return 0;
        }
        if(dp[i][x]!=-1)return dp[i][x];
        int pick=func(i+1,a,k,x^a[i],dp);
        int notpick=func(i+1,a,k,x,dp);
        return dp[i][x]=pick+notpick;
    }
public:
    int subsetXOR(vector<int> arr, int N, int k) {
        int maxi=*max_element(arr.begin(),arr.end());
        int m = (1 << (int)(log2(maxi) + 1) ) - 1; 
        if(k>m)return 0;
        vector<vector<int>> dp(N+1,vector<int>(m+1,-1));
        return func(0,arr,k,0,dp);
    }
};
class Solution{
    void func(int i,vector<int>&arr,int &k,int x,int &c){
        if(i==arr.size()){
            if(x==k){
                c++;
            } 
            return ;
        }
        x^=arr[i];
        func(i+1,arr,k,x,c);
        x^=arr[i];
        func(i+1,arr,k,x,c);
    }
public:
    int subsetXOR(vector<int> arr, int N, int k) {
        // vector<int> temp;
        int c=0;
        int x=0;
        func(0,arr,k,x,c);
        return c;
    }
};

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}