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
    Node* prev;
    int data;
    Node* next;
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
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode*merge(ListNode*left,ListNode*right){
        ListNode*dummy=new ListNode(0);
        ListNode*curr=dummy;
        while(left && right){
            if(left->val<=right->val){
                curr->next=left;
                left=left->next;
            }else{
                curr->next=right;
                right=right->next;
            }
            curr=curr->next;
        }
        while(left){
            curr->next=left;
            left=left->next;
            curr=curr->next;
        }
        while(right){
            curr->next=right;
            right=right->next;
            curr=curr->next;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode*prev=head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        if(prev)prev->next=NULL;
        ListNode*left=sortList(head);
        ListNode*right=sortList(slow);
        return merge(left,right);
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