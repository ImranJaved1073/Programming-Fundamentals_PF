#include <iostream>
using namespace std;

double calcOfPopulation(double, double, double, double, double);
double inputValidate(double, int);

int main()
{
    double P, // population size
        B,    // birth rate %
        D,    // death rate %
        num_years,
        arrivals,
        departures;

    cout << "Starting size of population: ";
    P = inputValidate(P, 2);

    cout << "Annual birth rate: %";
    B = inputValidate(B, 0);

    cout << "Annual death rate: %";
    D = inputValidate(D, 0);

    cout << "Arrivals each year: ";
    arrivals = inputValidate(arrivals, 0);

    cout << "Departures each year: ";
    departures = inputValidate(departures, 0);

    cout << "Number of years to display: ";
    num_years = inputValidate(num_years, 1);

    cout << "Population size for "
         << num_years << " years "
         << " = "
         << (calcOfPopulation(P, B, D, arrivals, departures) * num_years)
         << endl;

    return 0;
} // END int main()

double inputValidate(double number, int limit)
{

    while (!(cin >> number) || number < limit)
    {
        cout << "Error. Number must not be "
             << " 0 or greater:";
        cin.clear();
        cin.ignore(222, '\n');
    }

    return number;
}

double calcOfPopulation(double P, double B, double D, double arrivals, double departures)
{
    B *= .01; // 3.33% = .0333
    D *= .01; // 4.44% = .0444

    return ((P + (B * P) - (D * P)) + arrivals) - departures;
}