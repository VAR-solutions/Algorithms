//Code adds integers to PriorityQueue.

public class UglyNumbers {
    public long count(int x) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        pq.add(1L);
        long num = 0;
        for (int i = 0; i <= x; i++) {
            num = pq.poll();
            if (num%3 != 0 && num%5 != 0) pq.add(num*2);
            if (num%5 != 0) pq.add(num*3);
            pq.add(num*5);
        }
        return num;
    }
}
