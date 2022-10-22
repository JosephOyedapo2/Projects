package assignment03;
import java.util.ArrayList;


public class ArrayListQueue2<E> extends ArrayList<E> implements Queue<E>  {


    @Override
    public void enqueue(E e) {
        this.add(e);

    }

    @Override
    public E dequeue() {
        return this.remove(0);
    }

    @Override
    public boolean removeQueue(E e) {
       return this.isEmpty();
    }
}
