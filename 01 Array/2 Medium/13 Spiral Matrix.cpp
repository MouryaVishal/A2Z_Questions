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
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        int rm(0),cm(0),r=m.size()-1,c=m[0].size()-1,total=m.size()*m[0].size();
        int count=0;
        while(count<total){
            for(int i=cm;i<=c && count<total;i++){
                count++;
                // cout<<m[rm][i]<<" ";
                ans.push_back(m[rm][i]);
            }
            rm++;
            // cout<<endl;
            for(int i=rm;i<=r && count<total;i++){
                count++;
                // cout<<m[i][c]<<" ";
                ans.push_back(m[i][c]);
            }
            c--;
            // cout<<endl;
            for(int i=c;i>=cm && count<total;i--){
                count++;
                // cout<<m[r][i]<<" ";
                ans.push_back(m[r][i]);
            }
            r--;
            // cout<<endl;
            for(int i=r;i>=rm && count<total;i--){
                count++;
                // cout<<m[i][cm]<<" ";
                ans.push_back(m[i][cm]);
            }
            // cout<<endl;
            cm++;
        }

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