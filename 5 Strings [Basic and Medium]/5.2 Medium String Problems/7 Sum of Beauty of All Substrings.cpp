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
public:
    int beautySum(string s) {
        int ans=0;
        vector<int> temp(26,0);
        for(int i=0;i<s.size();i++){
            string str="";
            for(int j=i;j<s.size();j++){
                // str+=s[i]
                temp[s[j]-'a']++;
                int maxi=0;
                int mini=600;
                for(auto&a:temp){
                    if(a!=0 && a<mini){
                        mini=a;
                    }
                    if(a!=0 && maxi<a){
                        maxi=a;
                    }
                }
                // cout<<maxi<<" "<<mini<<endl;
                ans+=(maxi-mini);
            }
            fill(temp.begin(), temp.end(), 0);
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