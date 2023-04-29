#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
// Definition for a binary tree node.
struct TreeNode {
        int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool func(TreeNode* p, TreeNode* q){
        if(!p && !q)return true;
        if(!p || !q)return false;

        if(p->val!=q->val)return false;

        return func(p->left,q->left) && func(p->right,q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return func(p,q);
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