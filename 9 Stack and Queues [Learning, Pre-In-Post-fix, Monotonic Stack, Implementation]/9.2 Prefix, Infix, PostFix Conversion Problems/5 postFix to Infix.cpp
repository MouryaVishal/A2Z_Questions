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
bool charater(char ch){
    return (ch>='a' && ch<='z')|| (ch>='A' && ch<='Z');
}
string postToInfix(string postfix) {

    // Write your code here.
    stack<string> st;
    for(auto a:postfix){
        if(charater(a)){
            string ch(1,a);
            st.push(ch);
        }else{
            string sec=st.top();
            st.pop();
            string first=st.top();
            st.pop();
            string t="("+first+a+sec+")";
            st.push(t);
        }
    }

    return st.top();

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