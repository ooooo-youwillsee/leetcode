package com.ooooo;

/**
 * 每个cube可以贡献的表面积
 */
class Solution1 {
  
  public int surfaceArea(int[][] grid) {
    int[] dr = new int[]{0, 1, 0, -1};
    int[] dc = new int[]{1, 0, -1, 0};
    
    int N = grid.length;
    int ans = 0;
    
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        if (grid[r][c] > 0) {
          ans += 2;
          for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            int nv = 0;
            if (0 <= nr && nr < N && 0 <= nc && nc < N)
              nv = grid[nr][nc];
            
            ans += Math.max(grid[r][c] - nv, 0);
          }
        }
      }
    }
    return ans;
  }
  
  
  private static void test(int[][] grid) {
    Solution1 solution = new Solution1();
    int sum = solution.surfaceArea(grid);
    System.out.println(sum);
  }
  
  public static void main(String[] args) {
    test(new int[][]{
        {1, 2}, {3, 4}
    }); // 34
    
    test(new int[][]{
        {1, 1, 1}, {1, 0, 1}, {1, 1, 1}
    }); // 32
    
    test(new int[][]{
        {1, 0}, {0, 2}
    }); // 16
    
    test(new int[][]{
        {2, 2, 2}, {2, 1, 2}, {2, 2, 2}
    }); // 46
  }
}