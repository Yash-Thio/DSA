package JavaCode;
import java.util.*;
@SuppressWarnings("unused")
class MyException extends Exception{
    MyException(String name){
        super(name);
    }
}
class Mayank{
        static void Yash(String exceptionName) throws MyException{
            throw new MyException(exceptionName);
        }
        static void Aditya(String name) throws MyException{
                for (int i = 0; i < 10; i++){
                    if(i==5){
                        Yash("Error i = 5 " + name);
                }
            }
        }
        static void Aniket(String name) throws MyException{
                    System.out.println("arithmetic exception from thread " + name);
                    int y = 99 / 0;
                    System.out.println(y);
                }
}

public class ExceptionTester extends Mayank {
    public static void main(String[] args) {
        Thread Aditya = new Thread(()->{
            System.out.println("Aditya thread start");
                try {
                        Mayank.Aditya(Thread.currentThread().getName());
                    } catch (MyException e) {
                        // e.printStackTrace();
                        System.out.println(e.getMessage());
                    }finally{
                        System.out.println("Aditya thread over");
                    }
            },"Aditya");
        Thread Aniket = new Thread(()->{
            System.out.println("Aniket thread start");
            try {
                    Mayank.Aniket(Thread.currentThread().getName());
                } catch (MyException e) {
                    // e.printStackTrace();
                    System.out.println(e.getMessage());
                }finally{
                    System.out.println("Aniket thread over");
                }
        },"Aniket");
        Aditya.start();
        try {
            Aditya.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        Aniket.start();
        try {
            Aniket.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
   
}

