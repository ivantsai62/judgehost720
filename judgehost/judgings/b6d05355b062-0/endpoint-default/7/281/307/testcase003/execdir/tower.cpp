#include <cstdio>
#include <algorithm>
using namespace std;
struct Block{
    int L;
    int W;
    int H;
} B[300];
int nOfB;

bool cmp(const Block &X, const Block &Y) {
    if (X.L == Y.L)
        return X.W < Y.W;
    return X.L < Y.L;
}

int main(){
    int Case = 1, N, L, W, H;
    while (scanf("%d", &N) && N){
        nOfB = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d %d %d", &L, &W, &H);
            B[nOfB++] = {L, W, H};
            B[nOfB++] = {L, H, W};
            B[nOfB++] = {W, L, H};
            B[nOfB++] = {W, H, L};
            B[nOfB++] = {H, L, W};
            B[nOfB++] = {H, W, L};
        }
        sort(B, B + nOfB, cmp);

        int LIS[300], Max = 0;
        for (int i = 0; i < nOfB; ++i) {
            LIS[i] = B[i].H;
            for (int j = 0; j < i; ++j)
                if (B[i].L > B[j].L && B[i].W > B[j].W && LIS[j] + B[i].H > LIS[i])
                    LIS[i] = LIS[j] + B[i].H;

            if (LIS[i] > Max) Max = LIS[i];
        }
        printf("Case %d: maximum height = %d\n", Case++, Max);
    }
}
