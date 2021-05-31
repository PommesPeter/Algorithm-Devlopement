/* Title: prefix_sum_1D
 * Author: @PommesPeter
 * Data:2021-03-21
 * */

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int q[N], sum[N];

int main() {
    sum[0] = 0, q[0] = 0;
    cin >> n >> m;
    for (int i = 1 ; i <= n; i++ ) cin >> q[i];
    for (int i = 1 ; i <= n; i++)  sum[i] = sum[i - 1] + q[i];
    while (m--) {
        int l ,r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}