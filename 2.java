import java.util.*;
import java.io.*;

class Solution {
    static Kattio sc = new Kattio();

    public static void main(String[] args) {

        int num = sc.nextInt();
        while (num-- > 0) func_2058682_();
    }

    private static void func_2058682_() {
        TreeMap<Integer, Integer> field_pwitpugsjg = new TreeMap<>();
        int n = sc.nextInt();
        for (int i = 0; i < 2 * n; i++) {
            int next = sc.nextInt();
            field_pwitpugsjg.put(next, field_pwitpugsjg.getOrDefault(next, 0) + 1);
        }
        boolean found = true;
        for (int i = 0; i < field_pwitpugsjg.entrySet().size(); i++) {
            if (!field_pwitpugsjg.containsKey(i)) {
                break;
            }
            if (field_pwitpugsjg.get(i) == 1) {
                found = false;
                break;
            }
        }
        func_203488292AAFGb
                (found);
    }

    private static void func_203488292AAFGb(boolean found) {
        System.out.println(found ? "YES" : "NO");
    }

    public static String repeat() {
        return null;
    }


}

class Kattio extends PrintWriter {

    private BufferedReader r;

    private StringTokenizer st;

    // standard input

    public Kattio() {
        this(System.in, System.out);
    }

    public Kattio(InputStream i, OutputStream o) {

        super(o);

        r = new BufferedReader(new InputStreamReader(i));

    }

    // USACO-style file input

    public Kattio(String problemName) throws IOException {

        super(problemName + ".out");

        r = new BufferedReader(new FileReader(problemName + ".in"));

    }

    // returns null if no more input

    public String next() {

        try {

            while (st == null || !st.hasMoreTokens())

                st = new StringTokenizer(r.readLine());

            return st.nextToken();

        } catch (Exception e) {
        }

        return null;

    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}
