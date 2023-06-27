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
int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> next(n);
        vector<int> prev(n);
        for(int i=0;i<n;i++){
            next[i]=n;
            prev[i]=-1;
        }
        stack<int> nextEle;
        stack<int> prevEle;
        for(int i=0;i<n;i++){
            while(!prevEle.empty() && arr[prevEle.top()]>=arr[i]){
                prevEle.pop();
            }
            if(!prevEle.empty()){
                prev[i]=prevEle.top();
            }
            prevEle.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!nextEle.empty() && arr[nextEle.top()]>arr[i]){
                nextEle.pop();
            }
            if(!nextEle.empty()){
                next[i]=nextEle.top();
            }
            nextEle.push(i);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans=(ans%mod+(1LL*arr[i]*(next[i]-i)*(i-prev[i]))%mod)%mod;
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