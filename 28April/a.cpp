#include<bits/stdc++.h>

#define int               long long
#define mod               1000000007
#define inf               1e18
#define pq                priority_queue
#define pqi               priority_queue<int>
#define pb                push_back
#define sz(v)             ((int)(v).size())
#define all(v)            (v).begin(),(v).end()
#define ss                second
#define ff                first
#define fr(i,num)         for(int i=0;i<num;i++)
 
using namespace std;
using ld = long double;


int32_t main(){
    int _testCase;
    cin>>_testCase;
    while(_testCase--){
        int num;
        cin>>num;
        string _str;
        cin>>_str;
        int sa=0;
        int sb=0;
        if(_str[0]=='A') sa++;
        stack<char> st;
        st.push(_str[0]);
        for(int i=1;i<num;i++){
            if(_str[i]==st.top()){
                if(st.top()=='A')sa++;
                else sb++;
            }else{
                st.pop();
                st.push(_str[i]);
            }
        }

        cout<<sa<<" "<<sb<<endl;

        
    }
  return 0;
}