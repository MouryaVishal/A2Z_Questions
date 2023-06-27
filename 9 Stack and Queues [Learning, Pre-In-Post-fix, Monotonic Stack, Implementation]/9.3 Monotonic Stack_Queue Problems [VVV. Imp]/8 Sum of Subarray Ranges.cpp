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
    int mod=1e9+7;
    vector<int> nxt_min,prev_min,nxt_max,prev_max;
    void sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> nextEle;
        stack<int> prevEle;
        for(int i=0;i<n;i++){
            while(!prevEle.empty() && arr[prevEle.top()]>=arr[i]){
                prevEle.pop();
            }
            if(!prevEle.empty()){
                prev_min[i]=prevEle.top();
            }
            prevEle.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!nextEle.empty() && arr[nextEle.top()]>arr[i]){
                nextEle.pop();
            }
            if(!nextEle.empty()){
                nxt_min[i]=nextEle.top();
            }
            nextEle.push(i);
        }
    }
void sumSubarrayMax(vector<int>& arr) {
        int n=arr.size();
        stack<int> nextEle;
        stack<int> prevEle;
        for(int i=0;i<n;i++){
            while(!prevEle.empty() && arr[prevEle.top()]<=arr[i]){
                prevEle.pop();
            }
            if(!prevEle.empty()){
                prev_max[i]=prevEle.top();
            }
            prevEle.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!nextEle.empty() && arr[nextEle.top()]<arr[i]){
                nextEle.pop();
            }
            if(!nextEle.empty()){
                nxt_max[i]=nextEle.top();
            }
            nextEle.push(i);
        }

    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        prev_max.resize(n,-1);
        nxt_max.resize(n,n);
        prev_min.resize(n,-1);
        nxt_min.resize(n,n);
        sumSubarrayMins(nums);
        sumSubarrayMax(nums);
        long long sum = 0;
        long long right_max,left_max,right_min,left_min;
        for(int i = 0;i < n;i++){
            right_max = nxt_max[i] - i;
            left_max = i - prev_max[i];
            right_min = nxt_min[i] - i;
            left_min = i - prev_min[i];
            sum += (right_max*left_max - left_min*right_min)*nums[i];
        }
        return sum;
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