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
    bool possible(int mid,vector<int>& b, int m, int k){
        int j=0;
        int count=0;
        while(j<b.size()){
            int curr=0;
            while(j<b.size() && b[j]<=mid && curr<k){
                curr++;
                j++;
            }
            if(curr==k){
                count++;
            }else{
                j++;
            }
        }
        return count>=m;
    }
public:
    int minDays(vector<int>& b, int m, int k) {
        if(b.size()<(long long)m*(long long)k)return -1;
        int st=1;
        int end=*max_element(begin(b),b.end());
        int ans=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(mid,b,m,k)){
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