package sorting;
import java.util.*;

public class PRO42747 {
    public int solution(int[] citations) {
        int answer = 0;
        Arrays.sort(citations);
        int len = citations.length;
        for(int i=0; i<len; i++){
            //오름차순 정렬되어있으므로 인덱스를 이용하여 h 이상 인용된 논문 개수 구할 수 있음
            //x번 인용된 논문이 y개 있는 경우, min(x,y)가 h가 됨
            int citeCount = citations[i];
            answer = Math.max(answer, Math.min(len-i, citeCount));
        }
        return answer;
    }
}
