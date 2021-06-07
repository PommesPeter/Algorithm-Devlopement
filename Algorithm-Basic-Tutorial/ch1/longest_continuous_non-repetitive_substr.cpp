/* Title: longest_continuous_non-repetitive_substr
 * Author: @PommesPeter
 * Data:2021-06-03
 * */

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, res = 0;
int a[N], s[N];

int main() {
    // 算法思想: 左边一个指针j表示往左最远能到什么地方，右边一个指针i表示遍历一次该数组
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (s[a[i]] > 1) {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}