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

//class FootballMatch {
//private:
//    EventLocation eventLocation;
//
//public:
//    FootballMatch(const string& venue, const string& city, const string& country)
//        : eventLocation(venue, city, country) {}
//
//    void readEventLocation() {
//        string venue, city, country;
//
//        cout << "Enter venue name: ";
//        getline(cin, venue);
//
//        cout << "Enter city: ";
//        getline(cin, city);
//
//        cout << "Enter country: ";
//        getline(cin, country);
//
//        eventLocation = EventLocation(venue, city, country);
//    }
//
//    void displayMatchInfo() const {
//        cout << "Football Match Information:\n";
//        eventLocation.displayLocationInfo();
//    }
//};

int main() {
    //FootballMatch myMatch("Stadium A", "City X", "Country Y");

    //myMatch.displayMatchInfo();

    //myMatch.readEventLocation();

    //myMatch.displayMatchInfo();

    return 0;
}
