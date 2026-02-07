//Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <iostream>
using namespace std;
int main()
{    
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    int c = 0;
    int pos = -1;
    for(int i = 0; i < n; i++)
    {
        c++;
        if(a[i] == k)
        {
            pos = i;
            break;
        }
    }
    cout << pos << endl;
    cout << c << endl;
    return 0;
}
