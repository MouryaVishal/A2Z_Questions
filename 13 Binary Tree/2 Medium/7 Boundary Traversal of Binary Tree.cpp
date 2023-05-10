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

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    bool isLeaf(Node*r){
        return !r->left  && !r->right;
    }
    void addLeftNode(Node*r,vector<int>&ans){
        Node* node=r->left;
        while(node){
            if(!isLeaf(node)) ans.push_back(node->data);
            if(node->left)node=node->left;
            else node=node->right;
        }
    }
    void addRightNode(Node*r,vector<int>&ans){
        Node* node=r->right;
        vector<int> temp;
        while(node){
            if(!isLeaf(node)) temp.push_back(node->data);
            if(node->right)node=node->right;
            else node=node->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    void addLeaf(Node*r,vector<int>&ans){
        if(isLeaf(r)){
            ans.push_back(r->data);
            return;
        }
        if(r->left)addLeaf(r->left,ans);
        if(r->right)addLeaf(r->right,ans);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftNode(root,ans);
        addLeaf(root,ans);
        addRightNode(root,ans);
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