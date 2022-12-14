#include <iostream>
#include <string>

using namespace std;

void getInfo(string, double &);
double profit(double, double, double, double, double);
double inputValidate(double);
void displayCalculation(double);

int main()
{
    double NS,  // Number of shares
           PP,  // Purchase price per share
           PC,  // Purchase commission paid
           SP,  // Sale price per share
           SC,  // Sale commission paid
           profit_or_loss; 

    getInfo("Number of shares: ", NS);
    getInfo("Purchase price per share: ", PP);
    getInfo("Purchase commission paid: ", PC);
    getInfo("Sale price per share: ", SP);
    getInfo("Sale commission paid: ", SC);

    profit_or_loss = profit(NS, PP, PC, SP, SC);

    displayCalculation(profit_or_loss);

    return 0;
} // END int main()

void getInfo(string prompt, double &user_input)
{
    cout << prompt;
    user_input = inputValidate(user_input);
}

double inputValidate(double num1)
{
    
    while(!(cin >> num1) || num1 < 0)
    {
        cout << "Error. Number must not be "
             << " 0 or greater:";
        cin.clear();
        cin.ignore(333, '\n');
    }

    return num1;
}

double profit(double NS, double PP, double PC, double SP, double SC)
{
    cout << "NS = " << NS << endl; 
    cout << "PP = " << PP << endl; 
    cout << "PC = " << PC << endl; 
    cout << "SP = " << SP << endl; 
    cout << "SC = " << SC << endl;    

    return ((NS * SP) - SC) - ((NS * PP) + PC);
}

void displayCalculation(double profit_or_loss)
{
    cout << "The sale of the stock resulted in "
         << (profit_or_loss < 0 ? "LOSS." : "PROFIT.")
         << "At $" << profit_or_loss
         << endl;
}