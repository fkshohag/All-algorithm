import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

// https://leetcode.com/discuss/interview-question/5243021/Amazon-OA-Assessment-(Feb-2024)/

public class P2 {
    public static List<Integer> findRequestsInQueue(List<Integer> wait) {
       PriorityQueue<Integer> minHeap = new PriorityQueue<>();
       List<Integer> result = new ArrayList<>();
       for (int w : wait) {
           minHeap.offer(w);
       }
       int time = 0;

       while (!minHeap.isEmpty()) {
           while (!minHeap.isEmpty() && minHeap.peek() <= time) {
               minHeap.poll();
           }
           result.add(minHeap.size());
           minHeap.remove(wait.get(time));
           time++;
       }
       if (!result.contains(0)) {
           result.add(0);
       }
       return result;
   }
}
