import java.util.Arrays;

class Solution {
    private class SourceList {
        int val;
        SourceList next;

        public SourceList(int val) {
            this.val = val;
            this.next = null;
        }
    }

    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        SourceList head = new SourceList(deck[deck.length - 1]);
        SourceList tail = head;
        for (int i = deck.length - 2; i >= 0; i--) {
            tail.next = new SourceList(head.val);
            tail = tail.next;
            tail.next = new SourceList(deck[i]);
            tail = tail.next;
            head = head.next;
        }
        int[] arr = new int[deck.length];
        for (int i = 0; i < arr.length; i++) {
            arr[arr.length -  1 - i] = head.val;
            head = head.next;
        }
        return arr;
    }
}