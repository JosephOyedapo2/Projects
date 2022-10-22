package assignment03;
public interface Queue<E> {
    void enqueue(E e); // add e to the end of the queue, allow an exception to happen
    // if the queue is null
    E dequeue(); // remove the element at index 0 and return it. Allow an
    // exception to happen if the queue is empty or null
    boolean removeQueue(E e); // remove first occurrence of e if it is in the queue
    // and return true. Return false if e is not in the queue
    boolean isEmpty(); // return true if the queue is empty, otherwise false
}