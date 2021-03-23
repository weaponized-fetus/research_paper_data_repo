import java.math.BigInteger;
import java.util.HashSet;

public class bigintVShashset {
    private static int[] sieveOfEratosthenes(int n) {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int c = 0, cur = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {
                c++;
            }
        }
        int[] arr = new int[c];
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {
                arr[cur] = i;
                cur++;
            }
        }
        return arr;
    }

    private static void test(int caseSize) {
        System.out.println("Now testing: " + caseSize + " elements.");
        HashSet<Integer> set = new HashSet<Integer>();
        BigInteger bigint = new BigInteger("1");
        int[] a = sieveOfEratosthenes(caseSize);
        long startTime, endTime, dummy = 0;

        startTime = System.currentTimeMillis();
        for (int i : a) {
            bigint = bigint.multiply(BigInteger.valueOf(i));
        }
        endTime = System.currentTimeMillis();
        System.out.println("Adding items: bigInt: " + (endTime - startTime) + "ms");

        startTime = System.currentTimeMillis();
        for (int i : a) {
            set.add(i);
        }
        endTime = System.currentTimeMillis();
        System.out.println("Adding items: hashSet: " + (endTime - startTime) + "ms");

        startTime = System.currentTimeMillis();
        for (int i : a) {
            if (bigint.mod(BigInteger.valueOf(i)).signum() == 0)
                dummy = i;
        }
        endTime = System.currentTimeMillis();
        System.out.println("Searching items: bigInt: " + (endTime - startTime) + "ms");

        startTime = System.currentTimeMillis();
        for (int i : a) {
            if (set.contains(i))
                dummy = i;
        }
        endTime = System.currentTimeMillis();
        System.out.println("Searching items: hashSet: " + (endTime - startTime) + "ms");
        System.out.println(dummy + "\r       ");
    }

    public static void main(String[] args) {
        for (int i = 2; i < 18; i++) {
            test(2 << i);
        }
    }
}