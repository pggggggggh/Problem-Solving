import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CountDownLatch;

class FooBar {
    private int n;

    private final List<CountDownLatch> foolatch;
    private final List<CountDownLatch> barlatch;

    public FooBar(int n) {
        this.n = n;
        foolatch = new ArrayList<>(n);
        barlatch = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            foolatch.add(new CountDownLatch(1));
            barlatch.add(new CountDownLatch(1));
        }
        foolatch.getFirst().countDown();
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            foolatch.get(i).await();
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            barlatch.get(i).countDown();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            barlatch.get(i).await();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            if (i < n - 1)
                foolatch.get(i + 1).countDown();
        }
    }
}