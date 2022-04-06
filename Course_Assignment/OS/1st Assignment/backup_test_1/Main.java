import java.io.*;
class g implements Runnable{
    int num;
    public void run( ){
       System.out.print(num);
       try { 
           Thread.sleep(3142);
        }
       catch ( Exception e ){ }
       System.out.print(num);
    }
}
class Main{
    public static void main(String k[]) throws Exception{
        g obj; Thread a,b;
        obj = new g(); 
        obj.num = 34;
        a = new Thread(obj);
        a.start();
        obj = new g(); 
        obj.num = 78;
        Thread.sleep(703);
        b = new Thread(obj);
        b.start();
   }  
}