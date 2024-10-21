import java.util.Scanner;

class Stack<E> {
    int top = -1;
    E[] ar;

    Stack(int max_size) {
        ar = (E[]) new Object[max_size];
    }

    void push(E e) {
        ar[++top] = e;
    }

    int size() {
        return top + 1;
    }

    E pop() {
        E ret = ar[top];
        top--;
        return ret;
    }

    E top() {
        return ar[top];
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        scanner.nextLine();
        for (int t = 0; t < T; t++) {
            int flag = 1;
            String s = scanner.nextLine();
            Stack<Integer> stk = new Stack<>(100);
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') stk.push(i);
                else {
                    if (stk.size() == 0) {
                        flag = 0;
                        break;
                    }
                    stk.pop();
                }
            }

            if (flag == 1 && stk.size() == 0) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
