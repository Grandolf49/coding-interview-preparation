import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.InputMismatchException;

public class Main {

    // Remove following 2 lines while submitting
    static final File ip = new File("input.txt");
    static final File op = new File("output.txt");

    static InputReader in;

    static {
        // Remove try catch block while submitting
        try {
            System.setOut(new PrintStream(op));
            System.setIn(new FileInputStream(ip));
        } catch (Exception e) {
        }

        in = new InputReader(System.in);
    }

    /***
     * Solution
     */
    private static void solve(int t1) {
        int n, k;
        n = in.readInt();
        k = in.readInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            int t = in.readInt();
            arr[i] = t;
        }
        int start = 0, end = 0;
        int sum = 0;
        boolean isExist = false;
        while (start < n && end < n) {
            if (sum + arr[end] <= k) {
                sum += arr[end];
                end++;
                if (sum == k) {
                    isExist = true;
                    end--;
                    break;
                }
            } else {
                sum -= arr[start];
                start++;
            }
        }
        if (isExist) {
            System.out.println((start + 1) + " " + (end + 1));
        } else {
            System.out.println(-1);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

        int t = in.readInt();
        int t1 = 1;
        while (t1 <= t) {
            solve(t1);
            t1++;
        }
    }

    /**
     * A class for Fast Input
     */
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}
