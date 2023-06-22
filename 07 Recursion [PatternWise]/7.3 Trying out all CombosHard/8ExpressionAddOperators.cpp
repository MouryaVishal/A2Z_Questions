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

int func(string str){
    int i=0;
    int ans=0;
    int n=str.size();
    while(i<n && isdigit(str[i])){
        ans=ans*10+(str[i]-'0');
        i++;
    }
    cout<<ans<<endl;
    int prev=ans;
    int sign=1;

    while(i<n){
        if(str[i]=='*'){
            i++;
            int curr=0;
            while(i<n && isdigit(str[i])){
                curr=curr*10+(str[i]-'0');
                i++;
            }
            int temp=ans;
            ans=ans-(prev*sign)+(curr*sign*prev);
            prev=ans;
        }else{
            char t=str[i];
            i++;
            int curr=0;
            while(i<n && isdigit(str[i])){
                curr=curr*10+(str[i]-'0');
                i++;
            }
            if(t=='+'){
                ans+=curr;
                sign=1;
            }else{
                sign=-1;
                ans-=curr;
            }
        }
    }

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
    cout<<func("1*2*3");
}