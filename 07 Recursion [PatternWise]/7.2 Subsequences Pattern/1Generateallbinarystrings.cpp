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

class Solution{
    public:
    void solve(int &num,vector<string>&temp,string curr){
        if(curr.size()==num){
            temp.push_back(curr);
            return;
        }
        if(curr.size()==0){
            solve(num,temp,curr+'1');
            solve(num,temp,curr+'0');
        }else{
            if(curr[curr.size()-1]=='1'){
                solve(num,temp,curr+'0');
            }else{
                solve(num,temp,curr+'1');
                solve(num,temp,curr+'0');
            }
        }
    }
    vector<string> func(int num){
        vector<string> temp;
         solve(num,temp,"");
         return temp;
    }
};


int main(){
    int num;
    cout<<"Enter number ";
    cin>>num;
    Solution obj;
    vector<string> ans=obj.func(num);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}