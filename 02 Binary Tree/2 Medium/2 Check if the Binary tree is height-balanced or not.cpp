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
    int func(TreeNode* node,int &temp){
        if(node==NULL)return 0;
        int left=1+func(node->left,temp);
        int right=1+func(node->right,temp);
        if(abs(left-right)>1){
            temp=0;
            return 1;
        }

        return max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int temp=1;
        int d=func(root,temp);
        return temp;
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