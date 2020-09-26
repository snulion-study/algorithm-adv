package stack_queue;
import java.util.*;

class Truck {
    int entryTime;
    int weight;
    public Truck(int t, int w){
        this.entryTime = t;
        this.weight = w;
    }
}

public class Bridge_Truck {

    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Truck> q = new LinkedList<>();
        int bridge_weight = 0;
        int curr = 0;
        int time = 0;
        while(curr < truck_weights.length || !q.isEmpty()){
            time ++;
            if(!q.isEmpty()){
                Truck top = q.peek();
                if(time - top.entryTime >= bridge_length){
                    q.poll();
                    bridge_weight -= top.weight;
                }
            }
            if(curr < truck_weights.length && bridge_weight + truck_weights[curr] <= weight){
                q.offer(new Truck(time, truck_weights[curr]));
                bridge_weight += truck_weights[curr];
                curr++;
            }

        }
        return time;
    }
}