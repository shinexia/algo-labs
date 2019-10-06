package io.xgh.algo.books.CodingInterview;

import java.util.Comparator;
import java.util.PriorityQueue;

public class StreamMedian<T extends Number & Comparable<T>> {

    private PriorityQueue<T> upper = new PriorityQueue<>(Comparator.naturalOrder());
    private PriorityQueue<T> lower = new PriorityQueue<>(Comparator.reverseOrder());

    public StreamMedian<T> add(T t) {
        int size = upper.size() + lower.size();
        if ((size & 1) == 1) {
            // add to lower
            if (t.compareTo(upper.peek()) > 0) {
                upper.add(t);
                t = upper.poll();
            }
            lower.add(t);
        } else {
            // add to upper
            if (lower.size() > 0 && t.compareTo(lower.peek()) < 0) {
                lower.add(t);
                t = lower.poll();
            }
            upper.add(t);
        }
        return this;
    }

    public Long getMedian() {
        int size = upper.size() + lower.size();
        if (size == 0) {
            throw new RuntimeException("No numbers are available");
        }
        if ((size & 1) == 1) {
            return upper.peek().longValue();
        } else {
            return (upper.peek().longValue() + lower.peek().longValue()) >> 1;
        }
    }
}
