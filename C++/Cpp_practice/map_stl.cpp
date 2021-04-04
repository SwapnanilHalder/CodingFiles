#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
    map<int, int> m;
    m[0] = 0;
    m[0]++;
    m.insert({1, 6});
    m[1] = 3;
    m[2]++;
    m[2]++;


    if(m.find(1) == m.end()) {
        m.insert({1, 0});
        cout << "NOT FOUND\n"; 
    } 
    else {
        auto it = m.find(1);
        it->second = 5;
        m[0]++;
        cout << "FOUND\n";
    }

    for(auto it = m.begin(); it!= m.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }
}