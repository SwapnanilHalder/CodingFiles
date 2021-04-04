import java.util.*;

import java.io.*;

public class ADAKNG {

    public static Reader scan;
    public static PrintWriter out;

    public static void main (String[] args) throws java.lang.Exception {
        new Thread(null, null, "Thread", 1 << 28) {
            public void run() {
                try {
                    out = new PrintWriter(new BufferedOutputStream(System.out));
                    scan = new Reader(System.in);
                    solve();
                    out.close();
                } catch (Exception len) {
                    len.printStackTrace();
                    System.exit(1);
                }
            }
        }.start();
    }
    public static void solve() {
        int t = scan.nextInt();
        while(t-- > 0) {
            sol();
        }
    }
    static int count = 0;
    static Set< List<Integer> > s = new HashSet<>();
    static void sol() {
        int r = scan.nextInt();
        int c = scan.nextInt();
        int k = scan.nextInt();
        BFS(r, c, k);
        out.println(count);out.flush();
    } 
    static void BFS(int r, int c, int k) {
        if(k == 0) return;
        for(int i = -1; i <= 1; i++) {
            for(int j=-1; j<=1; j++) {
                if(r+i <= 8 && c+j <= 8 ) {
                    if(r+i >=1 && c+j >= 1){
                        if(!s.contains(Arrays.asList(r+i, c+j))) {
                            s.add(Arrays.asList(r+i, c+j));
                            count++;
                            out.print("r+i, c+j, k-1 : " + (r+i) +"  " + (c+j) + "  "+ (k-1) +"\n");out.flush();
                            BFS(r+i, c+j, k-1);
                        }
                        else {
                            out.print("EXISTS , r+i, c+j, k-1 : " + (r+i) +"  " + (c+j) + "  "+ (k-1) +"\n");out.flush();
                            BFS(r+i, c+j, k-1);
                        }
                    }
                }
            }
        }
    }


    public static class Reader { private InputStream stream; private byte[] buf = new byte[4096]; private int curChar, snumChars; public Reader(InputStream stream) { this.stream = stream; } public int read() { if (snumChars == -1) { throw new InputMismatchException(); } if (curChar >= snumChars) { curChar = 0; try { snumChars = stream.read(buf); } catch (IOException E) { throw new InputMismatchException(); } } if (snumChars <= 0) { return -1; } return buf[curChar++]; } public int nextInt() { int c = read(); while (isSpaceChar(c)) { c = read(); } int sgn = 1; if (c == '-') { sgn = -1; c = read(); } int number = 0; do { number *= 10; number += c - '0'; c = read(); } while (!isSpaceChar(c)); return number * sgn; } public long nextLong() { int c = read(); while (isSpaceChar(c)) { c = read(); } long sgn = 1; if (c == '-') { sgn = -1; c = read(); } long number = 0; do { number *= 10L; number += (long) (c - '0'); c = read(); } while (!isSpaceChar(c)); return number * sgn; } public int[] nextIntArray(int n) { int[] arr = new int[n]; for (int i = 0; i < n; i++) { arr[i] = this.nextInt(); } return arr; } public long[] nextLongArray(int n) { long[] arr = new long[n]; for (int i = 0; i < n; i++) { arr[i] = this.nextLong(); } return arr; } public String next() { int c = read(); while (isSpaceChar(c)) { c = read(); } StringBuilder res = new StringBuilder(); do { res.appendCodePoint(c); c = read(); } while (!isSpaceChar(c)); return res.toString(); } public String nextLine() { int c = read(); while (isSpaceChar(c)) { c = read(); } StringBuilder res = new StringBuilder(); do { res.appendCodePoint(c); c = read(); } while (!isEndofLine(c)); return res.toString(); } public boolean isSpaceChar(int c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1; } public boolean isEndofLine(int c) { return c == '\n' || c == '\r' || c == -1; } }
}
