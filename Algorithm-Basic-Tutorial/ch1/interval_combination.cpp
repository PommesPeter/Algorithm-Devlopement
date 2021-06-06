/* Title: interval_combination
 * Author: @PommesPeter
 * Data:2021-06-06
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int > PII;

const int N = 1e5 + 10;
int n;
int a[N];
vector<PII> segs;

void merge(vector<PII> &segs) {
    vector<PII> res;

    sort(segs.begin(), segs.end()); //按照左端点排序

    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9) {
                res.push_back({st, ed});
            }
            st = seg.first, ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    cin >> n;
    for (int i =0 ; i <n ; i++ ) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;

    return 0;
}