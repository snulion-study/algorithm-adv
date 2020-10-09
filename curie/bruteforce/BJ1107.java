package bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class BJ1107 {
    static boolean[] broken = new boolean[10]; // 0~10

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        if(N > 0){
            String[] s = br.readLine().split(" ");
            for(int i=0; i<N; i++){
                broken[Integer.parseInt(s[i])] = true;
            }
        }


        if (num == 100){
            System.out.println(0);
            return;
        }
        int min = Math.abs(100 - num);
        for(int i=0; i<1000000; i++){
            int len = isPossible(i);
            if(len > 0) min = Math.min(len + Math.abs(num - i), min);
        }
        System.out.println(min);
    }

    public static int isPossible(int num){
        if(num == 0){
            return broken[0] ? 0 : 1;
        }
        int len = 0;
        while(num > 0){
            int n = num % 10;
            if(broken[n]) return 0;
            num /= 10;
            len++;
        }
        return len;
    }
}
