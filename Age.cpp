#include <iostream>
#include <cmath>

// using namespace std;

int main()
{
    int age_one;
    int age_two;

    // Taking Age One
    std::cout << "Enter Age One: " << std::endl;
    std::cin >> age_one;

    // taking Age two
    std::cout << "Enter Age Two: " << std::endl;
    std::cin >> age_two;

    // arithematic operation
    int sum = age_one + age_two;
    int product = age_one * age_two;
    float average = sum / 2.0f;

    // Difference
    if (age_one > age_two)
    {
        int result = age_one - age_two;
        return result;
    }
    else
    {
        int result = age_two - age_one;
        return result;
    }

    int abs_diff = abs(age_one - age_two);

    std::cout << " The sum of ages" << sum << std::endl;

    std::cout << " The product of ages" << product << std::endl;

    // std::cout << " The difference of ages" << result << std::endl;

    std::cout << " The abs difference of ages" << abs_diff << std::endl;

    std::cout << " The averages of ages" << average << std::endl;

    return 0;
}
