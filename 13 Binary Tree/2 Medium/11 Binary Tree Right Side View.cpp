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
class Solution2 {
    
    void rightSideView(TreeNode* root,int level ,vector<int>& ans){
        if(root==NULL)return;
        
        if(ans.size()==level) ans.push_back(root->val);
        rightSideView(root->right,level+1,ans);
        rightSideView(root->left,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answerForRS;
        rightSideView(root,0,answerForRS);
        
        return answerForRS;
    }
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto a=q.front();
                q.pop();
                if(s==0){
                    ans.push_back(a->val);
                }
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
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