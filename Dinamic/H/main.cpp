#include <bits/stdc++.h>


int main(){
  freopen("peacefulsets.in", "r", stdin);
  freopen("peacefulsets.out", "w", stdout);
  int n;
  std::cin >> n;
  int dp[12][n+1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(size_t i = 0; i <= n; i++){
    for (size_t j = 0, p = 1; p <= i; j++) {
      for(size_t k = 0; k <= j; k++){
        dp[j][i] += dp[k][i - p];
      } 
      std::cout << p << " " << j << std::endl;
      p *= 2;
      p++;

    }
  }
  long long answer = 0;
  for (size_t i = 0; i < 12; i++){
    answer += dp[i][n];
  }
  std::cout << answer << std::endl;
  return 0;
}
