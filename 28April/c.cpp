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
        string _str;
        cin>>_str;
        string temp=_str;
        if(temp[0]=='?'){
            temp[0]='0';
        }
        int _num=_str.size();
        for(int i=1;i<_num;i++){
            if(_str[i]=='?'){
                temp[i]=temp[i-1];
            }
        }
        cout<<temp<<endl;
        
    }
  return 0;
}