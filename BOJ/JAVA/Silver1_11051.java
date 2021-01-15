package BOJ.JAVA;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class Silver1_11051 {
    
    //주요 변수 선언
    static int[][] D;

    public static void main(String[] args) throws IOException {
        //input
        // System.setIn(new FileInputStream("input파일")); // input파일 읽을 때
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 1. 여러 숫자가 한 줄에 있을 때 
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        D = new int[N+1][N+1];

        // k == 0 ==> 1
        // n == k ==> 1
        // D[n][k] = D[n-1][k-1] + D[n-1][k]
        for (int n=1;n<=N;n++){
            for (int k=0;k<=n;k++){
            
                if (k==0 || n==k) {
                    D[n][k] = 1;
                } else{
                    D[n][k] = ( D[n-1][k-1] + D[n-1][k] ) % 10007 ;
                }
            }
        }

        // output
        System.out.println(D[N][K]) ;
    }
}
