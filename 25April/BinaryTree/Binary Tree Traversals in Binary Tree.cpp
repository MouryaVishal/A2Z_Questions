#include<bits/stdc++.h>
using namespace std;

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
void func(Node*root,vector<int>&ans){
    if(!root)return;
    ans.push_back(root->data);
    func(root->left,ans);
    func(root->right,ans);
}
vector <int> preorder(Node* root)
{
    vector<int> ans;
    func(root,ans);
    return ans;
}
