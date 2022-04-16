import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomWord {
    public static void main(String[] args) {
        String string_out = StdIn.readString();
        float i = 2;
        float pPicking = 0.5f;
        while (!StdIn.isEmpty()) {
            String currentString = StdIn.readString();
            if (StdRandom.bernoulli(pPicking)) {
                string_out = currentString;
            }
            ++i;
            pPicking = (1 / i) / pPicking / (i - 1);
        }
        StdOut.print(string_out);
    }
}
