public class Solution {
   char[][] g;
   public int numIslands(char[][] grid) {
       int islands = 0;
       g = grid;
       for (int i=0; i<g.length; i++)
           for (int j=0; j<g[i].length; j++)
               islands += sink(i, j);
       return islands;
   }
   int sink(int i, int j) {
       if (i < 0 || i == g.length || j < 0 || j == g[i].length || g[i][j] == '0')
           return 0;
       g[i][j] = '0';
       sink(i+1, j); sink(i-1, j); sink(i, j+1); sink(i, j-1);
       return 1;
   }
}
