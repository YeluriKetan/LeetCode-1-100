import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public ArrayList<LinkedList<LinkedList<Integer>>> arr = null;

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        this.arr = new ArrayList<>(graph.length);
        for (int i = 0; i < graph.length; i++) {
            this.arr.add(i, null);
        }
        List<List<Integer>> list = new LinkedList<>();
        for (int i = 0; i < graph[0].length; i++) {
            list.addAll(map(0, helper(graph[0][i], graph)));
        }
        return list;
    }

    public LinkedList<LinkedList<Integer>> helper(int node, int[][] graph) {
        if (this.arr.get(node) != null) {
            return this.arr.get(node);
        }
        LinkedList<LinkedList<Integer>> list = new LinkedList<>();
        if (node == graph.length - 1) {
            LinkedList<Integer> place = new LinkedList<>();
            place.add(node);
            list.add(place);
            this.arr.add(node, list);
            return list;
        } else {
            for (int i = 0; i < graph[node].length; i++) {
                if (this.arr.get(i) != null) {
                    list.addAll(map(node, this.arr.get(i)));
                } else {
                    list.addAll(map(node, helper(graph[node][i], graph)));
                }
            }
            this.arr.add(node, list);
            return list;
        }
    }

    public LinkedList<LinkedList<Integer>> map(int add, LinkedList<LinkedList<Integer>> list) {
        for (int i = 0; i < list.size(); i++) {
            LinkedList<Integer> newList = list.get(i);
            newList.addFirst(add);
            list.set(i, newList);
        }
        return list;
    }
}