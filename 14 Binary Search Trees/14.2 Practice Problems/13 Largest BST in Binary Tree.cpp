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


class TreeNodeInfo{
    public:
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int size=0;
    bool isBST=false;
};

class Solution{
    TreeNodeInfo func(Node*root,int &ans){
        if(!root){
            return {INT_MIN,INT_MAX,0,true};
        }
        TreeNodeInfo left=func(root->left,ans);
        TreeNodeInfo right=func(root->right,ans);
        
        TreeNodeInfo currNode;
        currNode.size=left.size+right.size+1;
        currNode.maxi=max(root->data,right.maxi);
        currNode.mini=min(root->data,left.mini);
        
        if(left.isBST && right.isBST && root->data>left.maxi && root->data<right.mini){
            currNode.isBST=true;
        }
        
        if(currNode.isBST){
            ans=max(ans,currNode.size);
        }
        
        return currNode;
        
    }
    public:
    int largestBst(Node *root)
    {
        int ans=0;
        TreeNodeInfo bst=func(root,ans);
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