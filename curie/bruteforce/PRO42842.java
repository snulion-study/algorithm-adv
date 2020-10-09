package bruteforce;

public class PRO42842 {
        public int[] solution(int brown, int yellow) {
            int[] answer = {};

            int sum = brown + yellow;
            for (int i = 3; i <= sum / 2 - 1; i++) {
                if (sum % i != 0) continue;
                int j = sum / i;
                if ((i - 2) * (j - 2) == yellow) {

                    answer = new int[2];
                    answer[0] = Math.max(i, j);
                    answer[1] = Math.min(i, j);
                    break;
                }
            }


            return answer;
        }
}
