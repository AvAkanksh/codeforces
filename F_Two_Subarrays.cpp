// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // int main(){
// // //     int n;
// // //     cin>>n;
// // //     vector<int> a(n);
// // //     vector<int> b(n);
// // //     for(int i = 0 ; i<n ; i++){
// // //         cin>>a[i];
// // //     }
// // //     for(int i = 0 ; i<n ; i++){
// // //         cin>>b[i];
// // //     }
// // //     int q;
// // //     cin>>q;
// // //     while(q--){
// // //         int c,p,x;
// // //         cin>>c>>p>>x;
// // //         if(c==1){
// // //             a[p-1] = x;
// // //         }
// // //         else if(c==2){
// // //             b[p-1] = x;
// // //         }
// // //         else{
// // //             int l = p;
// // //             int r = x;
// // //             int ans = 0;

            

// // //             cout<<ans<<endl;
// // //         }
// // //     }
// // // }

// // #include <bits/stdc++.h>

// // using namespace std;

// // struct Node {
// //     long long max_sum_subarray, max_prefix_sum, max_suffix_sum, total_sum;
// // };

// // class SegmentTree {
// // public:
// //     vector<Node> tree;
// //     vector<int> lazy;
// //     int n;

// //     SegmentTree(int n) {
// //         this->n = n;
// //         tree.resize(4 * n);
// //         lazy.resize(4 * n);
// //     }

// //     void push(int node, int start, int end) {
// //         if (lazy[node] != 0) {
// //             tree[node].max_sum_subarray += lazy[node] * (end - start + 1);
// //             tree[node].max_prefix_sum += lazy[node] * (end - start + 1);
// //             tree[node].max_suffix_sum += lazy[node] * (end - start + 1);
// //             tree[node].total_sum += lazy[node] * (end - start + 1);

// //             if (start != end) {
// //                 lazy[2 * node] += lazy[node];
// //                 lazy[2 * node + 1] += lazy[node];
// //             }

// //             lazy[node] = 0;
// //         }
// //     }

// //     void update(int node, int start, int end, int l, int r, int val) {
// //         push(node, start, end);

// //         if (r < start || end < l) {
// //             return;
// //         }

// //         if (l <= start && end <= r) {
// //             tree[node].max_sum_subarray += val * (end - start + 1);
// //             tree[node].max_prefix_sum += val * (end - start + 1);
// //             tree[node].max_suffix_sum += val * (end - start + 1);
// //             tree[node].total_sum += val * (end - start + 1);

// //             if (start != end) {
// //                 lazy[2 * node] += val;
// //                 lazy[2 * node + 1] += val;
// //             }

// //             return;
// //         }

// //         int mid = (start + end) / 2;
// //         update(2 * node, start, mid, l, r, val);
// //         update(2 * node + 1, mid + 1, end, l, r, val);

// //         tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
// //     }

// //     Node query(int node, int start, int end, int l, int r) {
// //         push(node, start, end);

// //         if (r < start || end < l) {
// //             return {0, 0, 0, 0};
// //         }

// //         if (l <= start && end <= r) {
// //             return tree[node];
// //         }

// //         int mid = (start + end) / 2;
// //         Node left = query(2 * node, start, mid, l, r);
// //         Node right = query(2 * node + 1, mid + 1, end, l, r);

// //         return merge(left, right);
// //     }

// //     // Node merge(Node left, Node right) {
// //     //     Node node;
// //     //     node.total_sum = left.total_sum + right.total_sum;
// //     //     node.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);
// //     //     node.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);
// //     //     node.max_sum_subarray = max({left.max_sum_subarray, right.max_sum_subarray,
// //     //                                  left.max_suffix_sum + right.max_prefix_sum});
// //     //     return node;
// //     // }
// // //     Node merge(Node left, Node right) {
// // //     Node node;
// // //     node.total_sum = left.total_sum + right.total_sum;
// // //     node.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);
// // //     node.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);

// // //     // Correctly calculate the maximum sum subarray
// // //     node.max_sum_subarray = max({left.max_sum_subarray, right.max_sum_subarray,
// // //                                  left.max_suffix_sum + right.max_prefix_sum});
// // //     return node;
// // // }

// // Node merge(Node left, Node right) {
// //     Node node;
// //     node.total_sum = left.total_sum + right.total_sum;
// //     node.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);
// //     node.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);

// //     // Correctly calculate the maximum sum subarray
// //     node.max_sum_subarray = max({left.max_sum_subarray, right.max_sum_subarray,
// //                                  left.max_suffix_sum + right.max_prefix_sum,
// //                                  left.max_prefix_sum + right.max_suffix_sum});
// //     return node;
// // }

// // };

// // int main() {
// //     int n;
// //     cin >> n;

// //     vector<int> a(n + 1), b(n + 1);
// //     for (int i = 1; i <= n; i++) {
// //         cin >> a[i];
// //     }
// //     for (int i = 1; i <= n; i++) {
// //         cin >> b[i];
// //     }

// //     SegmentTree st(n);
// //     for (int i = 1; i <= n; i++) {
// //         st.update(1, 1, n, i, i, a[i] + 2 * b[i]);
// //     }

// //     int q;
// //     cin >> q;

// //     while (q--) {
// //         int type, x, y;
// //         cin >> type >> x >> y;

// //         if (type == 1) {
// //             st.update(1, 1, n, x, x, y - a[x]);
// //             a[x] = y;
// //         } else if (type == 2) {
// //             st.update(1, 1, n, x, x, 2 * (y - b[x]));
// //             b[x] = y;
// //         } else {
// //             Node node = st.query(1, 1, n, x, y);
// //             long long max_cost = node.max_sum_subarray;

// //             // Consider the case where the two subarrays are adjacent
// //             for (int i = x; i < y; i++) {
// //                 max_cost = max(max_cost, a[i] + 2 * b[i] + node.max_prefix_sum + node.max_suffix_sum);
// //             }

// //             cout << max_cost << endl;
// //         }
// //     }

// //     return 0;
// // }



// #include <bits/stdc++.h>

// using namespace std;

// struct Node {
//     long long max_sum_subarray, max_prefix_sum, max_suffix_sum, total_sum;
// };

// class SegmentTree {
// public:
//     vector<Node> tree;
//     vector<int> lazy;
//     int n;

//     SegmentTree(int n) {
//         this->n = n;
//         tree.resize(4 * n);
//         lazy.resize(4 * n);
//     }

//     void push(int node, int start, int end) {
//         // ... (Same as before)
//     }

//     void update(int node, int start, int end, int l, int r, int val) {
//         // ... (Same as before)
//     }

//     Node query(int node, int start, int end, int l, int r) {
//         // ... (Same as before)
//     }

//     Node merge(Node left, Node right) {
//         Node node;
//         node.total_sum = left.total_sum + right.total_sum;
//         node.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);
//         node.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);
//         node.max_sum_subarray = max({left.max_sum_subarray, right.max_sum_subarray,
//                                      left.max_prefix_sum + right.max_suffix_sum,
//                                      left.max_suffix_sum + right.max_prefix_sum,
//                                      left.total_sum + right.total_sum});
//         return node;
//     }
// };

// int main() {
//     int n;
//     cin >> n;

//     vector<int> a(n + 1), b(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     for (int i = 1; i <= n; i++) {
//         cin >> b[i];
//     }

//     SegmentTree st(n);
//     for (int i = 1; i <= n; i++) {
//         st.update(1, 1, n, i, i, a[i] + 2 * b[i]);
//     }

//     int q;
//     cin >> q;

//     while (q--) {
//         int type, x, y;
//         cin >> type >> x >> y;

//         if (type == 1) {
//             // ... (Same as before)
//         } else if (type == 2) {
//             // ... (Same as before)
//         } else {
//             Node node = st.query(1, 1, n, x, y);

//             // Calculate the maximum cost of two non-overlapping subarrays
//             long long max_cost = 0;
//             for (int i = x; i < y; i++) {
//                 max_cost = max(max_cost, a[i] + 2 * b[i] + node.max_prefix_sum + node.max_suffix_sum);
//             }
//             max_cost = max(max_cost, node.max_sum_subarray);

//             cout << max_cost << endl;
//         }
//     }

//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long max_sum_subarray, max_prefix_sum, max_suffix_sum, total_sum;
};

class SegmentTree {
public:
    vector<Node> tree;
    vector<int> lazy;
    int n;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node].max_sum_subarray += lazy[node] * (end - start + 1);
            tree[node].max_prefix_sum += lazy[node] * (end - start + 1);
            tree[node].max_suffix_sum += lazy[node] * (end - start + 1);
            tree[node].total_sum += lazy[node] * (end - start + 1);

            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);

        if (r < start || end < l) {
            return;
        }

        if (l <= start && end <= r) {
            tree[node].max_sum_subarray += val * (end - start + 1);
            tree[node].max_prefix_sum += val * (end - start + 1);
            tree[node].max_suffix_sum += val * (end - start + 1);
            tree[node].total_sum += val * (end - start + 1);

            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }

            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        push(node, start, end);

        if (r < start || end < l) {
            return {0, 0, 0, 0};
        }

        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);

        return merge(left, right);
    }

    Node merge(Node left, Node right) {
        Node node;
        node.total_sum = left.total_sum + right.total_sum;
        node.max_prefix_sum = max(left.max_prefix_sum, left.total_sum + right.max_prefix_sum);
        node.max_suffix_sum = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);
        node.max_sum_subarray = max({left.max_sum_subarray, right.max_sum_subarray,
                                     left.max_prefix_sum + right.max_suffix_sum,
                                     left.max_suffix_sum + right.max_prefix_sum,
                                     left.total_sum + right.total_sum});
        return node;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    SegmentTree st(n);
    for (int i = 1; i <= n; i++) {
        st.update(1, 1, n, i, i, a[i] + 2 * b[i]);
    }

    int q;
    cin >> q;

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) {
            st.update(1, 1, n, x, x, y - a[x]);
            a[x] = y;
        } else if (type == 2) {
            st.update(1, 1, n, x, x, 2 * (y - b[x]));
            b[x] = y;
        } else {
            Node node = st.query(1, 1, n, x, y);

            // Calculate the maximum cost of two non-overlapping subarrays
            long long max_cost = 0;
            for (int i = x; i < y; i++) {
                max_cost = max(max_cost, a[i] + 2 * b[i] + node.max_prefix_sum + node.max_suffix_sum);
            }
            max_cost = max(max_cost, node.max_sum_subarray);

            cout << max_cost << endl;
        }
    }

    return 0;
}
