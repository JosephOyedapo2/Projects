package assignment03;


public class Tester {
    public static void main(String[]args) {
        ArrayListQueue1<String> arr1 = new ArrayListQueue1<String>();
        ArrayListQueue2<String> arr2 = new ArrayListQueue2<>();
        arr1.enqueue("macos");
        arr1.enqueue("linux");
        arr1.enqueue("window");
        try{
            arr1.enqueue("");
        }
        catch(Exception e){
            System.out.println("Exception occured.");


        }

        arr2.enqueue("macos");
        arr2.enqueue("linux");
        arr2.enqueue("window");

        try{
            arr2.enqueue("");
        }
        catch(Exception e){
            System.out.println("Exception occured.");
        }
        System.out.println(arr1);
        System.out.println(arr2);


        String data = arr1.dequeue();
        String data2 = arr2.dequeue();
        System.out.println(data);
        System.out.println(data2);
    }


}
