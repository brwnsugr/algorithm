package com.company.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class MeetingRooms2 {

  public int minMeetingRooms(int[][] intervals) {
    if (intervals.length == 0) return 0;
    Arrays.sort(intervals, (a,b) -> Integer.compare(a[0],b[0]));
    PriorityQueue<Integer> allocator = new PriorityQueue<Integer>(
        intervals.length,
        new Comparator<Integer>() {
          @Override
          public int compare(Integer o1, Integer o2) {
            return o1 - o2;
          }
        }
    );

    //First Schedule let be assigned
    allocator.add(intervals[0][1]);

    for(int i = 1; i < intervals.length; i++) {
      Integer minTop = allocator.peek();
      if(intervals[i][0] < minTop) {
        allocator.add(intervals[i][1]);
      }
      else{
        allocator.remove();
        allocator.add(intervals[i][1]);
      }
    }
    return allocator.size();
  }
}
