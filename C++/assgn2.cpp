#include<iostream>
#include<string>
#define pb push_back
#define all(x) x.begin(), x.end()
#define For(i, a, b) for(int i{a} ; i< b ; i++)

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
        string addNum(string, string);
    public:
        void getNum(string);
        void showNum();
        string returnNum();
        Number MultNum(Number n1, Number n2);
};


void Number::getNum(string n) {
    num1 = n;
} 

string Number::returnNum() {
    return num1;
}

void Number::showNum() {
    cout << "Str : " << num1 <<endl;
}

string Number::addNum(string num1, string num2) {
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
    return result;
}

Number Number::MultNum(Number n, Number nn) {
    string num1 = n.returnNum();
    string num2 = nn.returnNum();
    reverse(num1);reverse(num2);
    if(num2 > num1)
        swap(num1, num2); //num1 is greater
    //while(num1.length() != num2.length()) num2.pb('0');
    int n1 = num1.length(), n2 = num2.length(), base{0};
    string mul1 = "", res = "";
    For(i, 0, n2) {
        base = num2[i]-'0';
        mul1 = "";
        int temp{0}, carry{0}, sit{0}, num{0};
        For(j, 0, n1) {
            num = (num1[j]-'0');
            temp = num * base + carry; 
            sit = temp %10; carry = temp /10; // determining the carry and sit
            mul1.pb(sit+'0');
        }
        if(carry) mul1.pb(carry+'0'); // adding the carry at the end
        reverse(mul1); 
        For(k, 0, i) mul1.pb('0');
        res = addNum(res, mul1); // updating the result
    }
    while((res[0]-'0') == 0) res.erase(res.begin());
    Number result;
    if(res.empty()) result.getNum("0"); // if one of the numbers is 0, the string will be empty
    else result.getNum(res);
    return result;
}

int main() {
    Number n1, n2, mult;
    string h1, h2;
    cout << "Enter the numbers: \n";
    cin >> h1 >> h2;
    n1.getNum(h1);
    n2.getNum(h2);
    mult = mult.MultNum(n1, n2);
    mult.showNum();
}

