package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/9 13:52
 */
public class Solution2 {


  static class TripleInOne {

    private ArrayStack s1, s2, s3;
    private int[] data;

    private static class ArrayStack {

      private int start, end, cur; // [start, end)
      private int[] data;

      public ArrayStack(int start, int end, int[] data) {
        this.start = this.cur = start;
        this.end = end;
        this.data = data;
      }

      public void push(int value) {
        if (cur == end) return;
        data[cur++] = value;
      }

      public int peek() {
        if (isEmpty()) return -1;
        return data[cur - 1];
      }

      public int pop() {
        if (isEmpty()) return -1;
        return data[--cur];
      }

      public boolean isEmpty() {
        return cur == start;
      }
    }


    public TripleInOne(int stackSize) {
      this.data = new int[stackSize * 3];
      s1 = new ArrayStack(0, stackSize, data);
      s2 = new ArrayStack(stackSize, 2 * stackSize, data);
      s3 = new ArrayStack(2 * stackSize, 3 * stackSize, data);
    }

    private ArrayStack getStack(int stackNum) {
      switch (stackNum) {
        case 0:
          return s1;
        case 1:
          return s2;
        case 2:
          return s3;
      }
      return null;
    }

    public void push(int stackNum, int value) {
      getStack(stackNum).push(value);
    }

    public int pop(int stackNum) {
      return getStack(stackNum).pop();
    }

    public int peek(int stackNum) {
      return getStack(stackNum).peek();
    }

    public boolean isEmpty(int stackNum) {
      return getStack(stackNum).isEmpty();
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
