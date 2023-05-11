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
    int mySqrt(int x) {
        // if(x<2)return x;
        long long st=1;
        long long end=x;
        long long ans=0;
        while(st<=end){
            long long mid=st+(end-st)/2;
            if(mid*mid==(long long)x)return mid;
            if(mid*mid<(long long)x){
                ans=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }

        return  (int)ans;
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