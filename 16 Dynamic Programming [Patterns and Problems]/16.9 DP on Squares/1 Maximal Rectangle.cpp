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
class Solution {
    int largestRectangleArea(vector<int>& h) {
        vector<int>prev;
        int n=h.size();
        int ans=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty()&& (i==n || h[st.top()]>=h[i])){
                int ht=h[st.top()];
                st.pop();
                int w=i;
                if(!st.empty()){
                    w=w-st.top()-1;
                }
                // cout<<ht<<" "<<w<<endl;
                ans=max(ans,ht*w);
            }
            st.push(i);
        }
        return ans;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& mt) {
        int ans=0;
        int n=mt.size();
        int m=mt[0].size();
        vector<int> temp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mt[i][j]=='1'){
                    temp[j]+=1;
                }else{
                    temp[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(temp));
        }
        return ans;
        
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