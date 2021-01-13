package BOJ.JAVA;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.FileInputStream; //input파일 읽을 때

public class template {
    
    //주요 변수 선언

    public static void main(String[] args) throws IOException {
        //input
        System.setIn(new FileInputStream("input파일")); // input파일 읽을 때
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // 1. 여러 숫자가 한 줄에 있을 때 
        StringTokenizer st = new StringTokenizer(br.readLine());
        // String line = br.readLine();
        // StringTokenizer st = new StringTokenizer(line);
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // 2. 한 줄에 하나의 숫자
        int testCase = Integer.parseInt(br.readLine());
    
        
        st = new StringTokenizer(br.readLine());
        // for (int i=0; i < N; i++){
        //     nums[i] = Integer.parseInt(st.nextToken());
        // }

        // output
        System.out.println();

        // 빠른 출력을 위해
        StringBuilder sb = new StringBuilder();
        
        while(st.hasMoreTokens()){
            sb.append("출력 내용");
        }

        System.out.println(sb.toString());
    }
}
