#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v;   //static
    vector<int> *vp = new vector<int> ();   //dynamic
    // initializing a vector
    vector<int> v2(10,-2);
    vector<int> v3(100);
for(int i=0;i<v2.size();i++){
    cout<<v2[i]<<" ";
}
cout<<endl;
    v.push_back(10);
    v.push_back(20);
    v.push_back(27);
    
    v[1] = 100;

    //  cout<<v[0]<<endl;
    //  cout<<v[1]<<endl;
    //  cout<<v[2]<<endl;
    // wrong never use square brackets to insert elements in a a vector
    v[3] =1002;
    v[4] =1234;
// .at gives out of range if entered index is greater than vector.size()(= no of elements in the vector)
    v.push_back(23);
    v.push_back(234);
    v.pop_back();
    cout<<"v.capacity:"<<v.capacity()<<endl;
    // cout<<v[3]<<endl;
    // cout<<v[4]<<endl;
    // cout<<v[5]<<endl;
    // cout<<v[6]<<endl;
    // cout<<v.at(7)<<endl;
    // cout<<v[8]<<endl;
    // cout<<v[9]<<endl;
    // cout<<v[10]<<endl;
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";   // inside for loop it is safe to use both [] and .at()
    }
    cout<<endl;
    cout<<"v.capacity:"<<v.capacity()<<endl;
    // for(int i=0;i<100;i++){
    //     cout<<"v.capacity():"<<v.capacity()<<endl;
    //     cout<<"v.size():"<<v.size()<<endl;
    //     v.push_back(i+1);
    // }
     return 0;
} 

