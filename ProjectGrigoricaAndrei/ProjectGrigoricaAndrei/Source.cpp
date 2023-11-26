#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Location {
private:
    string venueName;
    int maxSeats;
    int numRows;
    int numSeatsPerRow;
    string defaultTicketType;
    double defaultTicketPrice;

public:
    Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow);
    Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow, const string& defaultType, double defaultPrice);
    Location();
    Location(const Location& other);
    ~Location();

    // Setter methods with input validation
    void setVenueName(const string& name);
    void setMaxSeats(int seats);
    void setNumRows(int rows);
    void setNumSeatsPerRow(int seatsPerRow);
    void setDefaultTicketType(const string& defaultType);
    void setDefaultTicketPrice(double defaultPrice);

    // Accessor methods
    string getVenueName() const;
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumSeatsPerRow() const;

    // Generic methods for processing/displaying attributes
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

class Ticket {
private:
    static int ticketIDCounter;
    int ticketID;
    string ticketType;
    double ticketPrice;
    bool isBooked;

public:
    Ticket(const string& type, double price);
    Ticket(const Ticket& other);
    ~Ticket();

    // Setter methods with input validation
    void setTicketType(const string& type);
    void setTicketPrice(double price);
    void bookTicket();

    // Accessor methods
    int getTicketID() const;
    string getTicketType() const;
    double getTicketPrice() const;
    bool isTicketBooked() const;

    // Generic methods for processing/displaying attributes
    void displayTicketInfo() const;

    // Overloaded operators
    Ticket& operator=(const Ticket& other);
    friend ostream& operator<<(ostream& os, const Ticket& ticket);
    friend istream& operator>>(istream& is, Ticket& ticket);
    bool operator==(const Ticket& other) const;
};

// Initialize static member
int Ticket::ticketIDCounter = 1000;

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

Location::Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow, const string& defaultType, double defaultPrice)
    : venueName(name), maxSeats(maxSeats), numRows(numRows), numSeatsPerRow(numSeatsPerRow), defaultTicketType(defaultType), defaultTicketPrice(defaultPrice) {}

Location::Location()
    : maxSeats(0), numRows(0), numSeatsPerRow(0), defaultTicketType("Regular"), defaultTicketPrice(30.0) {}

void Location::setDefaultTicketType(const string& defaultType) {
    defaultTicketType = defaultType;
}

void Location::setDefaultTicketPrice(double defaultPrice) {
    if (defaultPrice > 0) {
        defaultTicketPrice = defaultPrice;
    }
    else {
        throw invalid_argument("Invalid value for default ticket price.");
    }
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

// Implementation of Ticket class
Ticket::Ticket(const string& type, double price)
    : ticketID(ticketIDCounter++), ticketType(type), ticketPrice(price), isBooked(false) {}

Ticket::Ticket(const Ticket& other)
    : ticketID(other.ticketID), ticketType(other.ticketType), ticketPrice(other.ticketPrice), isBooked(other.isBooked) {}

Ticket::~Ticket() {}

void Ticket::setTicketType(const string& type) {
    ticketType = type;
}

void Ticket::setTicketPrice(double price) {
    if (price > 0) {
        ticketPrice = price;
    }
    else {
        throw invalid_argument("Invalid value for ticket price.");
    }
}

void Ticket::bookTicket() {
    isBooked = true;
}

int Ticket::getTicketID() const {
    return ticketID;
}

string Ticket::getTicketType() const {
    return ticketType;
}

double Ticket::getTicketPrice() const {
    return ticketPrice;
}

bool Ticket::isTicketBooked() const {
    return isBooked;
}

void Ticket::displayTicketInfo() const {
    cout << "Ticket ID: " << ticketID << "\nType: " << ticketType << "\nPrice: $" << ticketPrice
        << "\nStatus: " << (isBooked ? "Booked" : "Available") << "\n";
}

Ticket& Ticket::operator=(const Ticket& other) {
    if (this != &other) {
        ticketID = other.ticketID;
        ticketType = other.ticketType;
        ticketPrice = other.ticketPrice;
        isBooked = other.isBooked;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Ticket& ticket) {
    os << "Ticket ID: " << ticket.ticketID << "\nType: " << ticket.ticketType << "\nPrice: $" << ticket.ticketPrice
        << "\nStatus: " << (ticket.isBooked ? "Booked" : "Available") << "\n";
    return os;
}

istream& operator>>(istream& is, Ticket& ticket) {
    cout << "Enter ticket type: ";
    is >> ticket.ticketType;

    cout << "Enter ticket price: $";
    is >> ticket.ticketPrice;

    ticket.isBooked = false; // New ticket is initially not booked

    return is;
}

bool Ticket::operator==(const Ticket& other) const {
    return (ticketID == other.ticketID) && (ticketType == other.ticketType) &&
        (ticketPrice == other.ticketPrice) && (isBooked == other.isBooked);
}

int main() {
    // Seed for random ID generation
    srand(time(0));

    Location myLocation("Stadium A", 500, 10, 50);
    Event myEvent("Football Match", "2023-12-01", "18:00");

    myLocation.displayLocationInfo();
    myEvent.displayEventInfo();

    int numTickets;
    cout << "Enter the number of tickets to generate: ";
    cin >> numTickets;

    vector<Ticket> tickets;
    for (int i = 0; i < numTickets; ++i) {
        Ticket newTicket("Regular", 30.0); // Default type and price
        tickets.push_back(newTicket);
    }

    cout << "\nGenerated Tickets:\n";
    for (const Ticket& ticket : tickets) {
        cout << ticket;
    }

    int ticketToBook;
    cout << "\nEnter the ticket ID to book: ";
    cin >> ticketToBook;

    // Validate the input ticket ID
    for (Ticket& ticket : tickets) {
        if (ticket.getTicketID() == ticketToBook) {
            ticket.bookTicket();
            cout << "Ticket booked successfully.\n";
            break;
        }
    }

    // Display updated information about the booked ticket
    cout << "\nUpdated Tickets:\n";
    for (const Ticket& ticket : tickets) {
        cout << ticket;
    }

    return 0;
}
