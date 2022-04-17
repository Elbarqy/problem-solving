import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation {
    private final WeightedQuickUnionUF area;
    private final boolean[] state;
    private int opened = 0;
    private final int size;
    private final int[] directions;

    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException();
        }
        size = n + 1;
        directions = new int[]{-1, 1, size, -1 * size};
        state = new boolean[size * size + size +1];
        area = new WeightedQuickUnionUF(size * size);
        for (int i = 1; i < size; ++i) {
            area.union(0, getIndex(1, i));
            area.union(size, getIndex(size - 1, i));
        }
    }

    public int numberOfOpenSites() {
        return opened;
    }

    public void open(int row, int col) {
        int currentIdx = getIndex(row, col);
        if (!state[currentIdx]) {
            ++opened;
        }
        state[currentIdx] = true;
        for (int dir : directions) {
            int offset = currentIdx + dir;
            if (offset <= 0 || offset > size * size - 1)
                continue;
            if (state[offset])
                area.union(currentIdx, offset);
        }
    }

    public boolean isOpen(int row, int col) {
        return state[getIndex(row, col)];
    }

    public boolean isFull(int row, int col) {
        return area.find(0) == area.find(this.getIndex(row, col)) && isOpen(row, col);
    }

    public boolean percolates() {
        int a = area.find(0);
        int p = area.find(size);
        return area.find(0) == area.find(size);
    }

    public static void main(String[] args) {
        int n = 4;
        Percolation percolation = new Percolation(n);
        while (!percolation.percolates()) {
            percolation.open(StdRandom.uniform(n) + 1, StdRandom.uniform(n) + 1);
        }
    }

    private int getIndex(int row, int col) {
        return row * this.size + col;
    }
}


