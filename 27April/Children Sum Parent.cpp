#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to check whether all nodes of a tree have the dataue 
    //equal to the sum of their child nodes.
    int func(Node*root,int &temp){
        if(root==NULL)return 0;
        if(!root->left && !root->right){
            return root->data;
        }
        int left=func(root->left,temp);
        int right=func(root->right,temp);
        
        if(root->data!=left+right){
            temp=0;
        }
        return root->data;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     int temp=1;
     func(root,temp);
     return temp;
    }
};


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
