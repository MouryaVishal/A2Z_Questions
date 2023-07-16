//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans="";
        unordered_map<char,int> mp;
        mp['^']=5;
        mp['*']=4;
        mp['/']=4;
        mp['-']=3;
        mp['+']=3;
        stack<char> st;
        for(auto a:s){
            if(a!='+' && a!='*' && a!='-' && a!='/' && a!=')' && a!='(' && a!='^'){
                ans+=a;
            }else if(a=='('){
                st.push(a);
            }else if(a==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && mp[st.top()]>=mp[a]){
                    ans+=st.top();
                    st.pop();
                }
                st.push(a);
            }
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends