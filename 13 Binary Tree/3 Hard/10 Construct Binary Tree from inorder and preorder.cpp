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
    TreeNode* func(int is,int ie,vector<int>&in,int ps,int pe,vector<int>&pt,unordered_map<int,int> &mp){
        if(is>ie ||ps>pe)return NULL;
        TreeNode* root=new TreeNode(pt[ps]);
        int k=mp[pt[ps]];
        int leftSide=k-is;
        root->left=func(is,k-1,in,ps+1,ps+leftSide,pt,mp);
        root->right=func(k+1,ie,in,ps+leftSide+1,pe,pt,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return func(0,inorder.size()-1,inorder,0,preorder.size()-1,preorder,mp);
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