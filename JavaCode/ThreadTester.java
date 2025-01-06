package JavaCode;
import java.util.*;
@SuppressWarnings("unused")
public class ThreadTester{
    public static void main(String[] args) {
        System.out.println("main start");
        Thread thread1 = new Thread1("thread1");
        Thread thread2 = new Thread1("thread2");
        Thread thread3 = new Thread(()->{
            for (int i=0;i<10;i++){
                System.out.println(Thread.currentThread().getName() + " " + i + " " + Thread.currentThread().getState());
                if(i==5){
                    try{
                        Thread.sleep(1000);
                        System.out.println(Thread.currentThread().getName() + " " + i + " " +  Thread.currentThread().getState());
                    }catch(InterruptedException e){
                        System.out.println(e);
                    }
                }
            }
        },"thread3");
        thread3.setDaemon(true);
        thread3.start();
        thread1.start();
        thread2.start();
        new Thread(() -> {
            try {
                while (thread1.isAlive() || thread2.isAlive() || thread3.isAlive()) {
                    System.out.println("Monitor: " + thread1.getName() + " is " + thread1.getState());
                    System.out.println("Monitor: " + thread2.getName() + " is " + thread2.getState());
                    System.out.println("Monitor: " + thread3.getName() + " is " + thread3.getState());
                    Thread.sleep(50); // Poll states periodically
                }
            } catch (InterruptedException e) {
                System.out.println("Monitor interrupted: " + e);
            }
        }, "StateMonitor").start();
        try{
            thread2.join();
        }catch(InterruptedException e){
            System.out.println(e);
        }
        System.out.println("main end");
    }
}
class Thread1 extends Thread{
    
    public Thread1(String name){
        super(name);
    }
    @Override
    public void run(){
        for (int i=0;i<10;i++){
            System.out.println(Thread.currentThread().getName() + " " + i + " " +  Thread.currentThread().getState());
            if(i==5){
                try{
                    Thread.sleep(100);
                    System.out.println(Thread.currentThread().getName() + " " + i + " " +  Thread.currentThread().getState());
                }catch(InterruptedException e){
                    System.out.println(e);
                }
            }
        }
    }
}