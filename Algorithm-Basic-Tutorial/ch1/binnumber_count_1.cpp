/* Title: binnumber_count_1
 * Author: @PommesPeter
 * Data:2021-06-03
 * */

#include <iostream>
using namespace std;

int lowbit(int x) {
    return x & -x;
}
int main() {
    int n;
    cin >> n;
    while(n -- ) {
        int x;
        cin >> x;

        int res = 0;
        while (x) {
            //每次减去x的最后一位1
            x -= lowbit(x);
            res++;
        }
        cout << res << " ";
    }
    return 0;
}