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
    TreeNode* func(int is,int ie,vector<int>&in,int ps,int pe,vector<int>&post
    ,unordered_map<int,int>&mp){
        if( pe<ps || ie<is)return NULL;
        TreeNode*root=new TreeNode(post[pe]);
        int k=mp[post[pe]];
        int leftside=k-is;
        root->left=func(is,k-1,in,ps,ps+leftside-1,post,mp);
        root->right=func(k+1,ie,in,ps+leftside,pe-1,post,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& ps) {
        unordered_map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        return func(0,in.size()-1,in,0,ps.size()-1,ps,mp);
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