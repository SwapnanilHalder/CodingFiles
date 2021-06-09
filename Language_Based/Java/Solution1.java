import java.util.*;

public class Solution1 {
    public static void pl(Object line) {
        System.out.println(line);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        for(int i=1; i<11; i++) {
            pl(k+" x "+i+" = "+k*i);
        }
    }
}
