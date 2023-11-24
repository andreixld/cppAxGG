#include <iostream>
#include <string>

using namespace std;

class Location {
private:
    string venueName;
    int maxSeats;
    int numRows;
    int numSeatsPerRow;

public:
    Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow);
    Location(const Location& other);
    ~Location();

    
    void setVenueName(const string& name);
    void setMaxSeats(int seats);
    void setNumRows(int rows);
    void setNumSeatsPerRow(int seatsPerRow);

    
    string getVenueName() const;
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumSeatsPerRow() const;

    
    void displayLocationInfo() const;
};

class Event {
private:
    string eventName;
    string eventDate;
    string eventTime;

public:
    static const int MAX_EVENT_NAME_LENGTH = 50;

    Event(const string& name, const string& date, const string& time);
    Event(const Event& other);
    ~Event();

    void setEventName(const string& name);
    void setEventDate(const string& date);
    void setEventTime(const string& time);

    string getEventName() const;
    string getEventDate() const;
    string getEventTime() const;

    void displayEventInfo() const;
};

// Implementation of Event class
Event::Event(const string& name, const string& date, const string& time)
    : eventName(name), eventDate(date), eventTime(time) {}

Event::Event(const Event& other)
    : eventName(other.eventName), eventDate(other.eventDate), eventTime(other.eventTime) {}

Event::~Event() {}

void Event::setEventName(const string& name) {
    if (name.length() <= MAX_EVENT_NAME_LENGTH) {
        eventName = name;
    }
    else {
        throw invalid_argument("Event name exceeds maximum length.");
    }
}

void Event::setEventDate(const string& date) {
    eventDate = date;
}

void Event::setEventTime(const string& time) {
    eventTime = time;
}

string Event::getEventName() const {
    return eventName;
}

string Event::getEventDate() const {
    return eventDate;
}

string Event::getEventTime() const {
    return eventTime;
}

void Event::displayEventInfo() const {
    cout << "Event Name: " << eventName << "\nDate: " << eventDate << "\nTime: " << eventTime << "\n";
}

int main() {

    return 0;
}
