#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node
{
    int data;
    Node *left, *right;
    Node *prev,*bottom;
    int data;
    Node *next;
    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
Node* merge(Node *left,Node *right){
    Node*dummy=new Node(9);
    Node*start=dummy;
    while(left && right){
        if(left->data<=right->data){
            dummy->bottom =left;
            left=left->bottom ;
        }else{
            dummy->bottom =right;
            right=right->bottom;
        }
        dummy=dummy->bottom;
    }
    while(left){
        dummy->bottom=left;
        left=left->bottom ;
        dummy=dummy->bottom ;
    }
    while(right){
        dummy->bottom=right;
        right=right->bottom;
        dummy=dummy->bottom;
    }
    return start->bottom;
    
}

Node *flatten(Node *root)
{
    if(!root || !root->next)return root;
    // cout<<root->data<<endl;
    return merge(root,flatten(root->next));
   // Your code here
}

#define fr(i, num) for (int i = 0; i < num; i++)
int main()
{
    int num;
    cout << "Enter number of element in an array:- ";
    cin >> num;
    vector<int> vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    // Solution obj;
}