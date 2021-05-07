#include <stdint.h>
#include <stdio.h>

void print_2_pow_n(int n) {
    int i, j, blen = n / 32 + 1, dlen = n / 29 + 1;
    uint32_t bin[blen], dec[dlen];
    uint64_t num;

    for (i = 0; i < blen; i++)
        bin[i] = 0;
    bin[n / 32] = (uint32_t)1 << (n % 32);

    for (j = 0; blen > 0; ) {
        for (num = 0, i = blen; i-- > 0;) {
            num = (num << 32) | bin[i];
            bin[i] = num / 1000000000;
            num = num % 1000000000;
        }
        dec[j++] = (uint32_t)num;
        while (blen > 0 && bin[blen - 1] == 0)
            blen--;
    }
    printf("2^%d = %u", n, dec[--j]);
    while (j-- > 0)
        printf("%09u", dec[j]);
    printf("\n");
}

int main() {
    int i;
    // for (i = 0; i <= 100; i += 5)
    //     print_2_pow_n(i);
    // print_2_pow_n(1000);
    // print_2_pow_n(10000);
    print_2_pow_n(100000);
    return 0;
}