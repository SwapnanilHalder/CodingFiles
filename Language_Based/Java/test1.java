public class test1 {
    static int x = 11;
    private int y = 33;
    public void method1(int x) {
        test1 t = new test1();
        this.x = 22;
        y = 44;

        System.out.println("test1.x: " + test1.x);
        System.out.println("t.x: " + t.x);
        System.out.println("t.y: " + t.y);
        System.out.println("y: " + y);
    }

    public static void main(String[] args) {
        test1 t = new test1();
        t.method1(5);
    }
}