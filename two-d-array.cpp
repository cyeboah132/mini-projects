#include <iostream>

int main()
{
    float myScore[2][3];

    int rows = sizeof(myScore) / sizeof(myScore[0]);
    int columns = sizeof(myScore[0]) / sizeof(myScore[0][0]);

    std::cout << "Array size: "
              << sizeof(myScore)
              << " bytes\n";

    std::cout << "Rows: "
              << rows
              << "\nColumns: "
              << columns
              << "\n\n";

    // Input scores
    for (int i = 0; i < rows; i++)
    {
        std::cout << "Student " << i + 1 << '\n';

        for (int j = 0; j < columns; j++)
        {
            std::cout << "Enter score for Subject "
                      << j + 1
                      << ": ";

            std::cin >> myScore[i][j];
        }

        std::cout << '\n';
    }

    // Display scores
    std::cout << "\n===== STUDENT SCORES =====\n";

    for (int i = 0; i < rows; i++)
    {
        std::cout << "\nStudent " << i + 1 << '\n';

        for (int j = 0; j < columns; j++)
        {
            std::cout << "Subject "
                      << j + 1
                      << " : "
                      << myScore[i][j]
                      << '\n';
        }
    }

    return 0;
}