#include <iostream>
#include "CalendarQueue.h"

int main() 
{
    CalendarQueue calendar;

    // Add events
    calendar.addEvent("Meeting", std::chrono::system_clock::now() + std::chrono::hours(1));
    calendar.addEvent("Lunch", std::chrono::system_clock::now() + std::chrono::minutes(30));

    // Retrieve and print the next event
    Event nextEvent = calendar.getNextEvent();
    std::cout << "Next event: " << nextEvent.description << std::endl;

    return 0;
}
