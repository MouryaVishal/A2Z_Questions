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
    bool searchMatrix(vector<vector<int>>& m, int tr) {
        int i=0;
        int j=m[0].size()-1;
        while(i<m.size() && j>=0){
            if(m[i][j]==tr)return true;
            if(m[i][j]<tr){
                i++;
            }else{
                j--;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int tr) {
        int i=0;
        int j=m.size()*m[0].size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(m[mid/m[0].size()][mid%m[0].size()]==tr)return true;
            if(m[mid/m[0].size()][mid%m[0].size()]<tr){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return false;
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