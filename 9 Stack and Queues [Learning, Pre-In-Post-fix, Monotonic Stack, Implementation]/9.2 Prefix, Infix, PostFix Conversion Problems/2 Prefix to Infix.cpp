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

string postFixtoInfix(string &s){
	stack<string> st;
	for(auto a:s){
		if(a>='a' && a<='z'){
			string ch(1,a);
			st.push(ch);
		}else{
			string sec=st.top();
			st.pop();
			string frt=st.top();
			st.pop();
			string t="("+sec+a+frt+")";
			st.push(t);
		}
	}

	return st.top();
}

string prefixToInfixConversion(string &s){
	// Write your code here.

	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]==')'){
			s[i]='(';
		}else if(s[i]=='(')
		{
			s[i]=')';
		}
	}

	return postFixtoInfix(s);
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