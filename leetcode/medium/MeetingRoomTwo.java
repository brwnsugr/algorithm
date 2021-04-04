package com.company.leetcode;

import java.util.Arrays;
import java.util.PriorityQueue;

public class MeetingRoomTwo {
  public int minMeetingRooms(int[][] intervals) {
    int numMeeting = intervals.length;
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    //sort the interval by start time

    //O(N * logN), Space complexity: O(N)
    Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0]));


    //add the first element in order to book a room.
    pq.add(intervals[0][1]);

    //loop start
    // O(N * logN)
    for(int i = 1; i < numMeeting; i++) {
      Integer currentMinEndTime = pq.peek();
      if(intervals[i][0] >= currentMinEndTime) {
        pq.remove();
        pq.add(intervals[i][1]);
      }
      else {
       pq.add(intervals[i][1]);
      }
    }
    return pq.size();
  }

}
