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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode*node=root;
        while(node){
            if(!node->left){
                ans.push_back(node->val);
                node=node->right;
            }else{
                TreeNode* rightmost=node->left;
                while(rightmost->right && rightmost->right!=node){
                    rightmost=rightmost->right;
                }

                if(!rightmost->right){
                    rightmost->right=node;
                    ans.push_back(node->val);
                    node=node->left;
                }else{
                    rightmost->right=NULL;
                    node=node->right;
                }
            }
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