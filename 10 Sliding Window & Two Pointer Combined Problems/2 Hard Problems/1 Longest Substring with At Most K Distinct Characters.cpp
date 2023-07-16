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
int kDistinctChars(int k, string &str)
{
    int j=0;
    int i=0;
    int ans=0;
    unordered_map<char,int> mp;
    while(j<str.size()){
        mp[str[j]]++;
        if(mp.size()>k){
            ans=max(ans,j-i);
            while(mp.size()>k){
                mp[str[i]]--;
                if(mp[str[i]]==0){
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        ans=max(ans,j-i+1);
        j++;
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
}