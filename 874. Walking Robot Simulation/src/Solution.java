import java.util.HashMap;
import java.util.TreeSet;

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        HashMap<Integer, TreeSet<Integer>> YYY = new HashMap<>(obstacles.length + 1, 1);
        HashMap<Integer, TreeSet<Integer>> XXX = new HashMap<>(obstacles.length + 1, 1);
        for (int i = 0; i < obstacles.length; i++) {
//            System.out.println("[" + obstacles[i][0] + ", " + obstacles[i][1] + "]");
            TreeSet<Integer> setY = YYY.getOrDefault(obstacles[i][0], new TreeSet<>());
            setY.add(obstacles[i][1]);
            YYY.put(obstacles[i][0], setY);
            TreeSet<Integer> setX = XXX.getOrDefault(obstacles[i][1], new TreeSet<>());
            setX.add(obstacles[i][0]);
            XXX.put(obstacles[i][1], setX);
        }
//        System.out.println("Phase 1 done");
        int[] position = {0,0,0};
        int max = 0;
        for (int i = 0; i < commands.length; i++) {
//            System.out.println("[" + position[0] + ", " + position[1] + ", " + position[2] + "]");
            if (commands[i] == -2) {
//                System.out.println("Turn left");
                if (position[0] == 0) {
                    position[0] = 3;
                } else {
                    position[0] = position[0] - 1;
                }
            } else if (commands[i] == -1) {
//                System.out.println("Turn right");
                if (position[0] == 3) {
                    position[0] = 0;
                } else {
                    position[0] = position[0] + 1;
                }
            } else {
//                System.out.println("Move");
                switch(position[0]) {
                    case 0:
                        Integer y1 = YYY.getOrDefault(position[1], new TreeSet<>()).higher(position[2]);
                        if (y1 != null && y1 <= position[2] + commands[i]) {
                            position[2] = y1 - 1;
                        } else {
                            position[2] = position[2] + commands[i];
                        }
                        break;
                    case 1:
                        Integer x1 = XXX.getOrDefault(position[2], new TreeSet<>()).higher(position[1]);
                        if (x1 != null && x1 <= position[1] + commands[i]) {
                            position[1] = x1 - 1;
                        } else {
                            position[1] = position[1] + commands[i];
                        }
                        break;
                    case 2:
                        Integer y2 = YYY.getOrDefault(position[1], new TreeSet<>()).lower(position[2]);
                        if (y2 != null && y2 >= position[2] - commands[i]) {
                            position[2] = y2 + 1;
                        } else {
                            position[2] = position[2] - commands[i];
                        }
                        break;
                    case 3:
                        Integer x2 = XXX.getOrDefault(position[2], new TreeSet<>()).lower(position[1]);
                        if (x2 != null && x2 >= position[1] - commands[i]) {
                            position[1] = x2 + 1;
                        } else {
                            position[1] = position[1] - commands[i];
                        }
                        break;
                }
            }
            max = Math.max(max, position[1] * position[1] + position[2] * position[2]);
        }
//        System.out.println("[" + position[0] + ", " + position[1] + ", " + position[2] + "]");
//        System.out.println("Phase 2 done");
        return max;
    }
}