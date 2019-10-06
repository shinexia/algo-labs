package io.xgh.algo.books.CodingInterview;

import org.junit.Assert;
import org.junit.Test;


public class StreamMedianTest {

    @Test
    public void testAdd() {
        StreamMedian<Long> s = new StreamMedian<>();
        s.add(1l);
        Assert.assertEquals(s.getMedian().longValue(), 1l);
        s.add(2l);
        Assert.assertEquals(s.getMedian().longValue(), 1l);
        s.add(3l);
        Assert.assertEquals(s.getMedian().longValue(), 2l);
        s.add(4l);
        Assert.assertEquals(s.getMedian().longValue(), 2l);
        s.add(2l);
        Assert.assertEquals(s.getMedian().longValue(), 2l);
        s.add(5l);
        Assert.assertEquals(s.getMedian().longValue(), 2l);
        s.add(1l);
        Assert.assertEquals(s.getMedian().longValue(), 2l);
    }
}
