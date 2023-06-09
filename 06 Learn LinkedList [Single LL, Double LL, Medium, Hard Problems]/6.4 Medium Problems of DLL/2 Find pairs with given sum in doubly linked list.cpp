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

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        if(!head ||!head->next)return{};
        Node*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        Node*st=head;
        vector<pair<int,int>> ans;
        while(st->data<temp->data){
            int sum=st->data+temp->data;
            if(sum==target){
                ans.push_back({st->data,temp->data});
                st=st->next;
                temp=temp->prev;
            }else if(sum<target){
                st=st->next;
            }else{
                temp=temp->prev;
            }
        }
        
        return ans;
//         31
// 32
// 1 4 5 6 10 11 12 13 14 15 19 20 21 22 25 26 27 31 33 35 36 37 38 39 40 41 42 43 44 47 48 49
//         (4,27) (5,26) (6,25) (10,21) (11,20) (12,19)
        // code here
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