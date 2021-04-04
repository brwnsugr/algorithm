package com.company.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class KClosestPoint {

  public int[][] kClosest(int[][] points, int k) {
    Map<Double, List<int[]>> m = new HashMap<>();
    List<Point> pointList = new ArrayList<>(points.length);
    for(int[] point : points) {
      pointList.add( new Point(point[0], point[1]));
    }
    PriorityQueue<Point> pq = new PriorityQueue<>(pointList);
    int[][] res = new int[k][2];
    for(int i = 0; i < k; ++i) {
      Point point = pq.poll();
      res[i] = new int[]{point.y, point.x};
    }
    return res;
  }

  static class Point implements Comparable<Point> {

    private int y;
    private int x;
    private int distPow;

    public Point(int y, int x) {
      this.y = y;
      this.x = x;
      this.distPow = y*y + x*x;
    }

    @Override
    public int compareTo(Point point) {
      return (this.distPow - point.distPow);
    }
  }
}
