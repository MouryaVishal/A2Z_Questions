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
    vector<vector<string>> findSequences(string b, string e, vector<string>& wl) {
        
        unordered_set<string> st(wl.begin(),wl.end());
        queue<vector<string>> q;
        q.push({b});
        int level=0;
        vector<string> del;
        del.push_back(b);
        vector<vector<string>> ans;
        
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            if(a.size()>level){
                level++;
                for(auto&ng:del){
                    st.erase(ng);
                }
                del.clear();
            }
            
            string word=a.back();
            if(word==e){
                if(ans.size()==0){
                    ans.push_back(a);
                }else if(ans[0].size()==a.size()){
                    ans.push_back(a);
                }
                continue;
            }
            
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        a.push_back(word);
                        q.push(a);
                        del.push_back(word);
                        a.pop_back();
                    }
                }
                word[i]=original;
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