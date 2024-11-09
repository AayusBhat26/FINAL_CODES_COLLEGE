// 9 Program to run the main thread and perform operations on it. Change the name and priority of the main thread (Java).
public class MainThreadExample {
    public static void main(String[] args) {
        Thread mainThread = Thread.currentThread();
        System.out.println("Initial Main Thread Name: " + mainThread.getName());
        System.out.println("Initial Main Thread Priority: " + mainThread.getPriority());
        mainThread.setName("AayushMainThread");
        mainThread.setPriority(Thread.MAX_PRIORITY);
        System.out.println("\nModified Main Thread Name: " + mainThread.getName());
        System.out.println("Modified Main Thread Priority: " + mainThread.getPriority());
        performOperations();
        System.out.println("\nMain Thread after performing operations:");
        System.out.println("Thread Name: " + mainThread.getName());
        System.out.println("Thread Priority: " + mainThread.getPriority());
    }
    public static void performOperations() {
        System.out.println("\nMain thread is performing operations...");
        for (int i = 1; i <= 5; i++) {
            System.out.println("Performing task " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Thread was interrupted.");
            }
        }

        System.out.println("Main thread operations completed.");
    }
}
