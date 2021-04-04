import java.util.*;

class CHEFNSWPS {
    public static void main(String[] args) throws java.lang.Exception {
        // your code goes here
        Scanner s = new Scanner(System.in);
        int testcases = s.nextInt();
        for (int t = 0; t < testcases; t++) {
            int n = s.nextInt();
            int[] a = new int[10];
            int[] b = new int[10];
            for (int i = 0; i < n; i++) {
                int temp = s.nextInt();
                a[temp]++;
            }
            for (int i = 0; i < n; i++) {
                int temp = s.nextInt();
                b[temp]++;
            }
            if (Arrays.equals(a, b))
                System.out.println("0");
            else {
                boolean quit = false;
                int[] total = new int[10];
                for (int i = 0; i < 10; i++) {
                    total[i] = a[i] + b[i];
                    if (total[i] % 2 == 1) {
                        quit = true;
                        break;
                    }
                }
                if (quit)
                    System.out.println("-1");
                else {
                    int swaps = 0;
                    for (int i = 0; i < 10; i++) {
                        swaps = swaps + Math.abs(a[i] - b[i]);
                    }
                    swaps = swaps / 4;
                    int j = 0;
                    int count = 0;
                    while (swaps > 0) {
                        if (a[j] != b[j]) {
                            int temp = Math.abs(a[j] - b[j]) / 2;
                            if (temp < swaps) {
                                count = count + temp * j;
                                swaps = swaps - temp;
                            } else {
                                count = count + swaps * j;
                                swaps = 0;
                            }
                        }
                        j++;
                    }
                    System.out.println(count);
                }
            }
        }
        s.close();
    }
}