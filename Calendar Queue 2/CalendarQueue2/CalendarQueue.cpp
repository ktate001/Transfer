#include <iostream>
#include <chrono>
#include "CalendarQueue.h"

CalendarQueue::CalendarQueue() : head(nullptr) {}

void CalendarQueue::addEvent(const std::string& description, const std::chrono::system_clock::time_point& time) {
    Event* newEvent = new Event;
    newEvent->description = description;
    newEvent->time = time;
    newEvent->next = nullptr;

    if (head == nullptr) {
        head = newEvent;
    }
    else {
        Event* current = head;
        Event* prev = nullptr;

        // Find the appropriate position to insert the new event based on time
        while (current != nullptr && current->time < newEvent->time) {
            prev = current;
            current = current->next;
        }

        if (prev == nullptr) {
            newEvent->next = head;
            head = newEvent;
        }
        else {
            prev->next = newEvent;
            newEvent->next = current;
        }
    }
}

Event CalendarQueue::getNextEvent() {
    if (head == nullptr) {
        std::cout << "Calendar Queue is empty!" << std::endl;
        return Event();
    }

    Event* nextEvent = head;
    head = head->next;
    return *nextEvent;
}

