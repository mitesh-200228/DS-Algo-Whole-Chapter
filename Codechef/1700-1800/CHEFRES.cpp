#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<pair<int,int>> intervals;
	    while(n--){
	        int start,end;
	        cin>>start>>end;
	        intervals.push_back(make_pair(start,end));
	    }
	    sort(intervals.begin(),intervals.end());
	    while(m--){
	        int curr;
	        cin>>curr;
	        int position = lower_bound(intervals.begin(),intervals.end(),make_pair(curr,0)) - intervals.begin();
	        if(position==0){
	            int ans = intervals[0].first - curr;
	            cout<<ans<<endl;
	        }
	        else{
	            int ans=-1;
	            if(intervals[position-1].second > curr){
	                ans = 0;
	            }
	            else if(position<intervals.size()){
	                ans = intervals[position].first - curr;
	            }
	            cout<<ans<<endl;
	        }
	    }
	}
	return 0;
}
