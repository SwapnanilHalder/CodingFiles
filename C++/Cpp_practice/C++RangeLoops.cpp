#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{0,1,2,3,4,5,6};
    for(auto &i:v)
        cout<<i<<' ';
    cout<<endl;

    for(int n:{10, 11, 14, 82, 100})
        cout<<n<<' ';
    cout<<endl;

    string str = "Geeks";
    for (auto &c : str)
        cout<<c<<' ';
    cout<<endl;

    map<int, int> MAP({{1,1}, {4,4}, {10,10}});
    for (auto &i : MAP)
    cout<<"{" << i.first<< ", "<<i.second<<"}\n";
}
