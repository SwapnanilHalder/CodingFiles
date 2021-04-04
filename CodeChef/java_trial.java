import java.util.*;
import java.io.*;

class java_trial {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Reader scan = new Reader();
    static Scanner scanner = new Scanner(System.in);
    public static void main (String[] args) throws java.lang.Exception {
        int t = scan.nextInt();
        while(t-- > 0) sol();
    }
    static void sol() throws java.lang.Exception {
        int n = scan.nextInt();
        int k = scan.nextInt();
        String s[] = scanner.nextLine().split(" ");
        ArrayList<Integer> arr = new ArrayList<>();
        for(String i :s) arr.add(Integer.parseInt(i));
        // for(int i: arr) pl(i);pl("\n");

        int count = 0;
        for(int i =0; i< arr.size(); i++) {
            if(i <= n-2){
                if(arr.get(i) >= k) {
                    count++;
                    arr.set(i+1, arr.get(i+1) + arr.get(i) - k);
                }
                else break;
            }
            else {
                arr.add(0);
                if(arr.get(i) >= k) {
                    count++;
                    arr.set(i+1, arr.get(i+1) + arr.get(i) - k);
                }
                else break;
            }

        }
        pl(count+1);
        // br.close();
    } 

    static void print(Object s) {System.out.print(s + " ");}
    static void pl(Object s) {System.out.print(s + "\n");}
    static class Reader { final private int BUFFER_SIZE = 1 << 16; private DataInputStream din; private byte[] buffer; private int bufferPointer, bytesRead; public Reader() { din = new DataInputStream(System.in); buffer = new byte[BUFFER_SIZE]; bufferPointer = bytesRead = 0; } public Reader(String file_name) throws IOException { din = new DataInputStream(new FileInputStream(file_name)); buffer = new byte[BUFFER_SIZE]; bufferPointer = bytesRead = 0; } public String readLine() throws IOException { byte[] buf = new byte[64]; int cnt = 0, c; while ((c = read()) != -1) { if (c == '\n') break; buf[cnt++] = (byte) c; } return new String(buf, 0, cnt); } public int nextInt() throws IOException { int ret = 0; byte c = read(); while (c <= ' ') c = read(); boolean neg = (c == '-'); if (neg) c = read(); do { ret = ret * 10 + c - '0'; } while ((c = read()) >= '0' && c <= '9'); if (neg) return -ret; return ret; } public long nextLong() throws IOException { long ret = 0; byte c = read(); while (c <= ' ') c = read(); boolean neg = (c == '-'); if (neg) c = read(); do { ret = ret * 10 + c - '0'; } while ((c = read()) >= '0' && c <= '9'); if (neg) return -ret; return ret; } public double nextDouble() throws IOException { double ret = 0, div = 1; byte c = read(); while (c <= ' ') c = read(); boolean neg = (c == '-'); if (neg) c = read(); do { ret = ret * 10 + c - '0'; } while ((c = read()) >= '0' && c <= '9'); if (c == '.') { while ((c = read()) >= '0' && c <= '9') { ret += (c - '0') / (div *= 10); } } if (neg) return -ret; return ret; } private void fillBuffer() throws IOException { bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); if (bytesRead == -1) buffer[0] = -1; } private byte read() throws IOException { if (bufferPointer == bytesRead) fillBuffer(); return buffer[bufferPointer++]; } public void close() throws IOException { if (din == null) return; din.close(); } }
}