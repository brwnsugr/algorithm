package com.company.leetcode;

import java.util.Arrays;

public class ProductExceptSelf {

  public int[] productExceptSelf(int[] nums) {
    int entireProduct = 1;
    int zeroCount = 0;
    for (int i= 0; i < nums.length; ++i) {
      if(nums[i] == 0) {
        zeroCount++;
      }
      if(nums[i] != 0) entireProduct *= nums[i];
      if(zeroCount > 1) return convertToAllZeros(nums);
    }


    for(int i = 0; i < nums.length; i++) {
      if(zeroCount == 1) {
        if(nums[i] == 0) {
          nums[i] = entireProduct;
        }
        else {
          nums[i] = 0;
        }
      } else {
        nums[i] = entireProduct / nums[i];
      }
    }

    return nums;
  }

  int[] convertToAllZeros(int[] nums) {
    for(int i = 0; i < nums.length; i++) {
      nums[i] = 0;
    }
    return nums;
  }

}
