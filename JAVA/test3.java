import java.io.*;
import java.util.*;
class Shape
{
    double sa;
    void Area()
    {
       
        System.out.println("Surface Area is");
       
    }
}
class RectangleArea extends Shape
{
    int l,w;
 
    RectangleArea(int l1,int w1)
    {
        l=l1;
        w=w1;
    }
     void Area()
    {
        int sa1;
        sa1=(l*w);
        System.out.println("Area of Rectangle :"+sa1);
    }
}
class SquareArea extends Shape
{
    int a;
     
    SquareArea(int a1)
    {
        a=a1;
    }
     void Area()
    {
        int sa2;
        sa2=a*a;
       
        System.out.println("Area of Square :"+sa2);
    }
     
}
class CircleArea extends Shape
{
   double r;
     
           
    CircleArea(double r1)
    {
       r=r1;
    }
     void Area()
    {
       double sa3;
       sa3=3.141592653589*r*r;
       String strDouble = String.format("%.2f", sa3);
       System.out.println("Area of Circle :"+strDouble);
     }
}
class test3 {

    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            String ch;
            ch=sc.next();
            switch(ch)
            {
                case "RECTANGLE":
               
                int len, wid;
                len=sc.nextInt();
                wid=sc.nextInt();
                if(len>0 && wid>0){
                    RectangleArea b= new RectangleArea(2,6);
                    b.l=len;
                    b.w=wid;
                    b.Area();
                }
               
               
                break;
                case "SQUARE":
                SquareArea c = new SquareArea(7);
                int length;
                length=sc.nextInt();
                if(length>0){
                    c.a=length;
                    c.Area();
                }
                break;
               
                case "CIRCLE":
                double rad;
                rad=sc.nextDouble();
                if(rad>0){
                    CircleArea c1= new CircleArea(2.0);
                    c1.r=rad;
                    c1.Area();

                }
               
                break;
               
                default:
                System.out.println("Invalid input");
           
           
            }
        }
    }