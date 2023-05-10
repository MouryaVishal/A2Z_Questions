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
    int maxProduct(vector<int>& nums) {
        int maxi(nums[0]), mini(nums[0]);
        int ans(nums[0]);
        for(int i=1;i<nums.size();i++){
            int temp=max({nums[i],maxi*nums[i],nums[i]*mini});
            mini=min({nums[i],maxi*nums[i],nums[i]*mini});
            maxi=temp;
            ans=max(ans,maxi);
        }

        return ans;
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