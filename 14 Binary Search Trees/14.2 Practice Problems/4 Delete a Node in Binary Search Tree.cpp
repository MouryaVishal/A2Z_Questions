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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* findRightMost(TreeNode*r){
        if(r->right==NULL)return r;
        return findRightMost(r->right);
    }
    TreeNode* func(TreeNode*root){
        if(!root->left)return root->right;
        if(!root->right)return root->left;

        TreeNode* rightChild=root->right;
        TreeNode* rightmostChild=findRightMost(root->left);
        rightmostChild->right=rightChild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val==key){
            return func(root);
        }

        TreeNode*node=root;
        while(node){
            if(node->val>key){
                if(node->left && node->left->val==key){
                    node->left=func(node->left);
                    break;
                }else{
                    node=node->left;
                }
            }else{
                if(node->right && node->right->val==key){
                    node->right=func(node->right);
                    break;
                }else{
                    node=node->right;
                }
            }
        }

        return root;
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