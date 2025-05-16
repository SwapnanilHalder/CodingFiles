#include <bits/stdc++.h>
#define SPEED1 ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define int long long int
#define For(i, a, b) for(int i=a; i<b; i++)
#define endl '\n'
#define pl(x) cout << x << "\n"
#define deb(x) cout << '\t' << #x <<  "= " << x << endl
#define vi vector<int>
#define vi2d vector<vector<int>>
#define pv(v) for(const auto&i: v) {cout << i << " ";} cout<<"\n"
#define pv2d(k) for(const auto &j: k) {pv(j);} cout << "" 
#define pb push_back
#define all(x) x.begin(), x.end()
#define inpt(x) int x{}; cin >> x
using namespace std;


class TrieNode {
    public: 
        TrieNode* arr[26];
        int wordCount;
};

class Trie {
public:
    TrieNode* obj;

    Trie() {
        obj = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* head = obj;
        for (auto &s: word) {
            if(head->arr[s-'a'] == NULL) {
                head->arr[s-'a'] = new TrieNode();
                head = head->arr[s-'a'];
            }
        }
        head->wordCount++;
    }
    
    bool search(string word) {
        TrieNode* head = obj;
        for(auto &s: word) {
            if(head->arr[s-'a'] == NULL) {
                return 0;
            }
            head = head->arr[s-'a'];
        }
        return (head->wordCount > 0);
    }
    
    bool startsWith(string prefix) {
        TrieNode* head = obj;
        for(auto &s: word) {
            if(head->arr[s-'a'] == NULL) {
                return 0;
            }
            head = head->arr[s-'a'];
        }
        return 1;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */