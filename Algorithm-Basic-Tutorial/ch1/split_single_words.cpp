/* Title: split single words
 * Author: @PommesPeter
 * Data: 2021-06-03
 * */

#include <iostream>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    for (int i = 0; i < a.length(); i++) {
        int j = i;
        while (a[j] != ' ' && j < a.length()) j++;
        cout << a.substr(i, j - i) << endl;
        i = j;
    }
    return 0;
}