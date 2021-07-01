class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode listA = list1;
        for (int i = 1; i < a; i++) {
            listA = listA.next;
        }
        ListNode listB = listA;
        for (int i = a - 1; i <= b; i++) {
            listB = listB.next;
        }
        ListNode listC = list2;
        while(listC.next != null) {
            listC = listC.next;
        }
        listC.next = listB;
        listA.next = list2;
        return list1;
    }
}