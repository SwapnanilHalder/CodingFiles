#include <iostream>
#include <chrono>
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'

#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " µs" << endl
using namespace std;

int main() {
    timestart;
    SPEED1;
    cout << "Hiii" << endl;
    timestop;
}