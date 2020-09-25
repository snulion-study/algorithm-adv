package sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BJ2170 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] lines = new int[N][2];
        for(int i=0; i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            lines[i][0] = x;
            lines[i][1] = y;
        }

        Comparator cmp = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]) return Integer.compare(o1[1], o2[1]);
                return Integer.compare(o1[0], o2[0]);
            }
        };

        Arrays.sort(lines, cmp);

        long sum = 0;
        long start = lines[0][0], end = lines[0][1];
        for(int i=1; i<N; i++){
            int currentStart = lines[i][0];
            int currentEnd = lines[i][1];
            if(currentStart > end){
                // cannot merge
                sum += Math.abs(end - start);
                start = currentStart;
                end = currentEnd;
            } else {
                // can merge: update end point
                end = Math.max(end, currentEnd);
            }
        }
        sum += (end-start);
        System.out.println(sum);
    }
}
