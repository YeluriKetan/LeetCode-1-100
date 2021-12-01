class CombinationIterator {

    private static int[] index;
    private static char[] letters;
    private static boolean isPossible;

    public CombinationIterator(String characters, int combinationLength) {
        index = new int[combinationLength];
        for (int i = 0; i < index.length; i++) {
            index[i] = i;
        }
        letters = characters.toCharArray();
        isPossible = true;
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < index.length; i++) {
            sb.append(letters[index[i]]);
        }
        moveNext();
        return sb.toString();
    }

    private void moveNext() {
        if (!isPossible) {
            return;
        }

        for (int i = index.length - 1; i >= 0; i--) {
            if (index[i] < letters.length - index.length + i) {
                index[i]++;
                for (int j = i + 1; j < index.length; j++) {
                    index[j] = index[j - 1] + 1;
                }
                return;
            } else {
                if (i == 0) {
                    isPossible = false;
                    return;
                }
            }
        }
    }

    public boolean hasNext() {
        return isPossible;
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
