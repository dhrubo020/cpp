#include<bits/stdc++.h>
using namespace std;


int CeilIndex(std::vector<int> &v, int l, int r, int key)  //tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
{

    while (r-l > 1) {
          //  cout <<l << " " << r<< " " << key <<endl;
          //  cout << r-l <<endl;
        int m = l + (r-l)/2;
   // cout <<"v["<<m<<"]"<< endl;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int> &v)
{
    if (v.size() == 0)
        return 0;
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
           // cout << "step " <<i<<" " << v[i] <<  " " << tail[length - 1] << endl;
        if (v[i] < tail[0])
        // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1]){
               // cout << "tail[" <<length<<"]="<<v[i]<<endl;
        // v[i] extends largest subsequence
            tail[length++] = v[i];

        }
        else{
                //cout<<"else  tail[" <<CeilIndex(tail, -1, length-1, v[i])<<" " <<endl;
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
        // v[i] will become end candidate of an existing subsequence or
        // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
        // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
        }

    }
    cout<<length<<endl<<"-"<<endl;
    for(int i=0; i<length; i++){
        cout<<tail[i]<<endl;
    }
}

int main()
{
    std::vector<int> v;
    int x;
    while(cin >> x){
        v.push_back(x);
    }
    //std::cout << "Length of Longest Increasing Subsequence is " << << '\n';
     LongestIncreasingSubsequenceLength(v);
    return 0;
}
