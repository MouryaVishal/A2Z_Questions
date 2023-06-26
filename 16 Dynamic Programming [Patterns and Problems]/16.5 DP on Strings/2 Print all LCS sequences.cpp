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
    Node* prev;
    int data;
    Node* next;
    Node()
    { 
    prev = NULL;
    data = 0;
    next = NULL;
    }
    
    Node(int value)
    {
    prev = NULL;
    data = value;
    next = NULL;
    }
  };
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)


// !Solution 
class Solution
{
    set<string> st;
    int solTab(string &t1,string &t2){
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans=0;
                if(t1[i]==t2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }


        return dp[0][0];
    }
    void solRec(int i,int j,int len,string temp,string &s, string &t,vector<string>&ans){
        if(len==0){
            if(!st.count(temp)){
                ans.push_back(temp);
                st.insert(temp);
            }
            return ;
        }
        if(i>=s.size() || j>=t.size())return;
        for(int r=i;r<s.size();r++){
            for(int x=j;x<t.size();x++){
                if(s[r]==t[x]){
                    temp.push_back(s[r]);
                    solRec(r+1,x+1,len-1,temp,s,t,ans);
                    temp.pop_back();
                }
            }
        }
    }
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    vector<string>ans;
		    int len=solTab(s,t);
		  //  cout<<len<<endl;
		    solRec(0,0,len,"",s,t,ans);
		    // Code here
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
// !Solution 
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}