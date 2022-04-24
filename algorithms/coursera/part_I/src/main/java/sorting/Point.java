package sorting;

import edu.princeton.cs.algs4.StdDraw;

import java.util.Comparator;

public class Point implements Comparable<Point> {

    private final int x;
    private final int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void draw() {
        StdDraw.point(x, y);
    }

    public void drawTo(Point that) {
        StdDraw.line(this.x, this.y, that.x, that.y);
    }

    public double slopeTo(Point that) {
        return (double) (this.y - that.y) / (double) (this.x - that.x);
    }

    public int compareTo(Point that) {
        if (this.y > that.y) return 1;
        if (this.y == that.y) return Integer.compare(this.x, that.x);
        return -1;
    }

    public Comparator<Point> slopeOrder() {
        return new SlopeOrder();
    }

    private class SlopeOrder implements Comparator<Point> {
        @Override
        public int compare(Point point, Point t1) {
            double p1Slope = slopeTo(point);
            double p2Slope = slopeTo(t1);
            return Double.compare(p1Slope, p2Slope);
        }
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public static void main(String[] args) {
    }
}