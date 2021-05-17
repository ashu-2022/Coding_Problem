// Wap to print min and max element of array
#include <bits/stdc++.h>
using namespace std;
pair<int,int>max_min(vector<int>v){
    pair<int,int> pi;
    // pi.first=*min_element(v.begin(),v.end());
    // pi.second=*max_element(v.begin(),v.end());
    int min=v[0],max=v[0];
    for(int i=1;i<v.size();i++){
        if (v[i]>max){
            max=v[i];
        }
        if (v[i]<min){
            min=v[i];
        }
    }
    pi.first=min;
    pi.second=max;
    return pi;
}
int main() {
	vector<int> v {1,2,3,4,5,6,7,8,9};
	pair<int,int>pi=max_min(v);
	cout<<"min_element : "<< pi.first<<endl;
	cout<<"max_element : "<< pi.second<<endl;
	return 0;
}

// Output :
// min_element : 1
// max_element : 9

// Time Complexity: O(n)
// Space Complexity: O(1)
