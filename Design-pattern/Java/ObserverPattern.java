import java.util.ArrayList;
import java.util.List;

interface Subject {
    void subscribe(Subscriber sub);

    void unsubscribe(Subscriber sub);

    void notifySubscriber();

    void uploadVideo(String title);
}

interface Observer {
    void update();

    void subscribeChannel(Channel ch);
}

class Channel implements Subject {
    private String title;
    private List<Subscriber> subs = new ArrayList<>();

    @Override
    public void subscribe(Subscriber sub) {
        subs.add(sub);
    }

    @Override
    public void unsubscribe(Subscriber sub) {
        subs.remove(sub);
    }

    @Override
    public void notifySubscriber() {
        for (Subscriber s : subs) {
            s.update();
        }
    }

    public String getTitle() {
        return title;
    }

    @Override
    public void uploadVideo(String title) {
        this.title = title;
        this.notifySubscriber();
    }
}

class Subscriber implements Observer {
    private String name;
    private Channel channel = new Channel();

    Subscriber(String name) {
        this.name = name;
    }

    @Override
    public void update() {
        System.out.println("Hello, " + this.name + " new video uploaded in " + this.channel.getTitle());
    }

    @Override
    public void subscribeChannel(Channel ch) {
        this.channel = ch;
    }
}

public class ObserverPattern {
    public static void main(String[] args) {
        Channel openBook = new Channel();
        Subscriber s1 = new Subscriber("Shohag");
        Subscriber s2 = new Subscriber("kABIR");
        openBook.subscribe(s1);
        openBook.subscribe(s2);
        s1.subscribeChannel(openBook);
        s2.subscribeChannel(openBook);
        openBook.uploadVideo("Funny video");
    }
}
