import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        LinkedList<Integer> list1 = new LinkedList<>();
        int curr = label;
        while(curr > 0) {
            list1.add(curr);
            if (curr % 2 == 0) {
                curr /= 2;
            } else {
                curr = (curr - 1) / 2;
            }
        }
        int begin = 0;
        int width = 1;
        while (begin + width < label) {
            begin += width;
            width *= 2;
        }
        int i = 0;
        curr = begin + begin + width - label + 1;
        LinkedList<Integer> list2 = new LinkedList<>();
        while(curr > 0) {
            if (i % 2 == 1) {
                list2.addFirst(curr);
            } else {
                list2.addFirst(list1.get(i));
            }
            i++;
            if (curr % 2 == 0) {
                curr /= 2;
            } else {
                curr = (curr - 1) / 2;
            }
        }
        return list2;
    }
}