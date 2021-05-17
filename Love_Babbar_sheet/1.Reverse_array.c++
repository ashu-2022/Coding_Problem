// Wap to reverse the array
#include <bits/stdc++.h>
using namespace std;
vector<int>swap_array(vector<int>& v){
    int i=0;
    int j=v.size()-1;
    //reverse(v.begin(), v.end());
    while(i<j){
        swap(v[i],v[j]);
        i++;
        j--;
    }
    return v;
}
int main()
{
    vector<int>v {1,2,3,4,5};
    swap_array(v);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}

// Output : 5 4 3 2 1 
// Time Complexity : O(n)
// Space Complexity : O(n)
