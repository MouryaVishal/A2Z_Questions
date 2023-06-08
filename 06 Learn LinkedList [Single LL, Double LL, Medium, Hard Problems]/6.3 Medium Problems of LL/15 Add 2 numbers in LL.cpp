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
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
    int getcount( ListNode* head){
        int count=0;
        ListNode*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void print(ListNode*l){
        while(l){
            cout<<l->val<<" ";
            l=l->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=getcount(l1);
        int n=getcount(l2);
        if(n>n1){
            ListNode* node=l2;
            l2=l1;
            l1=node;
        }

        // print(l1);
        int carry=0;
        int n2=getcount(l2);
        // cout<<n2<<endl;
        ListNode* prev=NULL;
        ListNode*start=l1;
        while(n2--){
            int s=l1->val+l2->val+(carry?1:0);
            l1->val=s%10;
            carry=s/10;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int t=l1->val+(carry?1:0);
            l1->val=t%10;
            carry=t/10;
            prev=l1;
            l1=l1->next;
        }
        if(carry){
            prev->next=new ListNode(1);
        }
        return start;
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