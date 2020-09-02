package com.ooooo;

import java.util.HashMap;
import java.util.Map;

class Solution1 {
  
  public boolean isNumber(String s) {
    Map<State, Map<CharType, State>> transfer = new HashMap<>();
    Map<CharType, State> initialMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_SPACE, State.STATE_INITIAL);
      put(CharType.CHAR_NUMBER, State.STATE_INTEGER);
      put(CharType.CHAR_POINT, State.STATE_POINT_WITHOUT_INT);
      put(CharType.CHAR_SIGN, State.STATE_INT_SIGN);
    }};
    transfer.put(State.STATE_INITIAL, initialMap);
    Map<CharType, State> intSignMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_INTEGER);
      put(CharType.CHAR_POINT, State.STATE_POINT_WITHOUT_INT);
    }};
    transfer.put(State.STATE_INT_SIGN, intSignMap);
    Map<CharType, State> integerMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_INTEGER);
      put(CharType.CHAR_EXP, State.STATE_EXP);
      put(CharType.CHAR_POINT, State.STATE_POINT);
      put(CharType.CHAR_SPACE, State.STATE_END);
    }};
    transfer.put(State.STATE_INTEGER, integerMap);
    Map<CharType, State> pointMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_FRACTION);
      put(CharType.CHAR_EXP, State.STATE_EXP);
      put(CharType.CHAR_SPACE, State.STATE_END);
    }};
    transfer.put(State.STATE_POINT, pointMap);
    Map<CharType, State> pointWithoutIntMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_FRACTION);
    }};
    transfer.put(State.STATE_POINT_WITHOUT_INT, pointWithoutIntMap);
    Map<CharType, State> fractionMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_FRACTION);
      put(CharType.CHAR_EXP, State.STATE_EXP);
      put(CharType.CHAR_SPACE, State.STATE_END);
    }};
    transfer.put(State.STATE_FRACTION, fractionMap);
    Map<CharType, State> expMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_EXP_NUMBER);
      put(CharType.CHAR_SIGN, State.STATE_EXP_SIGN);
    }};
    transfer.put(State.STATE_EXP, expMap);
    Map<CharType, State> expSignMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_EXP_NUMBER);
    }};
    transfer.put(State.STATE_EXP_SIGN, expSignMap);
    Map<CharType, State> expNumberMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_NUMBER, State.STATE_EXP_NUMBER);
      put(CharType.CHAR_SPACE, State.STATE_END);
    }};
    transfer.put(State.STATE_EXP_NUMBER, expNumberMap);
    Map<CharType, State> endMap = new HashMap<CharType, State>() {{
      put(CharType.CHAR_SPACE, State.STATE_END);
    }};
    transfer.put(State.STATE_END, endMap);
    
    int length = s.length();
    State state = State.STATE_INITIAL;
    
    for (int i = 0; i < length; i++) {
      CharType type = toCharType(s.charAt(i));
      if (!transfer.get(state).containsKey(type)) {
        return false;
      } else {
        state = transfer.get(state).get(type);
      }
    }
    return state == State.STATE_INTEGER || state == State.STATE_POINT || state == State.STATE_FRACTION || state == State.STATE_EXP_NUMBER
        || state == State.STATE_END;
  }
  
  public CharType toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
      return CharType.CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
      return CharType.CHAR_EXP;
    } else if (ch == '.') {
      return CharType.CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
      return CharType.CHAR_SIGN;
    } else if (ch == ' ') {
      return CharType.CHAR_SPACE;
    } else {
      return CharType.CHAR_ILLEGAL;
    }
  }
  
  enum State {
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END,
  }
  
  enum CharType {
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL,
  }
  
  private static void test(String s) {
    Solution1 solution = new Solution1();
    boolean is_num = solution.isNumber(s);
    System.out.println(is_num);
  }
  
  public static void main(String[] args) {
    test("0.8"); // true
    test("-1"); // true
    test("-1E-16"); // true
    test("1a3.14"); // false
  }
}