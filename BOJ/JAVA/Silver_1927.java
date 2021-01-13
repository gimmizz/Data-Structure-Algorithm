package BOJ.JAVA;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
// import java.util.StringTokenizer;
import java.io.FileInputStream; //input파일 읽을 때

import java.util.ArrayList;
import java.util.List;

public class Silver_1927 {
    
    //주요 변수 선언

    public static void main(String[] args) throws IOException {
        //input
        System.setIn(new FileInputStream("BOJ\\JAVA\\input\\1927.txt")); // input파일 읽을 때
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        MinHeap mh = new MinHeap();

        int input;
        for (int i=0; i < N; i++){
            input = Integer.parseInt(br.readLine());
            // System.out.printf("input:", input, "\n");
            if (input != 0){
                mh.insert(input);
            } else{
                System.out.println(mh.delete());
            }
        }
    
    }
    
}

class MinHeap {
    List<Integer> heap;

    public MinHeap() {
        heap = new ArrayList<>();
        heap.add(0);
    }
    
    public void insert(int val) {
        // 제일 끝에 항목 추가
        heap.add(val);

        int current = heap.size() - 1;
        int parent = current / 2;
        while (true) {
            // 루트에 도달한 경우
            if (current == 1) {
                break;
            }
            // 부모가 나보다 작은 경우
            else if ( heap.get(parent) < heap.get(current)) {
                break;
            }
            // 부모가 나보다 큰 경우
            else {
                int temp = heap.get(parent);
                heap.set(parent, heap.get(current));
                heap.set(current, temp);
            }
            current = parent;
            parent = current / 2;

        }
    }

    public int delete() {
        // 루트 값을 제거 후 제일 마지막 값을 루트로 가져옴.
        if(heap.size() == 1) return 0;

        int root = heap.get(1);
        heap.set(1, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);

        int currentPos = 1;

        while (true) {
            // 자식 존재 여부 확인
            if (heap.size()-1 < currentPos *2 ){
                break;
            }
            // 좌측, 우측 중 작은 값 선택
            int target = currentPos *2;
            if (heap.size()-1 >= currentPos *2+1 &&  heap.get(currentPos *2) > heap.get(currentPos * 2 + 1)){
                target = currentPos * 2 + 1;
            }

            // 선택된 자식이 자신보다 작은 경우 :swap
            if ( heap.get(target) < heap.get(currentPos)){
                int temp = heap.get(currentPos);
                heap.set(currentPos, heap.get(target));
                heap.set(target, temp);
            }
            // 선택된 자식이 자신보다 큰 경우
            else {
                break;
            }
            currentPos = target;
        }
        return root;
    }
}