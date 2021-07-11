int n, m;
cin >> n >> m;
set<int> set1;
while (n--)
{
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
		set1.insert(i);
}

while (m--)
{
	int sl;
	cin >> sl;

	auto iterator = set1.find(sl);
	if (iterator != set1.end()) {
		cout << " " << *iterator;
		set1.erase(iterator);
	} else {
		if (sl < *set1.begin()) {
			cout << " " << *set1.begin();
			set1.erase(set1.begin());
		} else {
			if (sl > *set1.rbegin()) {
				cout << " " << *set1.rbegin();
				iterator = set1.end();
				iterator--;
				set1.erase(iterator);
			} else {
				auto iterator2 = lower_bound(set1.begin(), set1.end(), sl);
				auto it1 = iterator2;
				it1--;

				if (abs(*it1 - sl) <= abs(*iterator2 - sl)) {
					cout << " " << *it1;
					set1.erase(it1);
				} else {
					cout << " " << *iterator2;
					set1.erase(iterator2);
				}
			}
		}

	}
}