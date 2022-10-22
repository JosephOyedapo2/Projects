package assignment03;


import java.util.ArrayList;

public class ArrayListQueue1<E> implements Queue<E> {
    ArrayList<E> arr = new ArrayList<E>();

    public ArrayListQueue1() {
        this.arr = arr;
    }

    public boolean isEmpty(){
     return arr.isEmpty();

}

    @Override
public void enqueue(E e) {
    arr.add(e);
}
@Override
public E dequeue() {

       if(arr.isEmpty()) {
           try{
           }
           catch(Exception e){

           }
       }

 return arr.remove(0);

}
@Override
public boolean removeQueue(E e) {
    return arr.isEmpty();
    }
}
