// // #include<bits/stdc++.h>
// // using namespace std;

// // // void solve(){
// // //     int n,k;
// // //     cin>>n>>k;
// // //     string s;
// // //     cin>>s;
// // //     int ans = 0;
// // //     if()

// // // }
// // // int main(){
// // //     ios::sync_with_stdio(0);
// // //     cin.tie(0);
// // //     int t;
// // //     cin>>t;
// // //     while(t--){
// // //         solve();
// // //     }
// // // }


// // // #include <iostream>
// // // #include <vector>
// // // #include <string>
// // // #include <algorithm>
// // // #include <cmath>
// // // using namespace std;

// // // Function to check if it's possible to split into `groups` groups
// // bool isPossible(const string &fishes, int n, int groups, long long k) {
// //     long long alice_score = 0, bob_score = 0;
// //     int group_size = (n + groups - 1) / groups; // Ceiling division
    
// //     for (int i = 0; i < groups; ++i) {
// //         int start = i * group_size;
// //         int end = min(start + group_size, n);
        
// //         long long alice_count = 0, bob_count = 0;
// //         for (int j = start; j < end; ++j) {
// //             if (fishes[j] == '0') ++alice_count;
// //             else ++bob_count;
// //         }
// //         alice_score += alice_count * i;
// //         bob_score += bob_count * i;
// //     }
    
// //     return (bob_score - alice_score) >= k;
// // }

// // void solve() {
// //     int t;
// //     cin >> t; // Number of test cases
// //     while (t--) {
// //         int n;
// //         long long k;
// //         cin >> n >> k;
// //         string fishes;
// //         cin >> fishes;

// //         int alice_count = count(fishes.begin(), fishes.end(), '0');
// //         int bob_count = count(fishes.begin(), fishes.end(), '1');

// //         if (bob_count - alice_count < k) {
// //             cout << -1 << '\n';
// //             continue;
// //         }

// //         // Binary search for minimum groups
// //         int low = 1, high = n, answer = -1;
// //         while (low <= high) {
// //             int mid = (low + high) / 2;
// //             if (isPossible(fishes, n, mid, k)) {
// //                 answer = mid;
// //                 high = mid - 1; // Try for fewer groups
// //             } else {
// //                 low = mid + 1; // Increase groups
// //             }
// //         }

// //         cout << answer << '\n';
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     solve();
// //     return 0;
// // }



// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// // Function to check if it's possible to split into `groups` groups
// bool isPossible(const string &fishes, int n, int groups, long long k) {
//     long long alice_score = 0, bob_score = 0;
//     int group_size = (n + groups - 1) / groups; // Ceiling division
    
//     for (int i = 0; i < groups; ++i) {
//         int start = i * group_size;
//         int end = min(start + group_size, n);
        
//         long long alice_count = 0, bob_count = 0;
//         for (int j = start; j < end; ++j) {
//             if (fishes[j] == '0') ++alice_count;
//             else ++bob_count;
//         }
//         alice_score += alice_count * i;
//         bob_score += bob_count * i;
//     }
    
//     return (bob_score - alice_score) >= k;
// }

// void solve() {
//     int t;
//     cin >> t; // Number of test cases
//     while (t--) {
//         int n;
//         long long k;
//         cin >> n >> k;
//         string fishes;
//         cin >> fishes;

//         int alice_count = count(fishes.begin(), fishes.end(), '0');
//         int bob_count = count(fishes.begin(), fishes.end(), '1');

//         if (bob_count - alice_count < k) {
//             cout << -1 << '\n';
//             continue;
//         }

//         // Binary search for minimum groups
//         int low = 1, high = n, answer = -1;
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if (isPossible(fishes, n, mid, k)) {
//                 answer = mid;
//                 high = mid - 1; // Try for fewer groups
//             } else {
//                 low = mid + 1; // Increase groups
//             }
//         }

//         cout << answer << '\n';
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     solve();
//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPossible(const string &fishes, int n, int m, long long k) {
    long long alice_score = 0, bob_score = 0;
    int current_group = 0;
    int group_size = (n + m - 1) / m; // Calculate group size (ceiling division)

    for (int i = 0; i < n; ++i) {
        if (i % group_size == 0) current_group++; // Increment group
        if (fishes[i] == '1') {
            bob_score += (current_group - 1);
        } else {
            alice_score += (current_group - 1);
        }
    }

    return (bob_score - alice_score) >= k;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        string fishes;
        cin >> fishes;

        int alice_count = count(fishes.begin(), fishes.end(), '0');
        int bob_count = count(fishes.begin(), fishes.end(), '1');

        // If it's impossible to achieve the score difference
        if (bob_count - alice_count < k) {
            cout << -1 << '\n';
            continue;
        }

        // Binary search for minimum groups
        int low = 1, high = n, answer = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(fishes, n, mid, k)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
