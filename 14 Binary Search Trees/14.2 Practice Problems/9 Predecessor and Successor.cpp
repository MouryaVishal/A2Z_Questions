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
   int key;
   Node* left, * right;
};
#define fr(i,num) for(int i=0;i<num;i++)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{ 
    pre=NULL;
    suc=NULL;
    if(root!=NULL){
        Node* temp=root;
        while(temp!=NULL){
            if(key>=temp->key){
                temp=temp->right;
            }else{
                suc=temp;
                temp=temp->left;
            }
        }
        Node* temp1=root;
        while(temp1!=NULL){
            if(key<=temp1->key){
                temp1=temp1->left;
            }else{
                pre=temp1;
                temp1=temp1->right;
            }
        }
    }
    

}


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