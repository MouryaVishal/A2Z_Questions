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
#include <bits/stdc++.h> 
struct Node{
    Node*links[26];
    bool flag=false;

    bool containkey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node* getRef(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie{
    Node*root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string &st){
        Node*node=root;
        for(int i=0;i<st.size();i++){
            if(!node->containkey(st[i])){
                node->put(st[i],new Node());
            }
            node=node->getRef(st[i]);
        }
        node->setEnd();
    }

    bool isCompletePrefixWord(string&st){
        Node*node=root;
        for(int i=0;i<st.size();i++){
            node=node->getRef(st[i]);
            if(!node->getEnd())return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie obj;
    for(auto w:a){
        obj.insert(w);
    }
    string ans="";
    for(auto w:a){
        if(obj.isCompletePrefixWord(w)){
            if(ans.size()<w.size()){
                ans=w;
            }else if(ans.size()==w.size() && ans>w){
                ans=w;
            }
        }
    }

    if(ans=="")return "None";

    return ans;
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