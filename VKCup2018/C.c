#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nl '\n'

int main() {
    bool good = true;
    int n;
    scanf("%d", &n);

    int numFirst = 0;
    int a;
    scanf("%d", &a);
    int first = a;
    numFirst++;
    while (a == first && numFirst < n) {
        scanf("%d", &a);
        if (a != first) {
            break;
        }
        numFirst++;
    }
    int count = 0;
    int curr = a;
    count++;
    for (int i = 0; i < n - numFirst - 1; i++) {
        scanf("%d", &a);
        if (a == curr) {
            count++;
        } else {
            if (count != numFirst) {
                good = false;
                break;
            } else {
                curr = a;
                count = 1;
            }
        }
    }

    if (numFirst != n && count != numFirst) {
        good = false;
    }
    if (good) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
