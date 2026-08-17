import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

class ZeroEvenOdd {
    private int n;
    private final Semaphore zeroturn = new Semaphore(1);
    private final Semaphore eventurn = new Semaphore(0);
    private final Semaphore oddturn = new Semaphore(0);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            zeroturn.acquire();
            printNumber.accept(0);
            if (i % 2 == 0) oddturn.release();
            else eventurn.release();
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            eventurn.acquire();
            printNumber.accept(i);
            zeroturn.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            oddturn.acquire();
            printNumber.accept(i);
            zeroturn.release();
        }
    }
}