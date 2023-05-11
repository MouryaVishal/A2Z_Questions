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
  public:
    bool arraySortedOrNot(int nums[], int n) {
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]) return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) c++;
        }
        if(c==1)return nums[0]>=nums[nums.size()-1];
        return c==0;
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