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
    int cw=0;
    int cp=0;
    
    bool containKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node*getRef(char ch){
        return links[ch-'a'];
    }
    void incWord(){
        cw++;
    }
    void incPrefix(){
        cp++;
    }
    void decWord(){
        cw--;
    }
    void decPrefix(){
        cp--;
    }

    int getWord(){
        return cw;
    }
    int getPrefix(){
        return cp;
    }
    
};
class Trie{
    Node*root;
    public:

    Trie(){
        root=new Node();
        // Write your code here.
    }

    void insert(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
          if (!node->containKey(word[i])) {
            node->put(word[i], new Node());
          }
          node = node->getRef(word[i]);
          node->incPrefix();
        }
        node->incWord();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
          if (!node->containKey(word[i])) {
            return 0;
          }
          node = node->getRef(word[i]);
        }
        return node->getWord();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
          if (!node->containKey(word[i])) {
            return 0;
          }
          node = node->getRef(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
          if (!node->containKey(word[i])) {
            return;
          }
          node = node->getRef(word[i]);
          node->decPrefix();
        }
        node->decWord();
    }
};

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