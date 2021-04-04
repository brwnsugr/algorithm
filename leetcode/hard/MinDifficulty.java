package com.company.leetcode;

import java.util.Arrays;

public class MinDifficulty {

  public int minDifficulty(int[] jobDifficulty, int d) {
    int jobsLength = jobDifficulty.length;
    if(jobsLength < d) return -1;
    // 1일 현재 날짜의 maxDifficulty, 하루 루프를 다 돌고 나면, 이전 날짜까지의 누적 최소 difficulty 합에다가 maxDifficulty 를 더해주는 방식으로.
    //dp[d][n] -> d 번째날 jobDifficulty 배열의 n 번째까지의  MinDiffuclty 값을 의미함


    // difficulty = {7,4,3,2}, day = 2
    // d[1][1] : 1 번째ㅔ 날 job diff 배열의 1번째 까지의 mindiffuclty -> d[1][1] = difficulty[0];
    // d[2][2] : 2 번째날 job diff 배열의 2번째 -> d[2][2] = d[1]
    int[][] dp = new int[d + 1][jobsLength + 1];

    for (int[] days : dp) {
      Arrays.fill(days, Integer.MAX_VALUE);
    }

    //job diffuclty 배열은 0부터 시작하고 있고,
    //job day배열은 1부터  시작하고 있어서
    dp[0][0] = 0;
    for(int i = 1; i <= d; i++) {
      //어느 i 번째 날을 기준으로 우측을 하나씩 증가 시키면서 순회를 하는데,
      for(int right = i; right <= jobsLength; right++) {
        int maxDifficultyEachDay = 0;
        // 각 우측 포인터를 기점으로 좌측을 i 번째 날 이상의 left 포인터로 순회를 하면서
        // 해당 우측 포인터 기준에서의 maxDifficulty Eachday(i번째) 계속 최대값으로 갱신해준다.
        for(int left = right-1; left >= i - 1; left--) {
          maxDifficultyEachDay = Math.max(maxDifficultyEachDay, jobDifficulty[left]);
          dp[i][right] = Math.min(dp[i][right], dp[i-1][left] + maxDifficultyEachDay);
        }
      }
    }
    return dp[d][jobsLength];
  }
}
