#include <iostream>
using namespace std;
#define endl "\n"

int main() {
	int N;
    cin >> N;

	int idx, side_idx, size;
	int top = 1, bottom = 1, diagonal = N - 1;
	for (idx = 0; idx < N; idx++) {
		cout << top++ << " ";
    }
	cout << endl;

	for (idx = 1; idx < N - 1; idx++) {
		for (side_idx = 0; side_idx < 2 * (N - idx - 1); side_idx++) {
			cout << " ";
        }
		cout << diagonal-- << endl;
	}

	for (idx = 0; idx < N; idx++) {
		cout << bottom++ << " ";
    }
    cout << endl;
	return 0;
}
