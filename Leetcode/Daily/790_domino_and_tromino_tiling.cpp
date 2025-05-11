#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY related as parameter.
 */

 int countGroups(vector<string> related) {
    
    map<int, set<int>> knownTo;
    set<int> grouped;
    int group = 0;
    for(int i=0; i<related.size(); i++) {
        for(int j=0; j<related[0].size(); j++) {
            if( (related[i][j]-'0') == 1) {
                // if(knownTo[i].find(j) == knownTo[i].end()) {
                //     knownTo[i].insert(j);
                //     knownTo[j].insert(i);
                    if(grouped.find(i) != grouped.end()) {
                        grouped.insert(j);
                    } else if(grouped.find(j) != grouped.end()) {
                        grouped.insert(i);
                    } else {
                        grouped.insert(i);
                        grouped.insert(j);
                        group++;
                    }
                // }
            }
        }
    }
    return (group + related.size()-grouped.size());
}

int main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string related_count_temp;
    getline(cin, related_count_temp);

    int related_count = stoi(ltrim(rtrim(related_count_temp)));

    vector<string> related(related_count);

    for (int i = 0; i < related_count; i++) {
        string related_item;
        getline(cin, related_item);

        related[i] = related_item;
    }

    int result = countGroups(related);
    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
