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


class MinStack {
    vector<int> st;
    int min_element=INT_MAX;
public:
    MinStack() {    
    }
    
    void push(int val) {
        if(min_element>=val){
            st.push_back(min_element);
            min_element=val;
        }
        st.push_back(val);
    }
    
    void pop() {
        if(min_element==st.back()){
            st.pop_back();
            min_element=st.back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();  
    }
    
    int getMin() {
        return min_element;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    // Solution obj;
}