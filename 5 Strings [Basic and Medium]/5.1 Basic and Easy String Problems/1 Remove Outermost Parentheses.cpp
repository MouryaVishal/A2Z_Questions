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
#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int c=0;
        for(auto&a:s){
            if(a=='(' && c==0){
                c++;
            }else if(a=='(' && c>=1){
                ans+=a;
                c++;
            }else if(a==')' && c>1){
                ans+=a;
                c--;
            }else if(a==')' && c==1){
                c--;;
            }
        }

        return ans;
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