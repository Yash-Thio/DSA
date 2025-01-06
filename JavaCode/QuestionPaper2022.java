package JavaCode;

import java.util.*;

interface Readable{
    String read();
}
class TextMessage implements Readable{
    String sender, content;
    TextMessage(String sender, String content){
        this.sender = sender;
        this.content = content;
    }
    public String getSender(){
        return this.sender;
    }
    @Override
    public String read() {
        return this.content;
    }

}
class EBook implements Readable{
    private String name; 
    private int pageNumber;
    private ArrayList<String> page = new ArrayList<>();
    EBook(String name, ArrayList<String> page, int pageNumber){
        this.name = name;
        this.pageNumber = pageNumber;
        for(String p : page){
            this.page.add(p);
        }
    }
    public String getName(){
        return this.name;
    }
    ArrayList<String> page(){
        return this.page;
    }
    public void nextPage(){
        int MAX_PAGE = this.page.size() - 1;
        if(this.pageNumber % MAX_PAGE == 0){
            this.pageNumber = 0; 
        }else{
            this.pageNumber = this.pageNumber + 1;
        }
    }
    @Override
    public String read() {
        String nextPage = this.page.get(this.pageNumber);
        return nextPage;
    }
    
}
public class QuestionPaper2022 {
    static void disp(String str){
            System.out.println(str);
        }
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            TextMessage objText = new TextMessage("Mayank Jha","Aditya mast admi hai.");
            ArrayList<String> page = new ArrayList<>();
            System.out.println("Enter number of pages");
            int numberOfPages = sc.nextInt();
            sc.nextLine();
            System.out.println("Keep entering content of each page switch page by pressing enter");
            for(int i = 0; i < numberOfPages; i++){
                System.out.println(i);
                String str = sc.nextLine();
                page.add(str);    
            }
            System.out.println("Enter Name of Book");
            String name = sc.nextLine();
            EBook objBook = new EBook(name,page,0);
            for(int i = 0; i<numberOfPages;i++){
                objBook.nextPage();
                disp(objBook.read());
            }
            System.out.println(objText.getSender());
            System.out.println(objText.read());
            sc.close();
    }
}
