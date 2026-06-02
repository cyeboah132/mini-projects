#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

const int MAX_EMPLOYEE = 100;
int employee_counter = 0;

// Employee's Data
std::string Name[MAX_EMPLOYEE];
float HoursWorked[MAX_EMPLOYEE];
int NumberOfDependent[MAX_EMPLOYEE];

// Related Rates
const double regular_rates = 25000.00;
const double overtime_rates = 1.5 * regular_rates;
const double gusss_rate = 0.06;
const double constituency_rate = 0.03;
const double welfare_rate = 0.02;
const double dependants_rate = 5000.00;

// pay arrays.
double RegularPay[MAX_EMPLOYEE];
double OvertimePay[MAX_EMPLOYEE];
double GusssPay[MAX_EMPLOYEE];
double ConstituencyPay[MAX_EMPLOYEE];
double WelfarePay[MAX_EMPLOYEE];
double DependantsPay[MAX_EMPLOYEE];

double DeductionPay[MAX_EMPLOYEE];
double GrossPay[MAX_EMPLOYEE];
double NetPay[MAX_EMPLOYEE];
double Taxes[MAX_EMPLOYEE];

// functions
void getInput();
void computePay();
double computeTax(double grosspay);
void showOutput();

int main()
{
    char choice;

    do
    {
        if (employee_counter >= MAX_EMPLOYEE)
        {
            std::cout << " Maximum number of employees reached.\n";
            break;
        }

        getInput();
        computePay();
        showOutput();

        employee_counter++;

        std::cout << "\n Do you want to enter another employee? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}

void getInput()
{

    int i = employee_counter;

    std::cout << " Enter your name: \n";
    getline(std::cin >> std::ws, Name[i]);

    std::cout << "Enter the Number of hours worked: \n";
    std::cin >> HoursWorked[i];

    std::cout << " Enter the number of dependants\n";
    std::cin >> NumberOfDependent[i];
}

void computePay()
{
    int i = employee_counter;

    if (HoursWorked[i] > 40)
    {
        RegularPay[i] = 40 * regular_rates;
        float overtime_hours = HoursWorked[i] - 40;
        OvertimePay[i] = overtime_rates * overtime_hours;
    }
    else if (HoursWorked[i] <= 40)
    {
        RegularPay[i] = HoursWorked[i] * regular_rates;
        OvertimePay[i] = 0;
    }
    else
    {
        std::cout << " You didn't do any work ";
        RegularPay[i] = 0;
        OvertimePay[i] = 0;
    }

    GrossPay[i] = RegularPay[i] + OvertimePay[i];

    GusssPay[i] = gusss_rate * GrossPay[i];
    ConstituencyPay[i] = constituency_rate * GrossPay[i];
    WelfarePay[i] = welfare_rate * GrossPay[i];

    if (NumberOfDependent[i] > 3)
    {
        int excess_dependants = NumberOfDependent[i] - 3;
        DependantsPay[i] = excess_dependants * 5000;
    }
    else
    {
        DependantsPay[i] = 0;
    }

    Taxes[i] = computeTax(GrossPay[i]);

    DeductionPay[i] = GusssPay[i] + ConstituencyPay[i] + WelfarePay[i] + DependantsPay[i] + Taxes[i];
}

double computeTax(double grosspay)
{
    double tax = 0;

    if (grosspay <= 125000)
    {
        tax = 0;
    }
    else if (grosspay <= 250000)
    {
        tax = 125000 * 0.05;
    }
    else if (grosspay <= 1750000)
    {
        tax = (125000 * 0.05) + (grosspay - 250000) * 0.1;
    }
    else if (grosspay <= 4500000)
    {
        tax = (125000 * 0.05) + (1500000 * 0.1) + ((grosspay - 1750000) * 0.15);
    }
    else if (grosspay <= 5750000)
    {
        tax = (125000 * 0.05) + (1500000 * 0.1) + (2750000 * 0.15) + ((grosspay - 5750000) * 0.20);
    }
    else
    {
        tax = (125000 * 0.05) + (1500000 * 0.1) + (2750000 * 0.15) + (1250000 * 0.2) + ((grosspay - 5750000) * 0.3);
    }

    return tax;
}

void showOutput()
{
    int i = employee_counter;

    std::cout << std::left
              << std::setw(20) << "Name"
              << std::setw(15) << "Hours"
              << std::setw(10) << "Gross Pay"
              << std::setw(10) << "Tax"
              << std::setw(10) << "Deduction"
              << std::setw(10) << "Net Pay"
              << "\n";

    // std::cout << "___________________________________________________";

    for (int i = 0; i <= employee_counter; i++)
    {
        std::cout << std::left
                  << std::setw(20) << Name[i]
                  << std::setw(15) << HoursWorked[i]
                  << std::setw(10) << GrossPay[i]
                  << std::setw(10) << Taxes[i]
                  << std::setw(10) << DeductionPay[i]
                  << std::setw(10) << NetPay[i]
                  << "\n";
    }
}
