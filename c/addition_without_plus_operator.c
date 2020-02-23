/*
 * Addition of two numbers without using '+' operator.
 */

#include<stdio.h>
#include<stdlib.h>

int add(int a, int b){
  while (b != 0){
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

int addRecursion(int a, int b){
  if (b == 0)
    return a;
  addRecursion(a ^ b, (a & b) << 1);
}

int main(){
  int a = 45;
  int b = 23;
  printf("Total: %d\n", add(a, b));
  printf("Total using recursion: %d\n", addRecursion(a, b));
  return 0;
}
