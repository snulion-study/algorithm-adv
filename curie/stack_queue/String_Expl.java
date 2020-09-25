package stack_queue;

import java.io.IOException;
import java.util.Scanner;

public class String_Expl {

    public static void main(String[] args) throws IOException {
        Scanner sc =new Scanner(System.in);
        String str = sc.nextLine();
        String bomb = sc.nextLine();

        char[] arr = new char[str.length()];
        int index = 0;
        for(int i=0; i<str.length(); i++){
            arr[index++] = str.charAt(i);
            if(arr[index-1] == bomb.charAt(bomb.length() - 1) && index >= bomb.length() - 1){
                boolean flag = true;
                for(int j=0; j<bomb.length(); j++){
                    if (bomb.charAt(bomb.length()- j - 1) != arr[index - j -1]) flag = false;
                }
                if(flag) index -= bomb.length();
            }
        }
        String res = String.valueOf(arr, 0, index);
        if(res.length() == 0) res = "LION";
        System.out.println(res);
    }


}
