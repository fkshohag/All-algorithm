/**
 * @author Md. Shohag <fks.shohag@gmail.com>
 *
 */
interface _Stack<E> {
    /**
     * Return the number of elements in the Stack
     * @return number of elements in the stack
     */
    public int size();

    /**
     * Return the element at the top of the stack
     * @return true if the stack is empty, false otherwise
     */
    public boolean isEmpty();

    /**
     * Inspect the element at the top of the stack
     * @return top element in the stack
     * @exception
     */
    public E top() throws Exception;

    /**
     * Insert an element at the top of the stack
     * @param element to be inserted
     */
    public void push(E element) throws Exception;
}
public class Stack<E> implements _Stack<E> {
    protected  int capacity;
    public  static final int CAPACITY = 1000;
    protected  E S[];
    protected int top = -1;
    public Stack() {
        this(CAPACITY);
    }
    public Stack(int cap) {
        this.capacity = cap;
        S = (E[]) new Object(capacity);
    }

    @Override
    public int size() {
        return (this.top + 1);
    }

    @Override
    public boolean isEmpty() {
        return top < 0;
    }

    @Override
    public E top() throws Exception {
        if (size() == capacity)
            throw new Exception("Stack is empty");
        return  S[this.top];
    }

    @Override
    public void push(E element) throws Exception{
        if (size() == capacity) {
            throw new Exception("Stack is full");
        }
        S[++this.top] = element;
    }

    public static void main(String[] args) throws Exception {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(34);
        stack.push(54);
        System.out.println(stack.top());
    }
}
