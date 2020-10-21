#include <iostream>

int mdc(int a, int b) {

    if(b == 0)
        return a;
    else
        return mdc(b, a % b);
}

int mmc(int a, int b) {

    return (a*b) / mdc(a,b);
}

int main () {

    int a, b;
    std::cin >> a >> b;
    printf("MDC = %d MMC = %d\n", mdc(a, b), mmc(a, b));
    return 0;
}
