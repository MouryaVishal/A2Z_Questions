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
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> pr(n);
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            pr[i]=i;
        }
        int ind=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i-1;prev++){
                if(arr[prev]<arr[i] && (arr[prev]%arr[i]==0 || arr[i]%arr[prev]==0) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    pr[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;
            }
        }
        
        vector<int> temp;
        while(pr[ind]!=ind){
            temp.push_back(arr[ind]);
            ind=pr[ind];
        }
        temp.push_back(arr[ind]);
        reverse(temp.begin(),temp.end());
        return temp;
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