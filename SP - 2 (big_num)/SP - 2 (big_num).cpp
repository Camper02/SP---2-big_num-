#include <iostream>
#include <string>
using namespace std;

string sum(string A, string B)
{
    bool flag = false;
    string answer_sum, num_a, num_b;
    int calc, m;
    int len, r_B = 0, r_A = 0;

    if (A.size() > B.size())
    {
        len = A.size();
        r_B = A.size() - B.size();
    }
    else
    {
        len = B.size();
        r_A = B.size() - A.size();
    }

    for (int i = 1; i <= len; i++)
    {
        num_a = '0';
        num_b = '0';
        if (len - i - r_A > -1)
        {
            num_a = A[len - i - r_A];
        }
        if (len - i - r_B > -1)
        {
            num_b = B[len - i - r_B];
        }
        if (flag)
        {
            calc = stoi(num_a) + stoi(num_b) + 1;
            flag = false;
        }
        else
        {
            calc = stoi(num_a) + stoi(num_b);
        }
        if (calc > 9)
        {
            flag = true;
            calc -= 10;
        }
        answer_sum = to_string(calc) + answer_sum;

    }
    if (flag)
    {
        answer_sum = '1' + answer_sum;
        flag = false;
    }
    return answer_sum;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    string A, B, answer_mult, num_a, num_b, c = "1";

    cin >> A >> B;

    cout << "сумма:" << sum(A, B) << endl;
    answer_mult = A;
    while (c != B)
    {
        answer_mult = sum(answer_mult, A);
        c = sum(c, "1");
    }
    cout << "Произведение:" << answer_mult;
    return 0;
}
