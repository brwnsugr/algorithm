package com.company.leetcode;

import static java.lang.Integer.min;

import java.util.Stack;

public class TrappingRainWater {

  public int trap(int[] height) {

    Stack<Integer> s = new Stack();

    int cur = 0;
    int ans = 0;

    for(cur = 0; cur < height.length; cur++) {
      while(!s.empty() && height[cur] > height[s.peek()]) {
        int top = s.peek();
        s.pop();
        if(s.empty()) break;
        int distance = cur - s.peek() - 1;
        int boundedHeight = min(height[cur],height[s.peek()]) - height[top];
        ans += distance * boundedHeight;
      }
      s.push(cur);
    }

    return ans;
  }

}
