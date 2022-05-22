#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, int, less<int>,
        rb_tree_tag, tree_order_statistics_node_update>
        ordered_map;

void solve() {
    int n, q, type, x1, y1, x2, y2;
    ordered_map rows, cols;
    cin >> n >> q;
    while (q-- > 0) {
        cin >> type >> x1 >> y1;
        switch (type) {
            case 1: {
                if (rows.find(x1) == rows.end()) {
                    rows[x1] = 1;
                } else {
                    rows[x1]++;
                }
                if (cols.find(y1) == cols.end()) {
                    cols[y1] = 1;
                } else {
                    cols[y1]++;
                }
                break;
            }
            case 2: {
                auto it = rows.find(x1);
                if (it->second == 1) {
                    rows.erase(it);
                } else {
                    it->second--;
                }
                it = cols.find(y1);
                if (it->second == 1) {
                    cols.erase(it);
                } else {
                    it->second--;
                }
                break;
            }
            case 3: {
                cin >> x2 >> y2;
                if (rows.order_of_key(x2 + 1) - rows.order_of_key(x1) == x2 - x1 + 1
                    || cols.order_of_key(y2 + 1) - cols.order_of_key(y1) == y2 - y1 + 1) {
                    cout << "Yes" << "\n";
                } else {
                    cout << "No" << "\n";
                }
                break;
            }
            default:
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
