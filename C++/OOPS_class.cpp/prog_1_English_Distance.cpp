#include <iostream>

using namespace std;

class Distance
{
    private:
        // Defining all the storing variables in private
        int league;
        int mile;
        int furlong;
        int chain;
        int yard;
        int foot;
        int inch;
        int thou;

    public:
        // getting inputs from user, and storing
        void getdist() {
            cout << "Enter leagues: ";  cin >> league;
            cout << "Enter miles: ";  cin >> mile;
            cout << "Enter furlongs: ";  cin >> furlong;
            cout << "Enter chains: ";  cin >> chain;
            cout << "Enter yards: ";  cin >> yard;
            cout << "Enter feet: ";  cin >> foot;
            cout << "Enter inches: ";  cin >> inch;
            cout << "Enter thou: ";  cin >> thou;

            modifydist();
        }
        // Function to modify the lengths by their upper limits, and adding appropriately to the next longer length unit
        void modifydist() {
            if (thou >= 1000) {
                inch += thou/1000;
                thou = thou%1000;
            }

            if (inch >= 12) {
                foot += inch/12;
                inch = inch%12;
            }

            if (foot >= 3) {
                yard += foot/3;
                foot = foot%3;
            }

            if (yard >= 22) {
                chain += yard/22;
                yard = yard%22;
            }

            if (chain >= 10) {
                furlong += chain/10;
                chain = chain%10;
            }

            if (furlong >= 8) {
                mile += furlong/8;
                furlong = furlong%8;
            }

            if (mile >= 3) {
                league += mile/3;
                mile = mile%3;
            }
        }
        // Function to print the total distance
        void showdist()
        {
            cout << "\nThe distance is : ";
            if (league != 0)
                cout << league << " League ";
            if (mile != 0)
                cout << mile << " Mile ";
            if (furlong != 0)
                cout << furlong << " Furlong ";
            if (chain != 0)
                cout << chain << " Chain ";
            if (yard != 0)
                cout << yard << " Yard ";
            if (foot != 0)
                cout << foot << " Foot ";
            if (inch != 0)
                cout << inch << " Inch ";
            if (thou !=  0)
                cout << thou << " Thou ";

            cout << "\n" << endl;
        }
};

int main ()
{
    Distance d1; // creating an object of Distance class

    d1.getdist();
    d1.showdist();
}