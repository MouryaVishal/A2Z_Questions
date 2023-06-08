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
   Node* next;
   Node(int x){
        data = x;
        next = NULL;
    }
};
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)
class Solution
{
    public:
    Node*reverse(Node*head){
        Node*dummy=NULL;
        Node*temp=head;
        while(temp){
            Node*node=temp->next;
            temp->next=dummy;
            dummy=temp;
            temp=node;
        }
        return dummy;
    }
    Node* addOne(Node *head) 
    {
        Node*l1=reverse(head);
        Node*start=l1;
        int carry=1;
        Node*prev=l1;
        while(l1){
            int t=l1->data+(carry?1:0);
            l1->data=t%10;
            carry=t/10;
            prev=l1;
            l1=l1->next;
        }
        if(carry){
            prev->next=new Node(1);
        }
        
        return reverse(start);
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