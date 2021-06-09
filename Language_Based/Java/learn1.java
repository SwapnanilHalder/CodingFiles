
public class learn1 {
    public static void main(final String[] args) {
        String s1 = new String("Hello How are you?");
        System.out.println("s1: " + s1);
        String s2 = "\nI am fine mister";
        System.out.println("s2: " + s2);
        String sconcat = s1 + s2;
        System.out.println("concat : " + sconcat);

        int num = 5;
        String s = "I have " + num + " cookies";
        System.out.println(s);

        int[] arr1 = new int[1];
        int[] arr = {5,4,8,9,2,3,6,7,1};
        for (int i : arr) {
            System.out.print(i+ "  ");
        }
    }
}