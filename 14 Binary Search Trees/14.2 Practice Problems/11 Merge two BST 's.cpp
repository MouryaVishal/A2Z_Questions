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

class BSTIlerator{
    stack<Node*> st;
    void pushNode(Node*root){
        for(;root!=NULL;root=root->left){
            st.push(root);
        }
    }
    public:
        BSTIlerator(Node*root){
            pushNode(root);
        }
        bool hasNext(){
            return st.size()!=0;
        }
        
        int next(){
            Node*t=st.top();
            st.pop();
            pushNode(t->right);
            return t->data;
        }
        int comp(){
            return st.top()->data;
        }
};
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        BSTIlerator r1(root1);
        BSTIlerator r2(root2);
        while(r1.hasNext() && r2.hasNext()){
            // cout<<r1.next()<<" "<<r2.next()<<endl;
            if(r1.comp()<r2.comp()){
                ans.push_back(r1.next());
            }else{
                ans.push_back(r2.next());
            }
        }
        
        while(r1.hasNext()){
                ans.push_back(r1.next());
        }
         while(r2.hasNext()){
                ans.push_back(r2.next());
        }
        
        return ans;
       //Your code here
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