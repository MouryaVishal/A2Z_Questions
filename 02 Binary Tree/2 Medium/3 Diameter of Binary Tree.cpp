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
    int func(TreeNode* r,int &ans){
        if(r==NULL)return 0;
        int l=1+func(r->left,ans);
        int ri=1+func(r->right,ans);
        ans=max(ans,l+ri);
        return max(l,ri);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        func(root,ans);
        return ans-2;
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