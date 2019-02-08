import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        // Read in data into Cow objects.
        int n = 5;
        int[] pos = new int[]{0,1,2,3,6};
        int[] speed = new int[]{1,2,3,2,1};

        Cow[] cows = new Cow[n];
        for (int i=0; i<n; i++) {
            cows[i] = new Cow(pos[i], speed[i]);
        }

        // This is key.
        Arrays.sort(cows);

        // Go through cows in this order, they get a group if they're
        // position is after the LAST cow that has a group.
        int cnt = 0, curPos = -1;
        for (int i=0; i<n; i++) {
            if (cows[i].pos > curPos) {
                cnt++;
                curPos = cows[i].pos;
            }
        }

        // Print the result.
        System.out.println(cnt);
    }
}

class Cow implements Comparable<Cow> {

    public int pos;
    public int speed;

    public Cow(int pos, int speed) {
        this.pos = pos;
        this.speed = speed;
    }

    // Slower cows go first, then break ties by current position.
    public int compareTo(Cow other) {
        if (this.speed != other.speed) return this.speed-other.speed;
        return this.pos - other.pos;
    }
}
