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
 class BSTTraversal{
    stack<TreeNode*> st;
    bool left=true;
    public:
        BSTTraversal(TreeNode*root,bool rev){
            left=rev;
            pushNode(root);
        }
        int next(){
            TreeNode* t=st.top();
            st.pop();
            if(left) pushNode(t->right);
            else pushNode(t->left);
            return t->val;
        }
        void pushNode(TreeNode*r){
            for(;r!=NULL;r=(left?r->left:r->right)){
                st.push(r);
            }
        }

 };
class Solution {
    bool func(TreeNode*r,int k,unordered_map<int,int>&mp){
        if(!r)return false;
        int req=k-r->val;
        if(mp.find(req)!=mp.end())return true;
        mp[r->val]++;
        bool left=func(r->left,k,mp);
        if(left)return true;
        return func(r->right,k,mp);

    }
public:
    bool findTarget(TreeNode* root, int k) {
        // unordered_map<int,int> mp;
        // return func(root,k,mp);
        if(!root)return false;
        BSTTraversal i(root,1);
        BSTTraversal j(root,0);

        int l=i.next();
        int r=j.next();
        while(l<r){
            if(l+r==k)return true;
            if(l+r>k){
                r=j.next();
            }else{
                l=i.next();
            }
        }

        return false;

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