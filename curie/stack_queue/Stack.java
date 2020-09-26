package stack_queue;

import java.util.Scanner;

public class Stack {

    public int[] stack;
    public int capacity;
    public int size;
    public int top = -1;

    public Stack(int cap){
        this.stack = new int[cap];
        this.capacity = cap;
    }

    public void push (int val) {
        if(size == capacity) {
            System.out.println(-1);
            return;
        }
        size++;
        stack[++top] = val;
    }

    public void pop(){
        if(top < 0) {
            System.out.println(-1);
            return;
        }
        System.out.println(stack[top--]);
    }

    public void top(){
        if(top < 0) {
            System.out.println(-1);
            return;
        }
        System.out.println(stack[top]);
    }

    public void size() {
        System.out.println(this.size);
    }

    public void empty() {
        System.out.println(this.size <= 0 ? 1 : 0);
    }


}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N =sc.nextInt();
        Stack s = new Stack(N);
        for(int i=0; i<N; i++){
            String input = sc.next();
            if(input.contains("push")) {
                int num = sc.nextInt();
                s.push(num);
            } else if(input.equals("pop")){
                s.pop();
            }else if(input.equals("size")) {
                s.size();
            }else if(input.equals("empty")) {
                s.empty();
            }else if(input.equals("top")) {
                s.top();
            }
        }
    }
}