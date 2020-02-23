#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define AMOUNT 33

int min(int a, int b){
  return a < b ? a : b;
}

int coinChangeRec(int *coins, int size, int amount, int *dp){
  int result = 0;
  if (amount == 0)
    return result;
  if (dp[amount] != INT_MAX)
    return dp[amount];
  int minimum = INT_MAX;
  for (int i = 0; i < size; i++){
    if (amount >= coins[i]){
      minimum = min(minimum, 1 + coinChangeRec(coins,
            size, amount - coins[i], dp));
      dp[amount] = minimum;
    }
  }
  return dp[amount];
}

int coinChange(int *coins, int size, int amount){
  int *dp = malloc(sizeof(int) * (amount + 1));
  for (int i = 0; i <= amount; i++)
    dp[i] = INT_MAX;
  return coinChangeRec(coins, size, amount, dp);
}

int main(){
  int coins[] = {1,2,5};
  int size = sizeof(coins)/sizeof(int);
  printf("Min num ways %d\n", coinChange(coins, size, AMOUNT));
  return 0;
}
