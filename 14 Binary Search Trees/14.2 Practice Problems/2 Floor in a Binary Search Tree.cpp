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

int floor(Node* root1, int tr) {
    if(!root1)return -1;
    Node*root=root1;
    int ans=-1;
    while(root){
        if(root->data==tr){
            ans=root->data;
            return ans;
        }
        if(root->data<tr){
            ans=root->data;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    
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