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


// !Solution 
#include<bits/stdc++.h>

struct Node{
    Node*links[26];
    bool containKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node*getRef(char ch){
        return links[ch-'a'];
    }
};


int countDistinctSubstrings(string &s)
{

    int ans=0;
    Node*root=new Node();
    for(int i=0;i<s.size();i++){
        Node*node=root;
        for(int j=i;j<s.size();j++){
            if(!node->containKey(s[j])){
                ans++;
                node->put(s[j],new Node());
            }
            node=node->getRef(s[j]);
        }
    }

    return ans+1;
    //    Write your code here.
}
// !Solution 
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}