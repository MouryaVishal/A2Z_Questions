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
    int leftH(TreeNode*r){
        if(!r)return 0;
        int ans=1;
        r=r->left;
        while(r){
            ans++;
            r=r->left;
        }
        return ans;
    }
    int rightH(TreeNode*r){
        if(!r)return 0;
        int ans=1;
        r=r->right;
        while(r){
            ans++;
            r=r->right;
        }
        return ans;
    }
    int func(TreeNode*r){
        if(!r)return 0;
        int left=leftH(r);
        int right=rightH(r);
        cout<<left<<" "<<right<<endl;
        if(left==right)return (1<<left)-1;

        return 1+func(r->left)+func(r->right);
    }
public:
    int countNodes(TreeNode* root) {
        return func(root);
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