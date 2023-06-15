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

class Solution {
    int func(string &a,int i,int sign,int result){
        if(a.size()<=i || a[i]<'0' ||a[i]>'9'){
            // cout<<i<<endl;
            return result*sign;
        }
        // cout<<result<<" "<<i<<endl;
        int temp=a[i]-'0';
        if(result>INT_MAX/10 ||(result==INT_MAX/10 && temp>7)){
            return sign<0?INT_MIN:INT_MAX;
        }

        return func(a,i+1,sign,result*10+(long long)temp);
    }
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ')
            i++;
        
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+')i++;
        // cout<<i<<" "<<s.size()<<endl;

        return func(s,i,sign,0);
    }
};

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0,j=0;
        if(str[i]=='-')i++,j++;
        while(i<str.size()){
            if(!(str[i]>='0' && str[i]<='9'))return -1;
            i++;
        }
        int ans=0;
        while(j<str.size()){
            ans=ans*10+(str[j]-'0');
            j++;
        }
        
        return str[0]=='-'?-ans:ans;
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