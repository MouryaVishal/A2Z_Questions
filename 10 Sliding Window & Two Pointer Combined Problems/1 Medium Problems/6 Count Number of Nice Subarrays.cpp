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
            curr+=nums[end]%2?1:0;
            while(st<=end && curr>k){
                curr-=(nums[st++]%2?1:0);
            }
            ans+=(end-st+1);
            end++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // return sumAtlist(nums,k)-sumAtlist(nums,k-1);
        int st=0,end=0,ans=0,odd=0,count=0;
        while(end<nums.size()){
            if(nums[end]&1){
                odd++;
                if(odd>=k){
                    count=1;
                    while(!(nums[st++]&1))count++;
                    ans+=count;
                }
            }else if(odd>=k){
                ans+=count;
            }
            end++;
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