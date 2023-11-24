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

    // Setter methods with input validation
    void setEventName(const string& name);
    void setEventDate(const string& date);
    void setEventTime(const string& time);

    // Accessor methods
    string getEventName() const;
    string getEventDate() const;
    string getEventTime() const;

    // Generic methods for processing/displaying attributes
    void displayEventInfo() const;
};



int main() {

    return 0;
}
