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
class Solution{
    vector<bool> sieve;
    void findPrime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(sieve[i]){
                for(int j=i*i;j<=n;j=j+i){
                    sieve[j]=false;
                }
            }
        }
    }
    
	public:
	vector<int>AllPrimeFactors(int n) {
	    sieve.resize(n+1,true);
	    findPrime(n);
	    vector<int> ans;
	    for(int i=2;i<=n;i++){
	        if(n%i==0 && sieve[i]){
	            ans.push_back(i);
	        }
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