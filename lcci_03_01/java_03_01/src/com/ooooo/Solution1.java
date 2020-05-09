package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/9 11:28
 */
public class Solution1 {


  static class TripleInOne {

    private int size, index_0, index_1, index_2;
    private int[] data;

    public TripleInOne(int stackSize) {
      data = new int[stackSize * 3];
      size = stackSize;
      index_0 = 0;
      index_1 = stackSize;
      index_2 = 2 * stackSize;
    }

    public void push(int stackNum, int value) {
      if (stackNum == 0) {
        if (!isFull(0)) data[index_0++] = value;
      }
      if (stackNum == 1) {
        if (!isFull(1)) data[index_1++] = value;
      }
      if (stackNum == 2) {
        if (!isFull(2)) data[index_2++] = value;
      }
    }

    private boolean isFull(int stackNum) {
      if (stackNum == 0) return index_0 == size;
      if (stackNum == 1) return index_1 == 2 * size;
      if (stackNum == 2) return index_2 == 3 * size;
      return false;
    }

    public int pop(int stackNum) {
      if (isEmpty(stackNum)) return -1;
      if (stackNum == 0) return data[--index_0];
      if (stackNum == 1) return data[--index_1];
      if (stackNum == 2) return data[--index_2];
      return -1;
    }

    public int peek(int stackNum) {
      if (isEmpty(stackNum)) return -1;
      if (stackNum == 0) return data[index_0 - 1];
      if (stackNum == 1) return data[index_1 - 1];
      if (stackNum == 2) return data[index_2 - 1];
      return -1;
    }

    public boolean isEmpty(int stackNum) {
      if (stackNum == 0) return index_0 == 0;
      if (stackNum == 1) return index_1 == size;
      if (stackNum == 2) return index_2 == 2 * size;
      return true;
    }
  }

  public static void main(String[] args) {
    TripleInOne tripleInOne = new TripleInOne(3);
    tripleInOne.push(0, 1);
    tripleInOne.push(0, 2);
    System.out.println(tripleInOne.pop(0));
    System.out.println(tripleInOne.pop(0));
    System.out.println(tripleInOne.pop(0));
    tripleInOne.push(1, 2);
    tripleInOne.push(1, 3);
    tripleInOne.push(1, 4);
    System.out.println(tripleInOne.pop(1));
    System.out.println(tripleInOne.pop(1));
    System.out.println(tripleInOne.isEmpty(0));
  }
}
