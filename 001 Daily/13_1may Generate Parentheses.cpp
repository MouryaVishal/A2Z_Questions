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
};

class Solution {
    void func(int s,int e,int t,int &n,string str,vector<string>&ans){
        if(s>n || t<0|| e>s) return;
        if(t==0){
            if(s==e){
                ans.push_back(str);
            }
            return;
        }
        func(s+1,e,t,n,str+"(",ans);
        func(s,e+1,t-1,n,str+")",ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0,0,n,n,"",ans);

        return ans;
    }
};


#define fr(i,num) for(int i=0;i<num;i++)
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