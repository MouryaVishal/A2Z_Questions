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
    bool possible(int m,int k,vector<int>&s){
        int c=1;
        int prev=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]-prev>=m){
                // cout<<prev<<" "<<s[i]<<endl;
                c++;
                prev=s[i];
            }
        }
        return c>=k;
    }
public:

    int solve(int n, int k, vector<int> &s) {
        sort(begin(s),end(s));
        int st=0;
        int end=*max_element(s.begin(),s.end());
        int ans=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(mid,k,s)){
                // cout<<"s"<<mid<<endl;
                ans=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return ans;
        // Write your code here
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