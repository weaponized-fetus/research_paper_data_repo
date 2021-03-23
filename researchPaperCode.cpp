#include <bits/stdc++.h>
using namespace std;

std::vector<int> sieveOfEratosthenes(int n) {
        bool *prime = new bool[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int c = 0, cur = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {
                c++;
            }
        }
        int *arr = new int[c];
        for (int i = 2; i <= n; i++) {
            if (prime[i] == true) {
                arr[cur] = i;
                cur++;
            }
        }
        return vector<int>(arr, arr + c);
}
int main()
{
    auto x = sieveOfEratosthenes(100);
    auto s = std::unordered_set<int>(x.begin(), x.end());
    for (auto i : x)
        cout << i << '\n';
    unsigned __int128 primorial = 1;
    for (auto i : x)
        primorial *= i;
    cout << bool(primorial % 3);
    
    
    auto start = chrono::steady_clock::now();
    bool dummy = 0;
    for (int i = 0; i < 1000; ++i)
    {
        for (auto i : x)
            dummy = primorial % i;
    }
//  Insert the code that will be timed
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    for (int i = 0; i < 1000; ++i)
    {
        for (auto i : x)
            dummy = s.count(i);
    }
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    
    
    //scatter plot 
    for (int i = 0; i < 1000; ++i)
    {
        start = chrono::steady_clock::now();
        for (int j = 0; j < 25; j++)
        for (auto i : x)
            dummy = s.count(i);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << "\n";
    }
    
    cout << "primorial" << endl;
    
    for (int i = 0; i < 1000; ++i)
    {
        start = chrono::steady_clock::now();
        for (int j = 0; j < 25; j++)
        for (auto i : x)
            dummy = primorial % i;
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << "\n";
    }
    
    //addition
    cout << "\n\n\n\nprimorial";
    
    primorial = 1;
    for (int i = 0; i < 1000; ++i)
    {
        start = chrono::steady_clock::now();
        for (int j = 0; j < 25; j++)
        for (auto i : x)
            primorial *= i;
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << "\n";
    }
    
    cout << "\n\nset";
    s.clear();
    for (int i = 0; i < 1000; ++i)
    {
        start = chrono::steady_clock::now();
        for (int j = 0; j < 25; j++)
        for (auto i : x)
            s.insert(i);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << "\n";
    }
    
    cout << "\n\n\n\nset";
    for (int i = 0; i < 1000; ++i)
    {
        start = chrono::steady_clock::now();
        for (int j = 0; j < 25; j++)
        for (auto i : x)
            s.erase(i);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << "\n";
    }
    
    cout << "\n\n\nprimorial";
    for (int i = 0; i < 1000; ++i)
    {
        start = chrono::steady_clock::now();
        for (int j = 0; j < 25; j++)
        for (auto i : x)
            primorial /= i;
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << "\n";
    }
    
    cout << endl << dummy << '\r';
}