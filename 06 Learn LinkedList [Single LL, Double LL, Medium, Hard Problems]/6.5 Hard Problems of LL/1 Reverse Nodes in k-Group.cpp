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
    Node *prev;
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
#define fr(i, num) for (int i = 0; i < num; i++)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode*temp=curr->next;
            curr->next=dummy;
            dummy=curr;
            curr=temp;
        }
        return dummy;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        int count=0;
        ListNode*temp=head;
        while(temp && count!=k-1){
            count++;
            temp=temp->next;
        }
        if(!temp){
            return head;
        }
        ListNode*node=temp->next;
        temp->next=NULL;

        ListNode*ns=reverseList(head);
        // ListNode*startingNode=ns;

        // while(ns && ns->next){
        //     ns=ns->next;
        // }
        head->next=reverseKGroup(node,k);
        return ns;
    }
};


int main()
{
    int num;
    cout << "Enter number of element in an array:- ";
    cin >> num;
    vector<int> vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}