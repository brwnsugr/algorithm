package com.company.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Set;

public class RandomizedSet {

  Map<Integer, Boolean> randomizedMap;


  /** Initialize your data structure here. */
  public RandomizedSet() {
    randomizedMap = new HashMap<>();

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  public boolean insert(int val) {
    if(randomizedMap.containsKey(val)) {
      return false;
    }
    else{
      randomizedMap.put(val, true);
      return true;
    }
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  public boolean remove(int val) {
    if(randomizedMap.containsKey(val)) {
      randomizedMap.remove(val);
      return true;
    }
    else{
      return false;
    }
  }

  /** Get a random element from the set. */
  public int getRandom() {
    Object[] keys = randomizedMap.keySet().toArray();
    int key = (int)keys[new Random().nextInt(keys.length)];
    return key;
  }

}
