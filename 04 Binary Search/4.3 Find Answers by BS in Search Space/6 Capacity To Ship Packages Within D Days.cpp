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
    bool possible(int mid,vector<int>& w, int d){
        int days=0;
        int i=0;
        while(i<w.size()){
            int curr=0;
            while(i<w.size() && curr+w[i]<=mid){
                curr+=w[i];
                i++;
            }
            days++;

            

        }
        // cout<<mid<<" "<<days<<endl;
        return days<=d;
    }
public:
    int shipWithinDays(vector<int>& w, int d) {
        // sort(begin(w),end(w));
        int st=*max_element(begin(w),end(w));
        int end=accumulate(begin(w),w.end(),0);
        int ans=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(possible(mid,w,d)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
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