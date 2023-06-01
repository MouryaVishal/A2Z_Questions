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
class Solution
{
    long long func(string &s,int k){
        vector<int> mp(26,0);
        int i=0;
        int j(0);
        int dist=0;
        long long ans=0;
        while(j<s.size()){
            mp[s[j]-'a']++;
            if(mp[s[j]-'a']==1)dist++;
            // if(dist>k){
            //     int strlength=j-i;
            //     ans+=(long long)(strlength*(strlength+1))/2;
                while(dist>k){
                    mp[s[i]-'a']--;
                    if(mp[s[i]-'a']==0){
                        dist--;
                    }
                    i++;
                }
            // }
            ans+=(j-i+1);
            j++;
        }
        // cout<<ans<<endl;
        return ans;
        
    }
  public:
    long long int substrCount (string s, int k) {
    	return func(s,k)-func(s,k-1);
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