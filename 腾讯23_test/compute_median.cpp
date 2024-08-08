#include <iostream>
#include <vector>
#include <iomanip>

using  namespace std;

double getMedian(const vector<int>& a)
{
    
}

void execute(vector<int>& a, vector<int>& b, vector<double>& result)
{
    while (!a.empty())
    {

    }

}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n - 1);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> b[i];
        }
        vector<double> result;
        execute(a, b, result);
        for (int i = 0; i < result.size(); ++i)
        {
            double cur = result[i];
            if (i == result.size() - 1)
            {
                if (cur == static_cast<int>(cur))
                {
                    cout << cur << endl;
                } else {
                    // printf("%.1f\n", cur);
                    cout << std::fixed << std::setprecision(1) << cur << endl;
                }
            } else {
                if (cur == static_cast<int>(cur))
                {
                    cout << cur << " ";
                } else {
                    // printf("%.1f ", cur);
                    cout << std::fixed << std::setprecision(1) << cur << " ";
                }

            }
        }
    }

    return 0;
}
