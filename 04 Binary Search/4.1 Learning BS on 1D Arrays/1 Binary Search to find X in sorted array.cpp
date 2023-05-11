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
    int func(int i,int j,vector<int>&nums,int &tr){
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==tr)return mid;
            if(nums[mid]>tr){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return func(0,nums.size()-1,nums,target);
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