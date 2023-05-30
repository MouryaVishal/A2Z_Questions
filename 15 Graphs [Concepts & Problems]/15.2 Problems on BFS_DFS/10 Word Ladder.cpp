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
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string> st;
        bool flag=0;
        queue<string> q;

        for(auto&a:w){
            if(a.compare(e)==0)flag=1;
            st.insert(a);
        }

        if(!flag)return 0;
        q.push(b);
        int count=0;
        while(!q.empty()){
            int s=q.size();
            count++;
            while(s--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(temp.compare(curr)==0)continue;
                        if(temp.compare(e)==0)return count+1;
                        if(st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};



class Solution {
    bool possible(string&s1,string&s2){
        int count=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])count++;
        }
        return count==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        unordered_map<string,vector<string>> adj;
        bool flag=false;
        for(int i=0;i<w.size();i++){
            if(w[i]==endWord)flag=1;
            if(possible(beginWord,w[i])){
                adj[w[i]].push_back(beginWord);
                adj[beginWord].push_back(w[i]);
            }
            for(int j=i+1;j<w.size();j++){
                if(possible(w[i],w[j])){
                    // cout<<w[i]<<" "<<w[j]<<endl;
                    adj[w[i]].push_back(w[j]);
                    adj[w[j]].push_back(w[i]);
                }
            }
        }
        if(!flag)return flag;
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
        q.push({0,beginWord});
        unordered_map<string,bool> vis;
        vis[beginWord]=true;
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            if(a.second==endWord)return a.first+1;
            for(auto&ng:adj[a.second]){
                if(!vis[ng]){
                    q.push({a.first+1,ng});
                    vis[ng]=true;
                }
            }
        }
        return 0;
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