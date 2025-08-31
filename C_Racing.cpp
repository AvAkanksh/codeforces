#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> d;
    // vector<int> h;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < n; i++)
    {
        int l;
        int r;
        cin >> l >> r;
        left.push_back(l);
        right.push_back(r);
    }

    vector<int> low_left;
    vector<int> high_right;
    int one = 0;
    int increment = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            low_left.push_back(0);
            high_right.push_back(0);
        }
        else
        {
            int diff = d[i - 1];
            if (diff == 1)
            {
                one++;
            }
            else if (diff == -1)
            {
                increment++;
            }
            low_left.push_back(one);
            high_right.push_back(one + increment);
            if (one > right[i - 1] || one + increment < left[i - 1])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    print(d);

    // cout<<"d"<<endl;
    // print(d);
    // cout<<"low_left : "<<endl;
    // print(low_left);
    // cout<<"- ";
    // print(left);
    // cout<<"high_right : "<<endl;
    // print(high_right);
    // cout<<"- ";
    // print(right);
    // cout<<"final_heights : "<<endl;
    // print(final_heights);
    // print(d);

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}