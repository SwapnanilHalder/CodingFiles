#include <fstream>
#include <iostream>
#include <string>
#define For(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
using namespace std;

int main() {
    ifstream file("input.txt");  // Reading from 'input.txt' file
    ofstream myfile;
    myfile.open("output.txt"); // Outputting to 'output.txt' file
    string data = "";
    while(getline(file, data, ',')) {
        string s;  // Taking a string to push the valid numbers and decimal point, which later can be pushed in 'output.txt' 
        For(i, 0, data.size()) {
            if((data[i] >= '0' && data[i] <= '9') || data[i] == '.') {
                s.pb(data[i]);
            }
        }
        if(s.length() > 0) myfile << s << ", "; // pushing the string inside the file
    }
    file.close(); // close the input file stream
    myfile.close(); // close the output file stream
}