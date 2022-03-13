import java.io.*;
class g implements Runnable
{ public void run()
  {
    DataInputStream z=new DataInputStream(System.in);
    try{String s;s=z.readLine();}catch(Exception e){}
  }
}
public class class_note
{ public static void main(String ar[]) throws Exception
 {
    g x=new g();
    Thread t=new Thread(x);
    t.run();
    Thread k=new Thread (x);
    k.start();
    int diff = 0;
    while(k.isAlive()) {Thread.sleep(1000);diff++;}
    System.out.println(diff);
  }
}