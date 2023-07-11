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
struct Node{
    Node*links[26];
    bool flag=false;

    bool containKey(char ch){
        return links[ch-'a'];
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
    bool istrue(){
        return flag;
    }
};
class Trie {
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getRef(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->getRef(word[i]);
        }

        return node->istrue();
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node=node->getRef(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
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