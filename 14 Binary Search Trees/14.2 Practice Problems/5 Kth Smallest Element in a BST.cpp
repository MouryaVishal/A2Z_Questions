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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x) : val(x), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans=0;
    bool flag=1;
    void func(TreeNode*root,int &k){
        if(!root)return;
        func(root->left,k);
        k--;
        if(k==0 && flag){
            ans=root->val;
            flag=0;
        }
        func(root->right,k);
    }


    
public:
    int kthSmallest(TreeNode* root, int K) {
       int val=0;
        TreeNode* cur=root;
        if(!root) return val;
        int c=0;
        while(cur){
            if(!cur->left){
                c++;
                if(c==K){
                    val=cur->val;
                };
                cur=cur->right;
            }
            else{
                TreeNode* p=cur->left;
                while(p->right!=NULL&&p->right!=cur){
                    p=p->right;                
                }
                if(!p->right){
                    p->right=cur;
                    cur=cur->left;
                }
                else{
                    p->right=NULL;
                    c++;
                    if(c==K){
                        val=cur->val; 
                    }                
                    cur=cur->right;
                }
            }
      }
      return val;
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