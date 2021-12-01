public class Test {
    public static void main(String[] args) {
        CombinationIterator itr = new CombinationIterator("fiklnuy", 3);
        String arr[] = {"hasNext","next","hasNext","next","hasNext","next","next","next","hasNext","hasNext","next","hasNext","hasNext","next","hasNext","next","hasNext","hasNext","hasNext","next","next","hasNext","next","hasNext","next","next","hasNext","hasNext","next","next","hasNext","hasNext","next","hasNext","next","next","next","next","hasNext","hasNext","next","next","hasNext","hasNext","next","next","hasNext","next","hasNext","hasNext","hasNext","next","next","hasNext","hasNext","hasNext","hasNext","next","hasNext","next","hasNext","next","next","next","next","next","next","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext","hasNext"};
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals("hasNext")) {
                System.out.println((i + 1) + ". " + itr.hasNext());
            } else {
                System.out.println((i + 1) + ". " + itr.next());
            }
        }
    }
}
