# 4 Keys Keyboard

* 이 질문은 네 가지 작업, 즉 A 인쇄, 모두 선택, 복사, 붙여 넣기를 제공합니다. 각 작업은 하나의 단계로 간주되어 숫자 N을 제공하고 N 작업에 대해 하나 이상의 A를 출력하도록 요청합니다. 제목의 예제를 분석하여 N 단계가 적어도 N A를 인쇄 할 수 있음을 확인합니다. 모든 단계를 A로 인쇄 할 수 있기 때문입니다. 그러면 N을 초과 할 수있는 상황은 확실히 복사 및 붙여 넣기의 사용입니다. 여기에서 모든 선택 및 복사 작업은 두 단계로 진행되므로 A의 수를 늘리는 작업은 실제로 N-2 단계에 불과합니다. 그 다음은 붙여 넣기입니다. 사실, 인쇄물이 너무 많거나 적어서 최대 결과를 얻지 못하기 때문에 인쇄 A와 붙여 넣기 횟수가 가까워 지므로 가장 쉬운 방법은 모든 사례를 통과 한 다음 최대 값을 얻는 것입니다 A가 인쇄되는 횟수는 [1, N-3] 사이이며, 붙여 넣기 횟수는 N-2-i이고 인쇄 된 부분은 N-1-i입니다.

```java
class Solution {
  //Rescursively
  public int maxRecursively(int n) {
      int max = n;
      for (int i = 1; i < n - 2; i++)
          max = Math.max(max, maxRecursively(i) * (n - i - 1));
      return max;
  }

  //# Time:  O(n^2)
  //# Space: O(n)
  public int maxA(int N) {
      int[] dp = new int[N+1];
      for (int i = 1; i <= N; i++) {
          dp[i] = i;
          for (int j = 1; j < i - 2 ; j++){
              dp[i] = Math.max(dp[i], dp[j] * (i-j-1));
          }
            
      }
      return dp[N];
  }

  //dp[i] = max(dp[i], dp[i-j]*(j-1)) j in [3, i)
  //# Time:  O(n^2)
  //# Space: O(n)
  public int maxA3(int N) {
      int[] dp = new int[N+1];
      for(int i=1;i<=N;i++){
          dp[i] = i;
          for(int j=3;j<i;j++){
              dp[i] = Math.max(dp[i], dp[i-j] * (j-1));
          }
      }
      return dp[N];
  }

  //# Time:  O(n)
  //# Space: O(n)
  public int maxA4(int N) {
    if (N <= 6)  return N;
    int[] dp = new int[N + 1];

    for (int i = 1; i <= 6; i++) {
      dp[i] = i;
    }

    for (int i = 7; i <= N; i++) {
      dp[i] = Math.max(dp[i - 4] * 3, dp[i - 5] * 4);
      // dp[i] = Math.max(dp[i - 4] * 3, Math.max(dp[i - 5] * 4, dp[i - 6] * 5));
    }

    return dp[N];
  }
  
  //# Time:  O(1)
  //# Space: O(n)
  public int maxA5(int N) {
    int[] best = new int[] { 0, 1, 2, 3, 4, 5, 6, 9, 12, 16, 20, 27, 36, 48, 64, 81 };
    int q = N > 15 ? (N - 11) / 5 : 0;
    return best[N - 5 * q] << 2 * q;
  }
}
```
