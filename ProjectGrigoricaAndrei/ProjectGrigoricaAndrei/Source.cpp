#include <iostream>
#include <string>

using namespace std;

class EventLocation {
private:
    string venueName;
    string city;
    string country;

public:
    EventLocation(const string& name, const string& city, const string& country)
        : venueName(name), city(city), country(country) {}

    string getVenueName() const {
        return venueName;
    }

    string getCity() const {
        return city;
    }

    string getCountry() const {
        return country;
    }

    void displayLocationInfo() const {
        cout << "Venue: " << venueName << "\nCity: " << city << "\nCountry: " << country << "\n";
    }
};

class FootballMatch {
private:
    EventLocation eventLocation;

public:
    FootballMatch(const string& venue, const string& city, const string& country)
        : eventLocation(venue, city, country) {}

    void readEventLocation() {
        string venue, city, country;

        cout << "Enter venue name: ";
        getline(cin, venue);

        cout << "Enter city: ";
        getline(cin, city);

        cout << "Enter country: ";
        getline(cin, country);

        eventLocation = EventLocation(venue, city, country);
    }

    void displayMatchInfo() const {
        cout << "Football Match Information:\n";
        eventLocation.displayLocationInfo();
    }
};

int main() {
    FootballMatch myMatch("Stadium A", "City X", "Country Y");

    myMatch.displayMatchInfo();

    myMatch.readEventLocation();

    myMatch.displayMatchInfo();

    return 0;
}
