import java.util.*;

public class printLn_shortcut {
    public static void pl(Object line) {
        System.out.println(line);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        pl("================================");
        for(int i=0; i<3; i++) {
            String s = scan.next();
            int p = scan.nextInt();
            System.out.printf("%-15s%03d%n", s, p);
        }
        pl("================================");
    }
}