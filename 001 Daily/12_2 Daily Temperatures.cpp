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
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<pair<int,int>> st;
        int n=t.size();
        vector<int> ans(n,0);
        st.push_back({t[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            if(st.back().first>t[i]){
                ans[i]=st.back().second-i;
            }else{
                while(st.size()>0 && st.back().first<=t[i]){
                    st.pop_back();
                }
                if(st.size()!=0){
                    ans[i]=st.back().second-i;
                }
            }
            st.push_back({t[i],i});
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