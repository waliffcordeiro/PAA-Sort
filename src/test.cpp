#include <stdio.h>

// Waliff Cordeiro Bandeira - 17/0115810

int main() {
    int n;
    scanf("%d", &n);

    while (n != 42) {
        printf("%d\n", n);
        scanf("%d", &n);
    }
    return 0;
}