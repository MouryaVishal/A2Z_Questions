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
    int median(vector<vector<int>> &m, int r, int c){
        int st=1;
        int end=2005;
        int req=(r*c)/2;
        while(st<=end){
            int mid=st+(end-st)/2;
            int curr=0;
            for(int i=0;i<r;i++){
                int temp=upper_bound(m[i].begin(),m[i].end(),mid)-m[i].begin();
                curr+=temp;
            }
            
            if(curr<=req){
                st=mid+1;
            }else{
                end=mid-1;
            }
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