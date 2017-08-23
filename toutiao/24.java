import java.util.Scanner;
import java.util.Stack;

/**
 * Created by rui on 2017/8/22.
 */
public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int [] a = new int[n];
        int [] left = new int[n];
        int [] right = new int[n];
        long [] sum = new long[n];
        for (int i = 0; i < n; i++){
            a[i] = in.nextInt();
            if (i > 0) sum[i] = sum[i-1] + a[i];
            else sum[i] = a[i];
        }
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++){
            while (! stack.isEmpty()){
                int c = stack.peek();
                if (a[c] > a[i]) {
                    right[c] = i; stack.pop();
                }else break;
            }
            stack.push(i);
        }
        while (!stack.isEmpty()){
            int c = stack.pop(); right[c] = n;
        }

        for (int i = n-1; i >= 0; i--){
            while (! stack.isEmpty()){
                int c = stack.peek();
                if (a[c] > a[i]) {
                    left[c] = i; stack.pop();
                }else break;
            }
            stack.push(i);
        }
        while (!stack.isEmpty()){
            int c = stack.pop(); left[c] = -1;
        }

        long lsum, rsum;
        long ans = 0;
        for (int i = 0 ; i < n; i++){
            if (left[i] == -1) lsum = 0; else lsum = sum[left[i]];
            rsum = sum[right[i]-1];
            ans = Math.max(ans,(rsum - lsum)*a[i]);
        }
        System.out.println(ans);
    }
}