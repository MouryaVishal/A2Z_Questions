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
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=(s+e)/2;
            if(mid%2)mid--;
            if( nums[mid]!=nums[mid+1]){
                e=mid;
            }else{
                s=mid+2;
            }
        }
        return nums[s];
    }
};


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if((mid==0 ||nums[mid-1]!=nums[mid]) && 
            (mid==nums.size()-1 || nums[mid+1]!=nums[mid]))return nums[mid];

            if(mid%2){
                if(mid==nums.size()-1 || nums[mid+1]==nums[mid]) end=mid-1;
                else{
                    st=mid+1;
                }
            }else{
                if(mid==0 ||nums[mid-1]==nums[mid])end=mid-1;
                else st=mid+1;
            }
        }

        return 0;
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