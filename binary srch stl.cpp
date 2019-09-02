#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
    int A[] = {15,12,19,16,13,17,18,14,11,10};
    vector <int> v(A, A + 10);
    sort (v.begin(), v.end());
    vector <int>::iterator it;
    if(binary_search(v.begin(), v.end(), 14))
        cout << "14 is in the array" << endl;
    else
        cout << "14 is not in the array" << endl;
    it = lower_bound(v.begin(), v.end(), 14);
    cout << "lower_bound: " << (it - v.begin()) << endl;
    it = upper_bound(v.begin(), v.end(), 14);
    cout << "upper_bound: " << (it - v.begin()) << endl;

    pair < vector <int>::iterator, vector <int>::iterator > p;
    p = equal_range(v.begin(), v.end(), 14);
    cout << "equal_range First: " << (p.first - v.begin()) << endl;
    cout << "equal_range Second: " << (p.second - v.begin()) << endl;
    return 0;
}
