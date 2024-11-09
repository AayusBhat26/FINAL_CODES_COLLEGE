// 10. Program to illustrate the working of child threads in concurrence with the main thread (Java).
class ChildThread extends Thread {
    public void run() {
        System.out.println(Thread.currentThread().getName() + " - Child thread is starting...");
        for (int i = 1; i <= 5; i++) {
            System.out.println(Thread.currentThread().getName() + " - Task " + i);
            try {
                Thread.sleep(500); // Simulate work for 500ms
            } catch (InterruptedException e) {
                System.out.println(Thread.currentThread().getName() + " - Interrupted");
            }
        }
        System.out.println(Thread.currentThread().getName() + " - Child thread is finished.");
    }
}

public class MainThreadWithChild {
    public static void main(String[] args) {
        Thread mainThread = Thread.currentThread();
        System.out.println(mainThread.getName() + " - Main thread is starting...");
        ChildThread child1 = new ChildThread();
        ChildThread child2 = new ChildThread();
        child1.start();
        child2.start();
        for (int i = 1; i <= 5; i++) {
            System.out.println(mainThread.getName() + " - Main thread task " + i);
            try {
                Thread.sleep(700);
            } catch (InterruptedException e) {
                System.out.println(mainThread.getName() + " - Interrupted");
            }
        }
        try {
            child1.join(); 
            child2.join(); 
        } catch (InterruptedException e) {
            System.out.println(mainThread.getName() + " - Interrupted while waiting for children.");
        }
        System.out.println(mainThread.getName() + " - Main thread is finished.");
    }
}
