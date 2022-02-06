class Bitset {

    private boolean[] arr;
    private int onesCount;
    private boolean flipped;

    public Bitset(int size) {
        arr = new boolean[size];
        onesCount = 0;
        flipped = false;
    }

    public void fix(int idx) {
        if ((!flipped && !arr[idx]) || (flipped && arr[idx])) {
            arr[idx] = !arr[idx];
            onesCount++;
        }
    }

    public void unfix(int idx) {
        if ((!flipped && arr[idx]) || (flipped && !arr[idx])) {
            arr[idx] = !arr[idx];
            onesCount--;
        }
    }

    public void flip() {
        flipped = !flipped;
        onesCount = arr.length - onesCount;
    }

    public boolean all() {
        return onesCount == arr.length;
    }

    public boolean one() {
        return onesCount > 0;
    }

    public int count() {
        return onesCount;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder(arr.length);
        for (boolean b : arr) {
            sb.append(b == flipped ? '0' : '1');
        }
        return sb.toString();
    }
}

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset obj = new Bitset(size);
 * obj.fix(idx);
 * obj.unfix(idx);
 * obj.flip();
 * boolean param_4 = obj.all();
 * boolean param_5 = obj.one();
 * int param_6 = obj.count();
 * String param_7 = obj.toString();
 */
