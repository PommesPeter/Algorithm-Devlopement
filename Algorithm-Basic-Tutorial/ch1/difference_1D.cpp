/* Title: difference_1D
 * Author: @PommesPeter
 * Data:2021-05-31
 * */
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k;
int q[N], b[N];

void insert(int l , int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> q[i];
    // 假设一开始都是0，所有的元素都是0，然后创建差分数组的时候相当于对自己本身这个位置插入一个数q[i]
    for (int i = 1; i <= n; i++) insert(i, i, q[i]);
    while (k --) {
        int l, r ,c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    // 求前缀和
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    // 输出结果
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    return 0;
}