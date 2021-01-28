//uva10142
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//must use c++11

char can[21][500], tmp[500];
int v[1001][25], score[25], fire[25], ans, firepeople;
int tc, n, i, j, p, print = 0;
int main(void){
    scanf("%d", &tc);
    while (tc--){
        memset(v, 0, sizeof(v));
        memset(fire, 0, sizeof(fire));
        memset(score, 0, sizeof(score));
        memset(can, 0, sizeof(can));
        memset(tmp, 0, sizeof(tmp));
        ans = -1;
        firepeople = 0;
        scanf("%d", &n);
        gets(can[0]);
        for(i = 0; i < n; i++)
            gets(can[i]);
        p = 0;//how many people vote
        while (gets(tmp)){
            if(!strcmp(tmp, ""))
                break;
            char *t;
            int a;
            j = 0;
            t = strtok(tmp, " ");
            while(t != NULL){
                a = atoi(t);
                v[p][j++] = a;
                t = strtok(NULL," ");
            }
            p++;
        }
        while (ans + ans <= p && firepeople < n){
            int mi = 0, ma = 0;
            memset(score, 0, sizeof(score));
            for (i = 0; i < p; i++){
                for(j = 0; j < n; j++)
                    if(!fire[v[i][j]]){
                        score[v[i][j]]++;
                        break;
                    }
            }
            int t = 0;
            for (i = 1; i <= n; i++)
                if (score[i] > t)
                    t = score[i];
            ans = t;
            if( ans + ans > p)
                break;
            else {
                for (i = 1; i <= n; i++)
                    if (score[i]){
                        if (!mi)
                            mi = i;
                        else if (score[mi] > score[i])
                            mi = i;
                        if(score[ma] < score[i])
                            ma = i;
                    }
                for (i = 1; i <= n; i++)
                    if (score[i] == score[mi]){
                        fire[i] = 1;
                        firepeople++;
                    }
            }
            if (score[ma] == score[mi])
                break;
        }
        if (print)
            printf("\n");

        for (i = 1; i <= n; i++)
                if (score[i] == ans)
                    printf("%s\n", can[i - 1]);
        print = 1;
    }
    return 0;
}
