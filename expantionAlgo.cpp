#include <iostream>
#include <vector>

int main()
{
    std::vector<int> digits;
    int q, n, b;

    std::cout << "Enter the number: \n";
    std::cin >> n;

    std::cout << "Enter the base you want to write: \n";
    std::cin >> b;

    q = n;

    while (q != 0)
    {
        digits.push_back(q % b);
        q = q / b; // FIXED HERE
    }

    std::cout << "The base " << b << " expansion for " << n << " is: \n";

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        std::cout << digits[i];
    }

    std::cout << std::endl;

    return 0;
}