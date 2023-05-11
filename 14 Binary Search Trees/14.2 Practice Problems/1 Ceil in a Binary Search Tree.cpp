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

int ans=-1;
void func(Node*root,int &tr){
    if(root==NULL)return ;
    
    if(root->data>=tr){
        ans=root->data;
    }
    if(root->data<tr){
        func(root->right,tr);
    }
    if(root->data>tr){
        func(root->left,tr);
    }
}
int findCeil(Node* root, int input) {
    func(root,input);
    return ans;
}


#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    // Solution obj;
}