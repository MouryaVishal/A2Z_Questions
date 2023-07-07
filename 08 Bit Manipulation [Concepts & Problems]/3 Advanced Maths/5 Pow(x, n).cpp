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
class Solution {
    double solve(double x,int n){
        if(n==0)return 1;
        // if(n==1)return x;
        double ans=1;
        if(n>0){
            if(n%2==0){
                return solve(x*x,n/2);
            }else{
                return x*solve(x*x,n/2);
            }
        }else{
            if(n%2==0){
                return solve((1/x)*(1/x),n/2*(-1));
            }else{
                return (1/x)*solve((1/x)*(1/x),n/2*(-1));
            }
        }
        return ans;
    }
public:
    double myPow(double x, int n) {
        // return solve(x,n);
        if(x==0|| x==1)return x; 

        double ans=1.0;
        while(n){
            if(n>0 && n%2){
                ans*=x;
            }
            if(n<0 && n%2){
                ans/=x;
            }

            x*=x;
            n/=2;
        }

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