package com.company.leetcode;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {

  private Map<Integer, DNode> cache;
  private int capacity;
  private int currentSize;
  private DNode head, tail;

  public LRUCache(int capacity) {
    this.cache = new HashMap<>();
    this.capacity = capacity;
    this.currentSize = 0;

    head = new DNode(); // head null
    tail = new DNode(); // tail null
    head.next = tail;
    tail.prev = head;
  }

  public int get(int key) {
    DNode node = cache.get(key);
    if (node == null) return -1;
    else{
      //move to head(가장 최근에 썼으니까 헤드로 올리자)
      moveToHead(node);
      return node.value;
    }
  }

  public void put(int key, int value) {
    //용량이 꽉 안찼으면 새로운걸 헤드 앞에 넣는다.
    DNode node = cache.get(key);

    if(node == null) { // 새 노드를 받는 경우
      DNode newNode = new DNode();
      newNode.key = key;
      newNode.value = value;

      cache.put(key, newNode);
      addNode(newNode);

      if(currentSize < capacity) {
        currentSize++;
      }
      else { // 현재가 꽉 찼을 경우
        DNode lastNode = popTail();
        cache.remove(lastNode.key);
      }
    }
    else{
      node.value = value;
      moveToHead(node);
    }
  }

  class DNode {
    int key;
    int value;
    DNode prev;
    DNode next;
  }

  private void addNode(DNode node) {
    //Node를 헤드 다음에 항상 추가함
    node.prev = head;
    node.next = head.next;

    head.next.prev = node;
    head.next = node;
  }

  private void removeNode(DNode node) {
    //노드를 삭제하고, 전노드, 후노드의 관계도 끊어준다.
    DNode prev = node.prev;
    DNode next  = node.next;
    prev.next = next;
    next.prev = prev;
  }

  private void moveToHead(DNode node) {
    removeNode(node);
    addNode(node);
  }

  private DNode popTail() {
    // Pop the current tail
    if (tail.prev == null) {
      return null;
    }
    else{
      DNode node = tail.prev;
      removeNode(tail.prev);
      return node;
    }
  }

}
