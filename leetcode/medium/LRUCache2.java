package com.company.leetcode;

public class LRUCache2 {

  private int capacity;
  private int currentSize;
  DoublyLinkeList doublyLinkeList;

  public LRUCache2(int capacity) {
    this.capacity = capacity;
    this.currentSize = 0;
    this.doublyLinkeList = new DoublyLinkeList();
  }

  public int get(int key) {
    return 0;
  }

  public void put(int key, int value) {

  }

  class DNode {
    int key;
    int value;
    DNode next;
    DNode prev;
  }

  class DoublyLinkeList {
    DNode head;
    DNode tail;
  }

  //Node add

  public void addNode(DNode node) {

    //add Node right next to the head;

    //if head.next 가 tail인 경우
    if(doublyLinkeList.head == doublyLinkeList.tail) {
      //head, tail mapping to the node
      doublyLinkeList.head.next = node;
      doublyLinkeList.tail.prev = node;
      //node 가 head, tail mapping
      node.prev = doublyLinkeList.head;
      node.next = doublyLinkeList.tail;
    }
    //if 중간원소 있는경우, head 옆에 tail을 밀어넣는다.
    //
    else{
      node.next = doublyLinkeList.head.next;
      doublyLinkeList.head.next.prev = node;
      doublyLinkeList.head.next = node;
      node.prev = doublyLinkeList.head;
    }
  }

  //Node remove
  public void removeNode() {
    // Remove node from right previous to the tail

  }



}
