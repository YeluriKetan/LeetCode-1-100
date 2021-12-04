import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

class Solution {
    private static HashMap<String, Integer> map;

    public Solution() {
        map = new HashMap<>();
    }

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        map.clear();
        BitSet source = new BitSet();

        List<String> currAccount;
        ArrayList<Integer> allSets = new ArrayList<>();
        HashSet<Integer> currSet = new HashSet<>();
        String currEmail;
        int sourceIndex;

        for (int i = 0; i < accounts.size(); i++) {
            currAccount = accounts.get(i);
            allSets.clear();
            currSet.clear();
            for (int j = 1; j < currAccount.size(); j++) {
                currEmail = currAccount.get(j);
                if (map.containsKey(currEmail) && !currSet.contains(map.get(currEmail))) {
                    allSets.add(map.get(currEmail));
                    currSet.add(map.get(currEmail));
                }
            }
            if (allSets.size() == 0) {
                source.set(i);
                removeDup(currAccount);
                for (int j = 1; j < currAccount.size(); j++) {
                    map.put(currAccount.get(j), i);
                }
                continue;
            }
            allSets.add(i);
            allSets.sort(Integer::compareTo);
            sourceIndex = allSets.get(0);
            for (int j = 1; j < allSets.size(); j++) {
                source.clear(allSets.get(j));
                join(sourceIndex, accounts.get(sourceIndex), accounts.get(allSets.get(j)));
            }
        }

        String currName;
        List<List<String>> ans = new ArrayList<>();
        sourceIndex = -1;
        for (int i = 0; i < source.cardinality(); i++) {
            sourceIndex = source.nextSetBit(sourceIndex + 1);
            currAccount = accounts.get(sourceIndex);
            currName = currAccount.remove(0);
            currAccount.sort(String::compareTo);
            currAccount.add(0, currName);
            ans.add(currAccount);
        }
        return ans;
    }

    private void join(int toIndex, List<String> addedTo, List<String> addedFrom) {
        HashSet<String> uniq = new HashSet<>();

        for (int i = 1; i < addedTo.size(); i++) {
            uniq.add(addedTo.get(i));
        }

        String currEmail;
        for (int i = addedFrom.size() - 1; i > 0; i--) {
            currEmail = addedFrom.get(i);
            if (uniq.contains(currEmail)) {
                addedFrom.remove(i);
            } else {
                addedTo.add(currEmail);
                uniq.add(currEmail);
                map.put(currEmail, toIndex);
            }
        }
    }

    private void removeDup(List<String> account) {
        HashSet<String> uniq = new HashSet<>();

        String currEmail;
        for (int i = account.size() - 1; i > 0; i--) {
            currEmail = account.get(i);
            if (uniq.contains(currEmail)) {
                account.remove(i);
            } else {
                uniq.add(currEmail);
            }
        }
    }
}
