#include<bits/stdc++.h>

#define int               long long
#define mod               1000000007
#define inf               1e18
#define pq                priority_queue
#define pqi               priority_queue<int>
#define pb                push_back
#define sz(v)             ((int)(v)._len())
#define all(v)            (v).begin(),(v).end()
#define ss                second
#define ff                first
#define fr(i,num)         for(int i=0;i<num;i++)
 
using namespace std;
using ld = long double;

vector<int> indexNumber( vector<pair<int, int>>& _que, int _len) {
    vector<int> _ddaa(_len + 1, 0);

    for ( auto& _q : _que) {
        int _qqst = _q.first;
        int _qqend = _q.second;

        _ddaa[_qqst]++;
        _ddaa[_qqend + 1]--;
    }

    vector<int> _indNumber(_len, 0);
    int count = 0;

    for (int i = 0; i < _len; ++i) {
        count += _ddaa[i];
        _indNumber[i] = count;
    }

    return _indNumber;
}



int32_t main(){
    int _testCase;
    cin>>_testCase;
    while(_testCase--){
        int _num,_valq;
        cin>>_num>>_valq;
        vector<int> _vv;
        fr(i,_num){
            int x;
            cin>>x;
            _vv.push_back(x);
        }
        vector<pair<int,int>> q;

        for(int i=0;i<_valq;i++){
            int x,y;
            cin>>x>>y;
            q.push_back({x-1,y-1});
        }

        vector<int> _indNumber = indexNumber(q, _num);
        sort(begin(_vv),end(_vv),greater<int>());

        vector<pair<int,int>> ttarr;
        for(int i=0;i<_num;i++){
            ttarr.push_back({_indNumber[i],i});
        }

        sort(begin(ttarr),end(ttarr),greater<pair<int,int>>());

        int i=0;
        vector<int> ans(_num);

        int sum=0;
        for(auto&a:ttarr){
            sum+=(_vv[i]*a.first);
            ans[(a.second)]=_vv[i];

            i++;
        }



        cout<<sum<<endl;
        for(int i=0;i<_num;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    
        
    }
  return 0;
}