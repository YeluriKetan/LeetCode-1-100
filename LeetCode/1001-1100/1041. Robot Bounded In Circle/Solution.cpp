class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int direction = 0;
        for (char c: instructions) {
            switch (c) {
                case 'G': {
                    switch (direction) {
                        case 0:
                            y++;
                            break;
                        case 1:
                            x++;
                            break;
                        case 2:
                            y--;
                            break;
                        case 3:
                            x--;
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case 'L':
                    direction = (direction + 3) % 4;
                    break;
                case 'R':
                    direction = (direction + 1) % 4;
                    break;
                default:
                    break;
            }
        }
        return !((direction == 0) && (x || y));
    }
};
