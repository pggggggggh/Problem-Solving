import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;



public class Main {
    static final long MOD = 1000000007L;
    static long fastpow(long a, long b) {
        if (b==0) return 1;
        long x = fastpow(a,b/2);
        if (b%2==1)
            return ((x*x)%MOD)*(a%MOD)%MOD;
        else
            return (x*x)%MOD;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        long ans=1;
        for (int i = 1; i <= n; i++) {
            ans=(ans*i)%MOD;
        }
        long orig=1;
        for (int i = 1; i <= n-r; i++) {
            orig=(orig*i)%MOD;
        }
        for (int i = 1; i <= r; i++) {
            orig=(orig*i)%MOD;
        }
        System.out.println((ans*fastpow(orig,MOD-2))%MOD);

        bw.flush();
        bw.close();
    }
}