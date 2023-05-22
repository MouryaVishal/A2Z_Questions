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
};
class Solution {
    int binarySearch(int i,int j,vector<int>&nums,int &tr,bool lower){
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==tr)ans=mid;
            if(lower && nums[mid]<tr) i=mid+1;
            else if(lower) j=mid-1;

            if(!lower && nums[mid]<=tr) i=mid+1;
            else if(!lower) j=mid-1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int tr) {
        int l=binarySearch(0,nums.size()-1,nums,tr,1);
        int u=binarySearch(0,nums.size()-1,nums,tr,0);
        return {l,u};
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