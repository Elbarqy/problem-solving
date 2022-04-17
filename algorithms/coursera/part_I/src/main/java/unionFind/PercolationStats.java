import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final double stdDev;
    private final double mean;
    private final int t;

    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) {
            throw new IllegalArgumentException();
        }
        this.t = trials;
        int k = 0;
        double[] estimates = new double[trials];
        while (trials != k) {
            Percolation percolation = new Percolation(n);
            while (!percolation.percolates()) {
                percolation.open(StdRandom.uniform(n) + 1, StdRandom.uniform(n) + 1);
            }
            estimates[k++] = percolation.numberOfOpenSites() * 1.0 / (n * n * 1.0);
        }
        mean = StdStats.mean(estimates);
        stdDev = StdStats.stddev(estimates);
    }

    public double mean() {
        return mean;
    }

    public double stddev() {
        return stdDev;
    }

    public double confidenceLo() {
        return mean - (1.96 * stdDev / (Math.sqrt(t)));
    }

    public double confidenceHi() {
        return mean + (1.96 * stdDev / (Math.sqrt(t)));
    }

    public static void main(String[] args) {
        //args[0] = n \\ args[1] = t
        int n = StdIn.readInt();
        int t = StdIn.readInt();
        PercolationStats percolationStats = new PercolationStats(n, t);
        StdOut.printf("mean                    = %f\n", percolationStats.mean);
        StdOut.printf("stddev                  = %f\n", percolationStats.stdDev);
        StdOut.println("95% confidence interval = [" + percolationStats.confidenceLo() + ", " + percolationStats.confidenceHi() + "]");
    }

}
