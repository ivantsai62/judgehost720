#include<cstdio>
#include<algorithm>
#include <stdio.h>
using namespace std;

int r[1005],c[1005];

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    int testcase, i, j, n, m, ans;
    scanf("%d", &testcase);
    while (testcase--){
        ans = 0;
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++)
            scanf("%d", &r[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &c[i]);
        sort(r, r + n, cmp);
        sort(c, c + m, cmp);

        for (i = 0; i < m; i++){
            if (c[i] == 0)
                continue;
            for (j = 0; j < n; j++){
                if (r[j]){
                    ans++;
                    c[i]--;
                    r[j]--;
                }

                if (c[i] == 0)
                    break;
            }
            ans = ans + c[i];
            sort(r, r + n, cmp);
        }

        for (i = 0; i < n; i++)
            ans = ans + r[i];

        printf("%d\n", ans);
    }
    return 0;
}
