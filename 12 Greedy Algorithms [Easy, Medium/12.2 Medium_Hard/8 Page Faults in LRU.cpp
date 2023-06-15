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
    int pageFaults(int n, int c, int p[]){
        // code here
        unordered_set<int> st;
        int h=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.count(p[i])){
                h++;
                continue;
            }
            int cnt=0;
            int k=i-1;
            if(st.size()==c){
                unordered_set<int> vis;
                while(cnt!=c){
                    if(!vis.count(p[k])){
                        cnt++;
                        vis.insert(p[k]);
                    }
                    k--;
                }
                st.erase(p[k+1]);
            }
            st.insert(p[i]);
        }
        
        return n-h;
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