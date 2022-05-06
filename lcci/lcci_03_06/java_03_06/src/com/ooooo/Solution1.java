package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author lzj
 * @since 2020/5/14 14:22
 */
public class Solution1 {

  static class AnimalShelf {

    Queue<Integer[]> cats, dogs;

    public AnimalShelf() {
      cats = new LinkedList<>();
      dogs = new LinkedList<>();
    }

    public void enqueue(int[] animal) {
      Integer[] e = new Integer[]{animal[0], animal[1]};
      if (e[1] == 0) cats.add(e);
      else dogs.add(e);
    }

    public int[] dequeueAny() {
      if (cats.isEmpty() && dogs.isEmpty()) return new int[]{-1, -1};
      if (cats.isEmpty()) return dequeueDog();
      if (dogs.isEmpty()) return dequeueCat();
      if (cats.peek()[0] > dogs.peek()[0]) return dequeueDog();
      return dequeueCat();
    }

    public int[] dequeueDog() {
      if (dogs.isEmpty()) return new int[]{-1, -1};
      Integer[] e = dogs.poll();
      return new int[]{e[0], e[1]};
    }

    public int[] dequeueCat() {
      if (cats.isEmpty()) return new int[]{-1, -1};
      Integer[] e = cats.poll();
      return new int[]{e[0], e[1]};
    }
  }

  public static void main(String[] args) {
    AnimalShelf shelf = new AnimalShelf();
    shelf.enqueue(new int[]{0, 0});
    shelf.enqueue(new int[]{1, 0});
    System.out.println(shelf.dequeueCat());
    System.out.println(shelf.dequeueDog());
    System.out.println(shelf.dequeueAny());
  }


}
