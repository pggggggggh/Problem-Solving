import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int T;
    static int N;
    static boolean[] finished, visited;
    static int[] node;
    static int answer;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());
        sb = new StringBuilder();
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            finished = new boolean[N + 1];
            visited = new boolean[N + 1];
            node = new int[N + 1];
            answer = 0;

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                node[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 1; i <= N; i++) {
                if (visited[i]) continue;
                dfs(i);
            }

            sb.append(N - answer).append("\n");
        }

        System.out.println(sb);
    }

    private static void dfs(int u) {
        int v = node[u];
        visited[u] = true;

        if (!visited[v]) {
            dfs(v);
        } else if (!finished[v]) {
            check(v);
        }

        finished[u] = true;
    }

    private static void check(int u) {
        finished[u] = true;
        answer++;
        if (!finished[node[u]]) check(node[u]);
    }
}