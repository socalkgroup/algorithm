class RotateImage {
    public void rotate(int[][] matrix) {
        // Let s denote start row/column and e end row/column.
        for (int s = 0, e = matrix.length-1; s < e; s++, e--) {
            for (int i = s; i < e; i++) {
                int j        = matrix.length - 1 - i;
                int temp     = matrix[s][i];
                matrix[s][i] = matrix[j][s];
                matrix[j][s] = matrix[e][j];
                matrix[e][j] = matrix[i][e];
                matrix[i][e] = temp;
            }
        }
    }
}
