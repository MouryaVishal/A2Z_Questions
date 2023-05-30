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
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;   
        int i = 0;     
        int n = s.size(); 

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            while (i < n && s[i] != ' ')
                s[end++] = s[i++];

            if (start < end) {
                reverse(s.begin() + start, s.begin() + end);
                s[end++] = ' ';
                start = end;
            }
            i++;
        }
        if (end > 0)
            s.resize(end - 1);

        return s;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        vector<string> temp;
        stringstream str(s);
        string word;
        int count=0;
        while(str>>word){
            temp.push_back(word);
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(i==0){
                ans+=temp[i];
                continue;
            }
            ans+=temp[i]+" ";

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