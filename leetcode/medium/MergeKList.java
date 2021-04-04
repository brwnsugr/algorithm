package com.company.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.SortedMap;
import java.util.TreeMap;

public class MergeKList {

  private Map<Integer, Integer> nodeMap = new HashMap<>();

  public ListNode mergeKLists(ListNode[] lists) {

    ListNode head = new ListNode(0);
    ListNode point = head;
    PriorityQueue<Integer> pq = new PriorityQueue<>();

    for (ListNode list : lists) {
      pushToPq(pq, list);
    }

    while(!pq.isEmpty()) {
      point.next = new ListNode(pq.poll());
      point = point.next;
    }
    return head.next;
  }

  private void pushToPq(PriorityQueue<Integer> pq, ListNode listNode) {
    while(listNode != null) {
      pq.add(listNode.val);
      listNode = listNode.next;
    }
  }
}



class ListNode {
  int val;
  ListNode next;

  ListNode() {
  }

  ListNode(int val) {
    this.val = val;
  }

  ListNode(int val, ListNode next) {
    this.val = val; this.next = next;
  }
  
}
