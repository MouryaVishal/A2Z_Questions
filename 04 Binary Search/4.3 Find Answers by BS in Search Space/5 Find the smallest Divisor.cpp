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
    bool possible(int mid,vector<int>& nums, int &th){
        int sum=0;
        for(auto&a:nums){
            sum+=a/mid+(a%mid?1:0);
        }
        return sum<=th;
    }
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int st=1;
        int end=*max_element(begin(nums),nums.end());
        int ans=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(mid,nums,th)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        return ans;

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