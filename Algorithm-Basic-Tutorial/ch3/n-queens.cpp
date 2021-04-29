/* Title: bigInteger_minus_template
 * Author: @PommesPeter
 * Data:2021-04-29
 * */

#include <iostream>

using namespace std;

const int N = 105;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; i++) {
        //为什么这里是u+i和n-u+i
        //一个特殊的小技巧：用平面直角坐标系可以类比，一个斜率是正数的直线的截距是y=x+b=>b=y-x；一个斜率是负数的直线截距是y=-x+b=>b=y+x
        //为了不让截距为负数，通常加上偏移量n，即b=y-x+n
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main () {
    cin >> n;
    for (int i =0 ;i < n; i++) {
        for (int j= 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;

}

