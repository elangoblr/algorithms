#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int a, int b){
  return a < b? a: b;
}

int coinChange(int *coins, int coinSize, int amount){
  if (amount == 0)
    return 0;
  int result = INT_MAX;
  for (int i = 0; i < coinSize; i++){
    if (coins[i] <= amount){
      result = min(result, 1 + coinChange(coins, coinSize, amount - coins[i]));
    }
  }
  return result;
}

int main(){
  int coins[] = {1,2, 5};
  int size = sizeof(coins)/sizeof(int);
  int amount = 33;
  printf("min num ways %d\n", coinChange(coins, size, amount));
  return 0;
}
