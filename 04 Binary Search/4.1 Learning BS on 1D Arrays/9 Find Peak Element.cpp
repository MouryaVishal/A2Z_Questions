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
#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if((mid==0 || nums[mid-1]<nums[mid]) && (mid==nums.size()-1 || nums[mid+1]<nums[mid])) return mid;

            if(mid==0 || nums[mid-1]<nums[mid]) st=mid+1;
            else end=mid-1;        
        }
        return 0;
    }
};



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