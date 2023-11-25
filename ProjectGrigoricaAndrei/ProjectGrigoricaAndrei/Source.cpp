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

// Implementation of Location class
Location::Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow)
    : venueName(name), maxSeats(maxSeats), numRows(numRows), numSeatsPerRow(numSeatsPerRow) {}

Location::Location(const Location& other)
    : venueName(other.venueName), maxSeats(other.maxSeats), numRows(other.numRows), numSeatsPerRow(other.numSeatsPerRow) {}

Location::~Location() {}

void Location::setVenueName(const string& name) {
    venueName = name;
}

void Location::setMaxSeats(int seats) {
    if (seats > 0) {
        maxSeats = seats;
    }
    else {
        throw invalid_argument("Invalid value for max seats.");
    }
}

void Location::setNumRows(int rows) {
    if (rows > 0) {
        numRows = rows;
    }
    else {
        throw invalid_argument("Invalid value for number of rows.");
    }
}

void Location::setNumSeatsPerRow(int seatsPerRow) {
    if (seatsPerRow > 0) {
        numSeatsPerRow = seatsPerRow;
    }
    else {
        throw invalid_argument("Invalid value for seats per row.");
    }
}

string Location::getVenueName() const {
    return venueName;
}

int Location::getMaxSeats() const {
    return maxSeats;
}

int Location::getNumRows() const {
    return numRows;
}

int Location::getNumSeatsPerRow() const {
    return numSeatsPerRow;
}

void Location::displayLocationInfo() const {
    cout << "Venue: " << venueName << "\nMax Seats: " << maxSeats << "\nNumber of Rows: " << numRows
        << "\nSeats Per Row: " << numSeatsPerRow << "\n";
}

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
    srand(time(0));

    Location myLocation("Stadium A", 500, 10, 50);
    Event myEvent("Football Match", "2023-12-01", "18:00");

    myLocation.displayLocationInfo();
    myEvent.displayEventInfo();
    return 0;
}
