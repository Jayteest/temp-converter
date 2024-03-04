/* Jacob St Lawrence
This program allows the user to input up to ten temperatures in Fahrenheit, and convert
them to their choice of Celsius or Kelvin. It also gives the user the option to display all
temperatures entered in the session in all three forms.
*/

//set up include statements and namespace
#include <iostream>
#include <iomanip>

using namespace std;

//declare variables and prototypes of functions
void showMenu();
void showCelsius(double, int);
void showKelvin(double, int);
void displayData(int);
int menuSelection;
double tempList[3][10];

int main()  //set up main
{
    //display heading for user
    cout << "This program converts a temperature in Fahrenheit to Celsius or Kelvin.";
    cout << "\nNOTE: A Maximum of 10 temperatures can be entered.\n" << endl;
    
    //initialize a counter for upcoming loop, as well as a flag
    int count = 0;
    bool keepGoing = true;
    
    while (keepGoing)   //create loop for user to keep making selections until they exit
    {
        //display main menu and get user's selection
        showMenu();
        cin >> menuSelection;
    
        switch (menuSelection)  //create switch to do what user selected
        {
            case 1:
                if (count < 10) //proceed to conversion if ten have not already been done
                {
                    //prompt user to input temperature to be converted and accept as input
                    cout << "Enter a Fahrenheit temperature: ";
                    cin >> tempList[0][count];
                    cout << endl;
                    //call function to convert input temperature and display in Celsius
                    showCelsius(tempList[0][count], count);
                    cout << endl;
                    count++;    //advance count before moving to next loop iteration
                }
                else    //if ten conversions have already been done, display error message
                {
                    cout << "\nYou have already entered 10 temperatures." << endl;
                    cout << "Please select to display data or quit.\n" << endl;
                }
                    break;
            case 2:
                if (count < 10) //proceed to conversion if ten have not already been done
                {
                    //prompt user to input temperature to be converted and accept as input
                    cout << "Enter a Fahrenheit temperature: ";
                    cin >> tempList[0][count];
                    cout << endl;
                    //call function to convert input temperature and display in Kelvin
                    showKelvin(tempList[0][count], count);
                    cout << endl;
                    count++;    //advance count before moving to next loop iteration
                }
                else    //if ten conversions have already been done, display error message
                {
                    cout << "\nYou have already entered 10 temperatures." << endl;
                    cout << "Please select to display data or quit.\n" << endl;
                }
                break;
            case 3:
                displayData(count); //call function to display all conversions from session
                break;
            case 4:
                //display exit message and end loop
                cout << "\nGoodbye!\n";
                keepGoing = false;
                break;
            default:
                //display error message and restart loop if invalid menu selection is made
                cout << "\nInvalid selection. Please try again.\n" << endl;
                break;
        }
        
    }
    return 0;
}

void showMenu() //define function to display main menu
{
    cout << "Select one of the following menu options:" << endl;
    cout << "\t1. Convert Fahrenheit to Celsius (Centigrade)" << endl;
    cout << "\t2. Convert Fahrenheit to Kelvin"  << endl;
    cout << "\t3. Display Data" << endl;
    cout << "\t4. Quit" << endl;
    cout << "Enter your choice: ";
}

void showCelsius(double tempF, int i)   //define function to convert temp and display in C
{
    //convert argument to both Celsius and Kelvin and assign to appropriate array indices
    tempList[1][i] = (5. / 9.) * (tempF - 32);
    tempList[2][i] = tempList[1][i] + 273.15;
    
    //display formatted Celsius temperature
    cout << fixed << setprecision(2) << tempF << " Fahrenheit = " << tempList[1][i] << " Celsius" << endl;
}

void showKelvin(double tempF, int i)    //define funtion to convert temp and display in K
{
    //convert argument to both Celsius and Kelvin and assign to appropriate array indices
    tempList[1][i] = (5. / 9.) * (tempF - 32);
    tempList[2][i] = tempList[1][i] + 273.15;
    
    //display formatted Kelvin temperature
    cout << fixed << setprecision(2) << tempF << " Fahrenheit = " << tempList[2][i] << " Kelvin" << endl;
}

void displayData(int counter)   //define funtion to display all conversions from session
{
    cout << '\n' << setw(14) << left << "Fahrenheit:";  //display Fahrenheit row title
    for (int i = 0; i < counter; i++)   //create loop to display all Fahrenheit temperatures
    {
        cout << setw(10) << tempList[0][i];
    }
    cout << '\n' << setw(14) << "Celsius:"; //display Celsius row title
    for (int i = 0; i < counter; i++)   //create loop to display all Celsius temperatures
    {
        cout << setw(10) << tempList[1][i];
    }
    cout << '\n' << setw(14) << "Kelvin:";  //display Kelvin row title
    for (int i = 0; i < counter; i++)   //create loop to display all Kelvin temeratures
    {
        cout << setw(10) << tempList[2][i];
    }
    cout << '\n' << endl;
}
