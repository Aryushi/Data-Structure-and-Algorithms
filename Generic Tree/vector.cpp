#include<iostream>
#include<vector>

using namespace std;
int main()
{
    vector<int> v;
    vector<int> *vp = new vector<int> ();

    v.push_back(10);
    v.push_back(20);
    v.push_back(27);

     cout<<v[0]<<endl;

     return 0;
} 

