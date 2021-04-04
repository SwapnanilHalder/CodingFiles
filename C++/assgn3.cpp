#include<iostream>
#include<string>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

void reverse(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
}

class Number {
    private:   
        string num1;
    public:
        void getNum(string);
        void showNum();
        string returnNum();
        Number addNum(Number n1, Number n2);
        Number operator+(Number &n2){
            string num2 = n2.returnNum();
            string result = "";
            reverse(num1);reverse(num2);  // reversing the string to start calculation from arr[0]
            if(num1.length() > num2.length())
                swap(num1, num2); //num2 is greater 
            while(num1.length() != num2.length()) num1.pb('0'); // making both the strings equal in size
            int carry{0}, sit{0}, temp{0}; 
            int nl = num1.length(), i{0}, j{0};
            while(i < nl) {
                int num11 = (num1[i]-'0'), num22 = (num2[i]-'0');
                int temp = num11 + num22 + carry;  // calculating the next digit
                sit = temp %10; carry = temp / 10; // determining the digit which will be placed and the rest to be carried
                result.pb(sit+'0');
                i++;
            }
            if(carry != 0) result.pb(carry+'0');
            reverse(result);
            Number sum; sum.getNum(result);
            return sum;
        };
};


void Number::getNum(string num) {
    num1 = num;
} 

string Number::returnNum() {
    return num1;
}

void Number::showNum() {
    cout << "Number : " << num1 <<endl;
}

int main() {
    Number n1, n2, sum;
    string h1, h2;
    cout << "Enter the Numbers : \n";
    cin >> h1 >> h2;
    n1.getNum(h1);
    n2.getNum(h2);
    sum = n1 + n2;
    sum.showNum();
}