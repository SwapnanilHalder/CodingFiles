class test5 {
    public static void main(String[] args) {
        float f = 4.78956f;
        System.out.println(f);

        int x = 1;
        while(x <= 4) {
            System.out.println("Value of x : " + x);
            x++;
        }
        for(int t = 2; t <= 4; t++) {
            System.out.println("Value of t :   "+ t);
        }

        String array[] = {"Ron", "Harry", "Hermoine"};
        for (String p:array) {
            System.out.println(p);
        }
    }
}