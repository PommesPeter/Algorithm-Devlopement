/* Title: k-th-number
 * Author: @PommesPeter
 * Data:2021-05-30
 * */
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k;
int q[N];

int quick_select(int q[], int l, int r) {

    if (l >= r) return q[l];
    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;
    while ( i < j ) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if (i < j)  swap(q[i], q[j]);
    }
    if (k - 1 <= j) quick_select(q, l, j);
    else quick_select(q, j + 1, r);
}

int main() {
    int res;
    cin >> n >> k;
    for (int i =0 ; i < n; i++) cin >> q[i];
    res = quick_select(q, 0, n - 1);
    cout << res << endl;
    return 0;
}

/*
 * 思路: 按照快排的思路，将列表分成两个部分，左边都<=x，右边都>=x
 * 查看k是否<左边的个数，如果小于说明第k个数在左侧，直接递归左边即可找到k，反之往又。
 *
 * */
