#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int min(int a, int b){
  return a < b ? a : b;
}

int coinChange(int *coins, int size, int amount){
  if (amount == 0)
    return 0;
  int *dp = malloc(sizeof(int) * (amount + 1));
  for (int i = 0; i <= amount; i++)
    dp[i] = amount + 1;
  dp[0] = 0;
  for (int i = 1; i <= amount; i++)
    for (int j = 0; j < size; j++)
      if (i >= coins[j])
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
  return dp[amount];
}

int main(){
  int coins[] = {1,2,5};
  int size = sizeof(coins)/sizeof(int);
  int amount = 33;
  printf("min num of ways %d\n", coinChange(coins, size, amount));
  return 0;
}
