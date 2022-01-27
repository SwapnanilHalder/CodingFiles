/*

Name : Swapnanil Halder
Roll No. : 18MA20046

*/

#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false)
#define SPEED1 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define vi vector<int>
#define vi2d vector<vector<int>> 
#define li list<int>
#define mii map<int, int>
#define msi map<string, int>
#define pb push_back
#define For(i,a,b) for(int i=a;i<b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define pi 3.1415926535897932384626
#define MOD 1000000007
#define INF 9223372036854775800 
#define ll long long
#define END cout << "\n" 
#define ENDstd printf("\n")
#define cinbuffer cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define pv(v) for(const auto &i: v){cout<<i<<" ";}END
#define pv2d(v2d) for(const auto &i : v2d) {pv(i);}cout<<""
#define deb(x) cout << '\t'<<#x << " = " << x << endl
#define inpt(x) int x{}; cin >> x
#define inptstd(x) int x{}; scanf("%lld", &x)
#define pn(x) printf("%lld\n", x)
#define pl(x) cout << x << endl
#define all(v) v.begin(),v.end()
#define loop(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define pmint(v) cout<< #v<<endl;loop(itr, v){cout << "\t" << itr->first << " ->  " << itr->second;END;}
#define pmpair(v) cout<< #v<<endl; cout << "	(" << v.first << " , " << v.second << ")";END
#define timestart auto start = chrono::high_resolution_clock::now()
#define timestop auto stop = chrono::high_resolution_clock::now();auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);cout << "Time taken by function: "<< duration.count() << " microseconds" << endl
using namespace std;

int gcd(int a, int b){return b ? gcd(b, a%b): a;}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
template <class T> T Max(T x,T y){return (x>y)?x:y;}
template <class T> T Min(T x,T y){return (y>x)?x:y;}


void generate_all_subsets(string &str, vector<string> &vec_subsets, string &subset, int index=0)
{
    vec_subsets.pb(subset);
    For(i, index, str.size()) {
        subset.pb(str[i]);
        generate_all_subsets(str, vec_subsets, subset, i + 1);
        subset.pop_back();
    }
    return;
}

vector<string> power_set(string &str)
{
    string subset;
    vector<string> vec_subsets;
    generate_all_subsets(str, vec_subsets, subset);
    cout << "printing all possible power_sets :\t";pv(vec_subsets);END;
    return vec_subsets;
}

bool cmp(string &a, string &b) {
    if (a.size() < b.size())
        return true;
    else if (a.size() > b.size())
        return false;
    if (a.compare(b) <= 0)
        return true;
    return false;
}

bool is_present(string &s, char &find_char) {
    return (s.find(find_char) == string::npos) ? false : true;
}

bool is_present(string &s, string &find_str) {
    unordered_set<char> cc;
    For(i, 0, s.size())
        cc.insert(s[i]);
    For(i, 0, find_str.size())
        if (cc.find(find_str[i]) == cc.end())
            return false;
    return true;
}

string closure(string key, vector<pair<string, string>> &functional_dependency) {
    For(i, 0, functional_dependency.size()) {
        if (is_present(key, functional_dependency[i].first) && !is_present(key, functional_dependency[i].second)) {
            key = key + functional_dependency[i].second;
            sort(all(key));
            key = string(key.begin(), unique(all(key)));
            return closure(key, functional_dependency);
        }
    }
    return key;
}

bool is_key(string &key, string &attribute_str, vector<pair<string, string>> &functional_dependency) {
    string closure_set = closure(key, functional_dependency);
    return is_present(closure_set, attribute_str);
}

int main() {
    cout << "choose attributes as single characters, and ENTER a string of all attributes (e.g. ABCDEG) =>\n";
    string attribute_str; cin >> attribute_str; int n = attribute_str.size();
    cout << "Enter the number of functional dependencies =>\n";
    int fd_size; cin >> fd_size;
    vector<pair<string, string>> functional_dependency(fd_size);
    cout << "Enter all the functional dependencies in order with spaces in between(e.g. AB->C; D->G => AB C D G)\n";
    For(i, 0, fd_size) {
        cin >> functional_dependency[i].first >> functional_dependency[i].second;
    }

    vector<int> idx_of_attribute(26, -1);
    For(i, 0, n) {
        idx_of_attribute[attribute_str[i] - 'a'] = 1;
    }

    For(i, 0, fd_size) {
        For(j, 0, functional_dependency[i].second.size()) {
            idx_of_attribute[functional_dependency[i].second[j] - 'a'] = 2;
        }
    }
    string primary_key_member, rest_attributes;
    For(i, 0, n) {
        if (idx_of_attribute[attribute_str[i] - 'a'] == 1)
            primary_key_member = primary_key_member + attribute_str[i];
        else if (idx_of_attribute[attribute_str[i] - 'a'] == 2)
            rest_attributes = rest_attributes + attribute_str[i];
    }

    vector<string> vec_powersets = power_set(rest_attributes), keys;
    sort(all(vec_powersets), cmp);
    int key_size = -1;
    for (string const possible_key_member : vec_powersets) {
        string key = primary_key_member + possible_key_member;
        if (key.empty())
            continue;
        if (key.size() > key_size)
            break;
        if (is_key(key, attribute_str, functional_dependency)) {
            (key_size == -1) ? key_size = key.size() : 0;
            sort(all(key));
            keys.pb(key);
        }
    }
    pl("Keys with Minimum Length:");
    pv(keys);
    return 0;
}


/*
ABCDEG
AB -> C; C -> A; BC -> D; ACD -> B; D -> EG; BE -> C; CG -> BD; CE -> AG

ABCDEG
8
AB C
C A
BC D
ACD B
D EG
BE C
CG BD
CE AG

*/