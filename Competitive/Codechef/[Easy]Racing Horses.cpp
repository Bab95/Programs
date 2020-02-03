#include<stdio.h>
#include<stdlib.h>
int main() {
    int T;
    scanf("%d", &T);
    int N, *p, temp;
    while (T > 0) {
        scanf("%d",&N);
        p = (int *) malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            *(p + i * sizeof(int)) = temp;
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (*(p + i * sizeof(int)) > *(p + j * sizeof(int))) {
                    temp = *(p + i * sizeof(int));
                    *(p + i * sizeof(int)) = *(p + j * sizeof(int));
                    *(p + j * sizeof(int)) = temp;
                }
            }
        }
        printf("\n");
       /* for (int i = 0; i < N; i++) {
            printf("%d", *(p + i * sizeof(int)));
        }*/
        int min = *(p + sizeof(int)) - *p;
        int t1, t2;
        for (int i = 1; i < N - 1; i++) {
            t1 = *(p + (i + 1) * sizeof(int));
            t2 = *(p + i * sizeof(int));
            if (t1 - t2 < min) {
                min = t1 - t2;
            }

        }
        printf("%d\n", min);
        free(p);
        T--;
    }
    return 0;
}
