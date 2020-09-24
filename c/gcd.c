#include<stdio.h>
#include<stdlib.h>

int gcd(int x, int y){
    if (y == 0)
        return x;
    return gcd(y, x%y);
}

int main(){
    int x, y;
    printf("Enter two values: ");
    scanf("%d %d", &x, &y);
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    return 0;
}
