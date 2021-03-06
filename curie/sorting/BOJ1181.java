package sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1181 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        HashSet<String> set = new HashSet<>();
        for(int i=0; i<N; i++) set.add(br.readLine());

        Comparator<String> cmp = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length() > o2.length()) return 1;
                else if (o1.length() == o2.length()) {
                    return o1.compareTo(o2);
                }
                return -1;
            }
        };

        List<String> list = new ArrayList<String>(set);
        Collections.sort(list, cmp);
        for(String s : list) System.out.println(s);
    }
}
