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
    int sumAtlist(vector<int>&nums,int k){
        int st=0;
        int end=0;
        int curr=0;
        int ans=0;
        while(end<nums.size()){
            curr+=nums[end];
            while(st<=end && curr>k){
                curr-=nums[st++];
            }
            ans+=(end-st+1);
            end++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return sumAtlist(nums,k)-sumAtlist(nums,k-1);
    }
};
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int curr=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int req=curr-goal;
            if(mp.find(req)!=mp.end()){
                ans+=mp[req];
            }
            mp[curr]++;
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