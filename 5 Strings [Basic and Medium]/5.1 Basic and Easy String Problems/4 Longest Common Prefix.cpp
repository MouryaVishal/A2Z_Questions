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
    string longestCommonPrefix(vector<string>& strs) {
        int len=INT_MAX;
        for(auto&a:strs){
            int temp=a.size();
            len=min(len,temp);
        }
        int j=0;
        for(;j<len;j++){
            int flag=0;
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i][j]!=strs[i+1][j]){
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
        cout<<j<<endl;
        return strs[0].substr(0,j);
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