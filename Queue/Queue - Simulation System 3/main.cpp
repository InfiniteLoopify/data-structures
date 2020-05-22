#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//predefined constants for 60min and 18hrs
const int MIN_60 = 60;
const int HRS_18 = 18;

//---------------------------------------------------------------------------------------------------------------------
//store customer info (start, middle and end time)
//start = customer arrival time
//middle = arrival + wait time
//end = arrival + wait + serve time
struct CustomerInfo
{
    int id;
    int start, middle, end;
    CustomerInfo(int a = 0, int b = 0, int c = 0, int d = 0) : id(a), start(b), middle(c), end(d) {}
};

//---------------------------------------------------------------------------------------------------------------------
//take a value and return the hour in which it should be included in
int getHour(int val)
{
    for(int i = 1; i <= HRS_18; ++i)
        if(val <= i * MIN_60)
            return i;
    if(!val)
        return 1;
    else
        return 0;
}

//---------------------------------------------------------------------------------------------------------------------
//display a vector till the end along with a string
void displayVector(const vector<int> &vec, const char *str)
{
    cout << str << endl;
    for(int i = 0; i < vec.size(); ++i)
        cout << setfill('0') << setw(2) << vec[i] << " ";
    cout << endl;
}

//---------------------------------------------------------------------------------------------------------------------
//display a vector1 divided by vector2 till the end along with a string
void displayVector(const vector<int> &vecUp, const vector<int> &vecDown, const char *str)
{
    cout << str << endl;
    for(int i = 0; i < vecUp.size(); ++i)
        cout << fixed << setfill('0') << setw(2) << setprecision(2)
			<< static_cast<double> (vecUp[i]) / vecDown[i] << " ";
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ifstream inf("Input.txt");
    //if file connot be opened then end program
    if(!inf)
    {
        cout << "Unable to open File.";
        cin.get();
        return -1;
    }

    CustomerInfo prev;
    CustomerInfo cur;

    //vectors to display all averages
    vector <int> avgWait(HRS_18);
    vector <int> avgServe(HRS_18);
    vector <int> avgCustomer(HRS_18);

    int id = 0, arrive = 0, serve = 0;
    //loop till file does not end and arrival time is less than 18 hours
    while(!inf.eof() && arrive <= HRS_18 * MIN_60)
    {
        prev = cur;

        //read data from file
        inf >> id;
        inf >> arrive;
        inf >> serve;

        //if value is negative, end program
        if(id < 0 || arrive < 0 || serve < 0)
        {
            cout << "Data cannot be negative\n";
            return -1;
        }

        cur.id = id;
        cur.start = arrive;

        //middle = greater value between current Customer arrival time and previous Customer departure time
        cur.middle = (arrive > prev.end) ? arrive : prev.end;
        cur.end = cur.middle + serve;

//        cout << cur.id << " " << cur.start << " (" << cur.middle - cur.start << ") "
//            						<< cur.middle << " (" << cur.end - cur.middle << ") "
//            						<< cur.end << " - " << getHour(cur.start) << "\n";

        int hour = getHour(cur.start);

        //if hour is less than 0 or greater than 18, then end loop
        if(!hour)
            break;

        if(cur.start == hour * MIN_60 && hour != HRS_18)
            ++avgCustomer[hour];
        else
            ++avgCustomer[hour - 1];

        //if start and end lie in same hour, then add data to hour
        if(getHour(cur.end) <= hour)
        {
            avgWait[hour - 1] += cur.middle - cur.start;
            avgServe[hour - 1] += cur.end - cur.middle;
        }
        //if start and end lie in different hour, split wait and serve time between the two hours
        else
        {
            //if middle if before hour mark
            if(cur.middle < hour * MIN_60)
            {
                avgWait[hour - 1] += cur.middle - cur.start;
                avgServe[hour - 1] += hour * MIN_60 - cur.middle;
                avgServe[hour] += cur.end - hour * MIN_60;
            }
            //if middle if after hour mark
            else if(cur.middle > hour * MIN_60)
            {
                avgWait[hour - 1] += hour * MIN_60 - cur.start;
                avgWait[hour] += cur.middle - hour * MIN_60;
                avgServe[hour] += cur.end - cur.middle;
            }
            //if middle and hour mark are equal
            else
            {
                avgWait[hour - 1] += cur.middle - cur.start;
                avgServe[hour] += cur.end - cur.middle;
            }
        }
    }

    int totalCustomers = 0;
    cout << "\nHours: \n";

    //display hours and find total customer count
    for(int i = 0; i < avgCustomer.size(); ++i)
    {
        //calculate total customers
        totalCustomers += avgCustomer[i];
        cout << setfill('0') << setw(2) << i + 1 << " ";
    }
    cout << "\n";

    //display all averages
    displayVector(avgWait, "\nAvg Wait: ");
    displayVector(avgServe, "\nAvg Serve: ");

	//displayVector(avgWait, avgCustomer, "\nAvg Wait: ");
    //displayVector(avgServe, avgCustomer, "\nAvg Serve: ");

    displayVector(avgCustomer, "\nAvg Customers: ");

	cout << "\nTotal Customers: " << totalCustomers << "\n";

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
