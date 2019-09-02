#include <iostream>
#include <algorithm>
using namespace std;
void display(char a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main ()
{
    int num, i, N;
    cout<<"Enter number of elements to be inserted: ";
    cin>>num>>N;
    char myints[num];
    for (i = 0; i < num; i++)
    {
        cout<<"Enter "<<i + 1<<" element: ";
        cin>>myints[i];
    }
    sort (myints, myints + num);
    cout << "The "<<num<<"! possible permutations with ";
    cout<<num<<" elements: "<<endl;
    do
    {
        display(myints, num);
    }
    while (next_permutation(myints, myints + N));
    return 0;
}
