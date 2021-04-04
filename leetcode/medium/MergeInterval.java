package com.company.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import javafx.util.Pair;

public class MergeInterval {
  public int[][] merge(int[][] intervals) {
    // 넣을 배열의 시작시간이 현재 min pq peek 에 종료시간보다 작거나 같으면, (즉, overlapping이면, 현재 pq 에 해당원소를 넣고,
    // start overlapping
    Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0]));

    LinkedList<int[]> mergedList = new LinkedList<>();
    mergedList.add(new int[] {intervals[0][0], intervals[0][1]});

    for(int i = 1; i < intervals.length; i++) {
      //not overlapping
      if(!mergedList.isEmpty() && mergedList.getLast()[1] < intervals[i][0]) {
        mergedList.add(new int[]{intervals[i][0], intervals[i][1]});
      }
      //overlapping
      else {
        mergedList.getLast()[1] = Math.max(intervals[i][1], mergedList.getLast()[1]);
      }
    }
    return mergedList.toArray(new int[mergedList.size()][]);
  }

}
