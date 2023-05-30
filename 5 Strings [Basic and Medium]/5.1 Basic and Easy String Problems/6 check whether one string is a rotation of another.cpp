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
    bool rotateString(string s, string g) {
        if(s.size()!=g.size())return false;
        int i=0;
        int j=0;
        while(i<g.size()){
            if(s[i]==g[j]){
                j++,i++;
            }else{
                i++;
            }
        }
        if(i==g.size() && i==j)return true;
        i=0;
        while(j<s.size()){
            if(s[i]==g[j]){
                i++,j++;
            }else{
                return false;
            }
        }

        return true;
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