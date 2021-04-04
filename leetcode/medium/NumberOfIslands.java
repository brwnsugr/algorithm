package com.company.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class NumberOfIslands {


  private int [][] directions = new int[][]{{-1,0}, {0,-1}, {0,1},{1,0}};

  public int numIslands(char[][] grid) {
    int row = grid.length;
    int col = grid[0].length;
    int ans = 0;

    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        if(grid[i][j] == '1') {
          grid[i][j] = '2';
          bfs(grid, i, j, row, col);
          ans++;
        }
      }
    }
    return ans;
  }

  private void bfs(char[][] grid, int m, int n, int row, int col) {
    Queue<int[][]> q = new LinkedList<>();
    //insert first init point
    q.add(new int[][]{{m,n}});
    grid[m][n] = '0';

    while(!q.isEmpty()) {
      int[][] cur = q.remove();

      for(int i = 0; i < directions.length; i++) {
        int nextY = cur[0][0] + directions[i][0];
        int nextX = cur[0][1] + directions[i][1];

        if(nextY >= 0 && nextY < row
        && nextX >= 0 && nextX < col) {
          if(grid[nextY][nextX] == '1') {
            grid[nextY][nextX] = '0';
            q.add(new int[][] {{nextY, nextX}});
          }
        }
      }
    }
  }
}
