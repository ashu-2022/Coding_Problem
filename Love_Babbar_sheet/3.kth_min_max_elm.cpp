  // Wap to print kth min and max element of array
#include <bits/stdc++.h>
using namespace std;
pair<int,int>kth_min_max(vector<int>v, int k){
    pair<int,int> pi;
    sort(v.begin(),v.end());
    pi.first=v[k-1];
    pi.second=v[v.size()-k];
    return pi;

}
int main() {
	vector<int> v {1,2,3,5,4,7,9,8,6};
	int k=3;
	pair<int,int>pi=kth_min_max(v,k);
	cout<<"min_element : "<< pi.first<<endl;
	cout<<"max_element : "<< pi.second<<endl;
	return 0;
}

// Output :
// min_element : 3
// max_element : 7

// Time Complexity: O(nlogn)
// Space Complexity: O(1)  
