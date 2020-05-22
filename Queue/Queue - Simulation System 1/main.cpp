#include <iostream>
#include <fstream>
#include <vector>

int main()
{

    std::ifstream inf("Input.txt");
    //if file cannot open
    if(!inf)
    {
        std::cout << "Cannot open File " << std::endl;
        std::cin.get();
        exit(1);
    }

    const int SIXTY_MIN = 60;
    const int WORKING_HOURS = 18;

    int arrive, serve, wait;
    int startTime, endTime, prevEndTime;
    arrive = serve = wait = startTime = endTime = prevEndTime = 0;

    int hours = 1;
    int totalCustomers = 0;
    std::vector <int> avgWait = {0};
    std::vector <int> avgCustomer = {0};
    std::vector <int> avgServe = {0};
    int avgIndex = 0;

    int id;
    while(!inf.eof() && hours <= WORKING_HOURS)
    {
        prevEndTime = endTime;

        inf >> id;
        inf >> arrive;
        inf >> serve;
        ++totalCustomers;
        ++avgCustomer[avgIndex];

        wait = (prevEndTime - arrive) >= 0 ? (prevEndTime - arrive) : 0;
        startTime = (prevEndTime < arrive) ? (arrive) : (prevEndTime);
        endTime = startTime + serve;

        if(endTime > hours * SIXTY_MIN)
        {
            avgWait.push_back(0);
            avgCustomer.push_back(0);
            avgServe.push_back(0);
            ++avgIndex;

            if(arrive + wait < hours * SIXTY_MIN)
                avgWait[avgIndex - 1] += wait;
            else
            {
                avgWait[avgIndex - 1] += hours * SIXTY_MIN - arrive;
                avgWait[avgIndex] += (arrive + wait - hours * SIXTY_MIN) >= 0
                                    ? (arrive + wait - hours * SIXTY_MIN) : (0);
            }
            avgServe[avgIndex- 1] += hours * SIXTY_MIN - startTime;
            avgServe[avgIndex] += endTime - hours * SIXTY_MIN;

            ++hours;
        }
        else
        {
            avgWait[avgIndex] += wait;
            avgServe[avgIndex] += serve;
        }
        std::cout << arrive << " " << serve << " " << wait << " " << startTime << " " << endTime << "\n";
    }

    std::cout << "\nCustomers: " << totalCustomers;

    std::cout << "\nAvg Serve: ";
    for(int i = 0; i < avgIndex + 1; ++i)
        std::cout << avgServe[i] << " ";

    std::cout << "\nAvg Wait: ";
    for(int i = 0; i < avgIndex + 1; ++i)
        std::cout << avgWait[i] << " ";

    std::cout << "\nAvg Custs: ";
    for(int i = 0; i < avgIndex + 1; ++i)
        std::cout << avgCustomer[i] << " ";

    std::cout << "\n";
    return 0;
}
