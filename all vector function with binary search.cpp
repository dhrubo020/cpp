#include<bits/stdc++.h>
using namespace std;
int main()
{
      vector<int>v4={3,7,8,11,13,76,2,34,23,45};
    v4.erase(v4.begin());
    for(int i=0;i<v4.size();i++)
        cout<<v4[i]<<" ";
    v4.erase(v4.begin()+3);
    for(int i=0;i<v4.size();i++)
        cout<<v4[i]<<" ";
    v4.erase(v4.begin(),v4.begin()+3);
    for(int i=0;i<v4.size();i++)
        cout<<v4[i]<<" ";
    cout<<endl;

    ///Initialize
    printf("Initialize\n");
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    /*vector<int>v1;
    for(int i=0;i<10;i++)
        v1.at(i)=i;
    //for(int i=0;i<v1.size();i++)
    for(auto i : v1)
        cout<<i<<" ";*/

    vector<int>v2;
    for(int i=0;i<3;i++)
    {
        int a;
        cin>>a;
        v2.push_back(a);
    }
    for(int i=0;i<v2.size();i++)
        cout<<v2[i]<<" ";
    cout<<endl;

    ///Assign

    vector<int>v3;
    v3.assign(5,10);
    for(int i=0;i<v3.size();i++)
        cout<<v3[i]<<" ";
    cout<<endl;
    for(auto i=v.rbegin();i!=v.rend();i++)
        cout<<*i<<" ";
    cout<<endl;

    cout<<"Size : "<<v.size()<<endl;

    cout<<"Max_Size : "<<v.max_size()<<endl;

    cout<<"Capacity : "<<v.capacity()<<endl;

   // v.clear();

    if(v.empty())
        printf("Empty\n");
    else
        printf("Not Empty\n");

    ///Resize

    v.resize(5);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    cout<<v.front()<<endl;
    v.pop_back();
    cout<<v.back()<<endl;



    int mx=*max_element(v4.begin(),v4.end());
    int mn=*min_element(v4.begin(),v4.end());

    cout<<"Max_element : "<<mx<<endl;
    cout<<"Min_element : "<<mn<<endl;

    int index=distance(v4.begin(),max_element(v4.begin(),v4.end()));   ///Complexity O(n)

    printf("Index of Max_Element : %d\n",index);
    //Swap

    vector<int>b(3,100);
    vector<int>c(5,200);
    b.swap(c);
    for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
    cout<<endl;

    ///Reverse

    vector<int>d={1,2,3,4,5};
    reverse(d.begin(),d.end());
    for(int i=0;i<d.size();i++)
        cout<<d[i]<<" ";
    cout<<endl;

    ///Emplace

    vector<int>e={10,20,30};

    e.emplace(e.begin()+1,100);
    e.emplace(e.end(),200);
    printf("Emplace :\n");
    for(int i=0;i<e.size();i++)
        cout<<e[i]<<" ";
    cout<<endl;

    ///Sort,Binary_Search

    vector<int>f={8,2,5,3,7,7,9,7};
    sort(f.begin(),f.end());

    printf("Sorted Element :\n");
    for(int i=0;i<f.size();i++)
        cout<<f[i]<<" ";
    cout<<endl;
    printf("Binary_Search\n");
    if(binary_search(f.begin(),f.end(),3))
        printf("Element found in vector\n");
    else
        printf("Element not found\n");

    int lb=lower_bound(f.begin(),f.end(),7)-f.begin();
    int up=upper_bound(f.begin(),f.end(),7)-f.begin();
    auto eq=equal_range(f.begin(),f.end(),7);

    printf("Upper Bound of 7 is %d\n",up);
    printf("Lower Bound of 7 is %d\n",lb);
    printf("7 appears in vector %d times\n",up-lb);
    cout<<*(eq.first)<<" "<<*(eq.second)<<endl;
}
