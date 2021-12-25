class Solution {

    private String s;
    private int index;
    private int[] arr;
    private char prevOper;

    public int calculate(String s) {
        this.s = s;
        index = 0;
        arr = new int[2];
        arr[0] = getInt();
        prevOper = 0;
        char currOper;
        while (index < s.length()) {
            currOper = getOper();
            switch (currOper) {
            case '/': {
                if (prevOper == 0) {
                    arr[0] /= getInt();
                } else {
                    arr[1] /= getInt();
                }
                break;
            }
            case '*': {
                if (prevOper == 0) {
                    arr[0] *= getInt();
                } else {
                    arr[1] *= getInt();
                }
                break;
            }
            case '+':
            case '-': {
                getRidPrevious();
                prevOper = currOper;
                arr[1] = getInt();
                break;
            }
            default:
                break;
            }
        }
        getRidPrevious();
        return arr[0];
    }

    private void getRidPrevious() {
        if (prevOper == 0) {
            return;
        }
        if (prevOper == '+') {
            arr[0] += arr[1];
        } else {
            arr[0] -= arr[1];
        }
        prevOper = 0;
    }

    private int getInt() {
        int currInt = 0;
        char curr;
        while (index < s.length()) {
            curr = s.charAt(index);
            if (curr == ' ') {
                index++;
                continue;
            }
            if (curr > 47) {
                currInt *= 10;
                currInt += curr - '0';
                index++;
            } else {
                break;
            }
        }
        return currInt;
    }

    private char getOper() {
        char curr;
        while (index < s.length()) {
            curr = s.charAt(index++);
            if (curr != ' ') {
                return curr;
            }
        }
        return 0;
    }
}
