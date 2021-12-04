import java.util.ArrayList;

class BrowserHistory {

    private static ArrayList<String> HISTORY;
    private static int currInd;

    public BrowserHistory(String homepage) {
        HISTORY = new ArrayList<>();
        HISTORY.add(homepage);
        currInd = 0;
    }

    public void visit(String url) {
        currInd++;
        int num = HISTORY.size() - currInd;
        for (int i = 0; i < num; i++) {
            HISTORY.remove(currInd);
        }
        HISTORY.add(currInd, url);
    }

    public String back(int steps) {
        if (steps > currInd) {
            currInd = 0;
        } else {
            currInd -= steps;
        }
        return HISTORY.get(currInd);
    }

    public String forward(int steps) {
        if (steps > HISTORY.size() - 1 - currInd) {
            currInd = HISTORY.size() - 1;
        } else {
            currInd += steps;
        }
        return HISTORY.get(currInd);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
