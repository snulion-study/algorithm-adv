package bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
public class BJ1759 {

    public static boolean[] visited;
    public static char[] chars;
    public static int L;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        L  = Integer.parseInt(s[0]);
        int C = Integer.parseInt(s[1]);
        chars = new char[C];
        chars = br.readLine().replaceAll("\\s","").toCharArray();
        Arrays.sort(chars);
        visited = new boolean[C];
        for(int i=0; i<C; i++){
            if(i + L > C) continue;
            visited[i] = true;
            generatePW(Character.toString(chars[i]), i);
            visited[i] = false;
        }
    }

    public static boolean isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    public static void generatePW(String curr, int index){
        if(curr.length() == L){
            if(isValid(curr)) System.out.println(curr);
            return;
        }
        for(int i = index+1; i < chars.length; i++){
            if(visited[i]) continue;
            visited[i] = true;
            generatePW(curr + chars[i], i);
            visited[i] = false;
        }
    }

    public static boolean isValid(String s){
        int ja = 0;
        int mo = 0;
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(isVowel(c)) mo++;
            else ja ++;
        }

        return ja >= 2 && mo >= 1;
    }
}
