#include <stdio.h>
#define MAX 100000
int main() {
    int n, a[MAX], sum = 0, max_len = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int map[2*MAX+1];
    for (int i = 0; i <= 2*MAX; i++) map[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += (a[i] == 0) ? -1 : 1;
        if (sum == 0) max_len = i + 1;
        if (map[sum + MAX] != -1) {
            if (i - map[sum + MAX] > max_len)
                max_len = i - map[sum + MAX];
        } else {
            map[sum + MAX] = i;
        }
    }
    printf("%d\n", max_len);
    return 0;
}