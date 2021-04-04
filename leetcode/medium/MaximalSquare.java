package com.company.leetcode;

public class MaximalSquare {
  public int maximalSquare(char[][] matrix) {

    int answer = 0;
    int row = matrix.length;
    int col = matrix[0].length;

    //search from the left uppermost point
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        // if case that Found 1, trying to find out how big the square size is, from 1.
        if(matrix[i][j] == '1') {
          int diagonalSquareSizeArea = getDiagonalSquareSizeArea(i, j, matrix);
          int area = diagonalSquareSizeArea * diagonalSquareSizeArea;
          if(area > answer) {
            answer = area;
          }
        }
      }
    }
    return answer;
  }

  public int getDiagonalSquareSizeArea(int i, int j, char[][] matrix) {
    int squareSideLength = 0;

    while(i + squareSideLength < matrix.length && j + squareSideLength < matrix[0].length) {
      if(matrix[i+squareSideLength][j+squareSideLength] == '1') {
        boolean isCurrentSquare = true;
        for(int start = 0; start <= squareSideLength; start++) {
          if(matrix[i+start][j + squareSideLength] == '0' ||
            matrix[i+squareSideLength][j+start] == '0') {
            isCurrentSquare = false;
            break;
          }
        }
        if(isCurrentSquare) {
          squareSideLength++;
        }
        else{
          break;
        }
      }
      else{
        break;
      }
    }
    return squareSideLength;
  }

}
