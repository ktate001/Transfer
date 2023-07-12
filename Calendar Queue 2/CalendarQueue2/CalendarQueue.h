#pragma once
#ifndef	SIMEXEC_H
#define SIMEXEC_H

#include <iostream>
#include <chrono>
#include <string>

struct Event 
{
	std::string description;
	std::chrono::system_clock::time_point time;
	// Other relevant data
	Event* next;
};

class CalendarQueue
{
public:
	CalendarQueue();
	void addEvent(const std::string& description, const std::chrono::system_clock::time_point& time);
	void display();
	Event getNextEvent();
private:
	Event* head;
};

#endif