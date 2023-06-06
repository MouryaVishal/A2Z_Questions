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
struct Node {
  int val;
  Node *next;
   Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)

int countNodesinLoop(struct Node *head)
{
    Node*slow=head;
    Node*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            break;
        }
    }
    
    if(!fast || !fast->next)return 0;
    
    fast=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    
    fast=fast->next;
    
    int count=1;
    while(fast!=slow){
        count++;
        fast=fast->next;
    }
    return count;
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