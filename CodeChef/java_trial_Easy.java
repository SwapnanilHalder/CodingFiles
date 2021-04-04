import java.util.*;

public class java_trial_Easy {
    public static void pl(Object line) {
        System.out.println(line);
    }
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int t = scan.nextInt();
        while(t-- > 0) sol();
    }

    static void sol() {
        int n = scan.nextInt();
        int k = scan.nextInt();
        scan.next();
        String[] s = scan.nextLine().split(" ");
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
        System.out.println(count+1);
    } 
}