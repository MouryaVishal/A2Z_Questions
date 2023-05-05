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
    int func(TreeNode*node,int &ans){
        if(node==NULL)return 0;
        int left=func(node->left,ans);
        int right=func(node->right,ans);
        int nodeInPath=max(max(left,right)+node->val,node->val);
        int rootinPath=max(nodeInPath,left+right+node->val);
        ans=max(ans,rootinPath);
        return nodeInPath;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=-1001;
        func(root,ans);
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