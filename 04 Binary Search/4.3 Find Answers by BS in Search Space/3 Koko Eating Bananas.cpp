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
    bool condition(int m,vector<int>&p,int&h){
        long long count=0;
        for(auto&a:p){
            count+=(long long)a/m+(long long)(a%m?1:0);
        }
        return count<=(long long)h;
    }
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int st=1;
        int end=*max_element(p.begin(),p.end());
        int ans=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(condition(mid,p,h)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
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