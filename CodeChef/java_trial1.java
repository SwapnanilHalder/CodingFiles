import java.util.*;
import java.io.*;

public class java_trial1 {

    public static Reader sc;
    public static PrintWriter out;

    public static void main (String[] args) throws java.lang.Exception {
		new Thread(null, null, "Thread", 1 << 28) {
			public void run() {
				try {
					out = new PrintWriter(new BufferedOutputStream(System.out));
					sc = new Reader(System.in);
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
		int t = sc.nextInt();
		while(t-- > 0) sol();
	}

    static void sol() {
        int n = sc.nextInt();
        int k = sc.nextInt();
		int[] s = sc.nextIntArray(n);
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i :s) arr.add(i);

        int count = 0;
        for(int i =0; i< arr.size(); i++) {
			if(arr.get(i) >= k) {
				if(i <= n-2) {
					count++;
					arr.set(i+1, arr.get(i+1) + arr.get(i) - k);
				}
				else {
					count += Math.ceil(arr.get(n-1) / k);
				}
			}
			else break;
        }
        out.println(count+1);
        out.flush();
    } 



    public static class Reader { private InputStream stream; private byte[] buf = new byte[4096]; private int curChar, snumChars; public Reader(InputStream stream) { this.stream = stream; } public int read() { if (snumChars == -1) { throw new InputMismatchException(); } if (curChar >= snumChars) { curChar = 0; try { snumChars = stream.read(buf); } catch (IOException E) { throw new InputMismatchException(); } } if (snumChars <= 0) { return -1; } return buf[curChar++]; } public int nextInt() { int c = read(); while (isSpaceChar(c)) { c = read(); } int sgn = 1; if (c == '-') { sgn = -1; c = read(); } int number = 0; do { number *= 10; number += c - '0'; c = read(); } while (!isSpaceChar(c)); return number * sgn; } public long nextLong() { int c = read(); while (isSpaceChar(c)) { c = read(); } long sgn = 1; if (c == '-') { sgn = -1; c = read(); } long number = 0; do { number *= 10L; number += (long) (c - '0'); c = read(); } while (!isSpaceChar(c)); return number * sgn; } public int[] nextIntArray(int n) { int[] arr = new int[n]; for (int i = 0; i < n; i++) { arr[i] = this.nextInt(); } return arr; } public long[] nextLongArray(int n) { long[] arr = new long[n]; for (int i = 0; i < n; i++) { arr[i] = this.nextLong(); } return arr; } public String next() { int c = read(); while (isSpaceChar(c)) { c = read(); } StringBuilder res = new StringBuilder(); do { res.appendCodePoint(c); c = read(); } while (!isSpaceChar(c)); return res.toString(); } public String nextLine() { int c = read(); while (isSpaceChar(c)) { c = read(); } StringBuilder res = new StringBuilder(); do { res.appendCodePoint(c); c = read(); } while (!isEndofLine(c)); return res.toString(); } public boolean isSpaceChar(int c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1; } public boolean isEndofLine(int c) { return c == '\n' || c == '\r' || c == -1; } }
}
