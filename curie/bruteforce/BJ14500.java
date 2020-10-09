package bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ14500 {
    public static int max = -1;
    static int[][] dir = {{1,0},{0,1},{-1,0},{0,-1}};
    static boolean[][] visited;
    static int[][] board;
    static int M, N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        M = Integer.parseInt(s[0]);
        N = Integer.parseInt(s[1]);
        board = new int[M][N];
        visited = new boolean[M][N];
        for(int i=0; i<M; i++){
            s = br.readLine().split(" ");
            for(int j=0; j<N; j++){
                board[i][j] = Integer.parseInt(s[j]);
            }
        }
        //인접한 4개의 합 중 최고 구하면 됨
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                dfs(i, j, board[i][j], 1);
                solve2(i, j);
            }
        }
        System.out.println(max);
    }

    public static void dfs(int x, int y, int sum, int count) {
        if(count == 4) {
            max = Math.max(max, sum);
            return;
        }
        if(count > 4) return;
        visited[x][y] = true;
        for(int i=0; i<4; i++){
            int currX = x + dir[i][0];
            int currY = y + dir[i][1];
            if(currX < 0 || currX >= M || currY < 0 || currY >= N || visited[currX][currY]) continue;
            dfs(currX, currY, sum + board[currX][currY], count + 1);
        }
        visited[x][y] = false;
    }

    static int[][][] shape = {{{0,0},{0,1},{0,2},{1,1}}
            ,{{0,0},{1,0},{2,0},{1,1}}
            ,{{0,0},{0,1},{0,2},{-1,1}}
            ,{{0,0},{2,0},{1,0},{1,-1}}};

    private static void solve2(int x,int y) {
        for(int i=0;i<4;i++) {
            int sum = 0;
            for(int j=0;j<4;j++) {
                int currX = x + shape[i][j][0];
                int currY = y + shape[i][j][1];
                if(currX<0 || currY<0 || currX>=M || currY>=N) break;
                sum += board[currX][currY];
            }
            max = Math.max(max, sum);
        }
    }
}
