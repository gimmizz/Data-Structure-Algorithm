package BOJ.JAVA;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;

public class Silver1_1713{
    public static void main(String[] args) throws IOException{
        // input
        System.setIn(new FileInputStream("BOJ\\JAVA\\input\\1713.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        ArrayList<Student> pics = new ArrayList<Student>(N);

        int count = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<count;i++){
            int cur =Integer.parseInt(st.nextToken());
            // 이미 존재하는 경우
            // - recommend 값 ++

            boolean found = false;
            for (Student s : pics){
                if (s.no == cur){
                    s.recommend++;
                    found = true;
                    break;
                } 
            }

            // 새로운 추가
            // - if 공간이 있으면 - 새롭게 추가
            // - else 꽉 찼을 경우 (가장 recommend 적은 학생 삭제, 가장 오래된 학생 삭제)
            if (!found){
                if (pics.size() < N){
                    // 새롭게 추가
                    pics.add(new Student(cur, 1, i));
                } else{
                    Collections.sort(pics);
                    pics.remove(0);
                    pics.add(new Student(cur, 1, i));
                }
            }
        }
        // output
        // 학생 번호가 증가하는 순서대로 출력
        int[] output = new int[N];
        for (int i=0;i<pics.size();i++){
            output[i] = pics.get(i).getNo();
        }
        Arrays.sort(output);
        for (int i=0;i<output.length;i++){
            System.out.printf(output[i] + " ");
        }

    }
    static class Student implements Comparable<Student>{
        int no;
        int recommend;
        int enter_time;

        Student(int no, int recommend, int enter_time){
            this.no = no;
            this.recommend = recommend;
            this.enter_time = enter_time;
        }

        public int getNo(){
            return this.no;
        }

        @Override
        public int compareTo(Student s){
            if(this.recommend > s.recommend){
                return 1;
            } else if (this.recommend == s.recommend){
                if (this.enter_time > s.enter_time){
                    return 1;
                }
            }
            return -1;
        }
    }
}