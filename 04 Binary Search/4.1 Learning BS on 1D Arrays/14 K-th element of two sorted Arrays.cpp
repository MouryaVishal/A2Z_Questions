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



class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int st=0;
        int end=INT_MAX;
        while(st<=end){
            int mid=st+(end-st)/2;
            int nE=upper_bound(arr1,arr1+n,mid)-arr1;
            int mE=upper_bound(arr2,arr2+m,mid)-arr2;
            if(nE+mE<k)st=mid+1;
            else end=mid-1;
        }
        
        return st;
        
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