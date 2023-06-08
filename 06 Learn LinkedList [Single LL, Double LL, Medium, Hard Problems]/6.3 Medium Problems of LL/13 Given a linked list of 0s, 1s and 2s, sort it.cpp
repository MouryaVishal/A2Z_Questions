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
   struct Node *next;
    Node(int x) {
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
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int z(0),o(0),t(0);
        Node*temp=head;
        while(temp){
            if(temp->data==0)z++;
            if(temp->data==1)o++;
            if(temp->data==2)t++;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(z){
                temp->data=0;
                z--;
            }else if(o){
                temp->data=1;
                o--;
            }else{
                temp->data=2;
                t--;
            }
            temp=temp->next;
        }
        
        return head;
        
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