#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string &org, char delimiter) {
    vector<string> v;
    for (int i = 0 ;i < org.length(); i++) {
        int j = i;
        while (org[j] != delimiter && j < org.length()) j++;
        v.emplace_back(org.substr(i, j - i));
        i = j;
    }
    return v;
}

int main() {
    string a;
    getline(cin, a);
    auto c = split(a, ' ');
    for (auto &i : c) cout << i << endl;

    return 0;
}