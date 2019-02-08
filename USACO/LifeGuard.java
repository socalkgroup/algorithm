import java.util.*;

public class Main {

    public static void main(String[] args) {

        List<TimeFrame> timeFrameList = new ArrayList<TimeFrame>();
        Set<Integer> keySet = new HashSet<Integer>();

        int n=3;
        int[] start = new int[]{5, 1, 3};
        int[] end = new int[]{9, 4, 7};

        for(int i=0; i<n; i++){
          timeFrameList.add(new TimeFrame(start[i],i));
          timeFrameList.add(new TimeFrame(end[i],i));
        }

        Collections.sort(timeFrameList);

        int coverage = 0;
        int[] singleWork = new int[n];
        int last = 0;

        for(TimeFrame tf: timeFrameList) {

            if(keySet.size() == 1) {
              singleWork[keySet.iterator().next()] += tf.start - last;
            }

            if(!keySet.isEmpty()) {
                coverage += tf.start - last;
            }

            if(keySet.contains(tf.end)) {
                keySet.remove(tf.end);
            }
            else {
                keySet.add(tf.end);
            }
            last = tf.start;
        }

        int ret = 0;
        for(int solo: singleWork) {
            ret = Math.max(ret, coverage - solo);
        }
        System.out.println(ret);
    }

    static class TimeFrame implements Comparable<TimeFrame> {
        public int start, end;
        public TimeFrame(int a, int b) {
            start = a;
            end = b;
        }
        public int compareTo(TimeFrame s) {
            return start - s.start;
        }
    }
}
