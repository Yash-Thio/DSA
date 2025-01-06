package JavaCode;
import java.util.*;
@SuppressWarnings("unused")
public class ClassWithinAClass {
    static class Inner1{
        void disp(){
            System.out.println("inner 1");
        }
    }
    static class Inner2{
        void disp(){
            System.out.println("inner 2");
        }
    }
    public static void main(String[] args){
        ClassWithinAClass.Inner1 obj1 = new Inner1();
        ClassWithinAClass.Inner2 obj2 = new ClassWithinAClass.Inner2();
        obj1.disp();
        obj2.disp();
    }
}
