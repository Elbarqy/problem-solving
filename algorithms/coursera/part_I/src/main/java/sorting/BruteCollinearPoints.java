package sorting;

import java.util.ArrayList;

public class BruteCollinearPoints {
    private Point[] points;
    private LineSegment[] colinearSegments;

    public BruteCollinearPoints(Point[] points) {
        if (points == null) throw new IllegalArgumentException();
        this.points = points;
        ArrayList<LineSegment> results = new ArrayList<>();
        int size = 0;
        if (points.length >= 4) for (int i = 0; i < points.length; ++i)
            for (int j = i + 1; j < points.length; ++j)
                for (int k = j + 1; k < (points.length - 1); ++k)
                    for (int s = k + 1; s < (points.length); ++s)
                        if (points[i].slopeTo(points[j]) == points[i].slopeTo(points[s]) && points[i].slopeTo(points[j]) == points[i].slopeTo(points[k])) {
                            LineSegment lineSegment = new LineSegment(points[i], points[s]);
                            if (!results.contains(lineSegment)) {
                                results.add(lineSegment);
                                ++size;
                            }
                        }

        colinearSegments = results.toArray(new LineSegment[size]);
    }    // finds all line segments containing 4 points

    public int numberOfSegments() {
        return colinearSegments.length;
    }    // the number of line segments

    public LineSegment[] segments() {
        return colinearSegments;
    }
}
