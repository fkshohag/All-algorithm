class Node<T> {
    private T element;
    private Node next;
    public Node(T value) {
        this.element = value;
        this.setNext(null);
    }

    public T getElement() {
        return this.element;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getNext() {
        return this.next;
    }
}

public class LinkedList <T> {
    protected Node head;
    protected Node tail;
    protected  long size;
    public LinkedList() {
        head = null;
        size = 0;
    }
    public void insertElement(T value) {
        Node newNode = new Node(value);
        if (this.head == null) {
            this.head = newNode;
            this.tail = this.head;
        } else {
            this.tail.setNext(newNode);
            this.tail = this.tail.getNext();
        }
    }

    public  void listElements() {
        while (this.head != null) {
            System.out.println(this.head.getElement());
            this.head = this.head.getNext();
        }
    }
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertElement("Shohag");
        list.insertElement(34);
        list.listElements();
    }
}
