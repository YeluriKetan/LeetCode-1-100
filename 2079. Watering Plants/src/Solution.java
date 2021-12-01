class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int total = 0;
        int currCapacity = capacity;
        for (int i = 0; i < plants.length; i++) {
            if (plants[i] > currCapacity) {
                total += 2 * i;
                currCapacity = capacity - plants[i];
            } else {
                currCapacity -= plants[i];
            }
            total += 1;
        }
        return total;
    }
}
