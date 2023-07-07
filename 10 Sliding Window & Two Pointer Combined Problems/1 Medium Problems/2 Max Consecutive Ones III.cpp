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
    bool possible(vector<int>&nums,int &k,int &mid){
        int cr=0;
        int j(0),i(0);
        while(j<mid){
            if(nums[j]==0)cr++;
            j++;
        }
        if(cr<=k)return true;
        while(j<nums.size()){
            if(nums[j]==0)cr++;
            if(nums[i]==0) cr--;
            i++;
            j++;
            if(cr<=k)return true;
        }
        return false;
    }
public:
    int longestOnes(vector<int>& nums, int k) {
        // int st=0;
        // int end=nums.size();
        // int ans=0;
        // while(st<=end){
        //     int mid=st+(end-st)/2;
        //     if(possible(nums,k,mid)){
        //         ans=mid;
        //         st=mid+1;
        //     }else{
        //         end=mid-1;
        //     }
        // }
        // return ans;
        int j(0),i(0);
        int ans=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]==0)cnt++;
            if(cnt>k){
                while(cnt>k){
                    if(nums[i]==0){
                        cnt--;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
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