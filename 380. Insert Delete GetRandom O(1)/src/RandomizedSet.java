import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

class RandomizedSet {

    private static ArrayList<Integer> list;
    private static HashMap<Integer, Integer> map;
    private static final Random rand = new Random();

    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }

    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        } else {
            list.add(val);
            map.put(val, list.size() - 1);
            return true;
        }
    }

    public boolean remove(int val) {
        if (map.containsKey(val)) {
            int currInd = map.get(val);
            if (currInd == list.size() - 1) {
                list.remove(currInd);
                map.remove(val);
                return true;
            }
            list.set(currInd, list.get(list.size() - 1));
            list.remove(list.size() - 1);
            map.put(list.get(currInd), currInd);
            map.remove(val);
            return true;
        } else {
            return false;
        }
    }

    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
