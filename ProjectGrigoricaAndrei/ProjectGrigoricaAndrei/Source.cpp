    #define _CRT_SECURE_NO_WARNINGS

    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    // AbstractEntity class with a pure virtual method
    class AbstractEntity {
    public:
        virtual int generateRandomID() = 0; // Pure virtual method
        virtual ~AbstractEntity() = default;  // Virtual destructor for proper polymorphic behavior
    };

    class Location : public AbstractEntity {
    private:
        string venueName;
        int maxSeats;
        int numRows;
        int numSeatsPerRow;
        string defaultTicketType;
        double defaultTicketPrice;
        string* venueDescription;
        static const int staticArraySize = 5;
        int staticArray[staticArraySize];
        vector<int> numericalVector;

    public:
        Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow);
        Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow, const string& defaultType, double defaultPrice);
        Location();
        Location(const Location& other);
        ~Location();


        void setVenueName(const string& name);
        void setMaxSeats(int seats);
        void setNumRows(int rows);
        void setNumSeatsPerRow(int seatsPerRow);
        void setDefaultTicketType(const string& defaultType);
        void setDefaultTicketPrice(double defaultPrice);
        void setVenueDescription(const string& description);
        void addToNumericalVector(int value);
        string getVenueDescription() const;
        void displaySeatingPlan() const;


        string getVenueName() const;
        int getMaxSeats() const;
        int getNumRows() const;
        int getNumSeatsPerRow() const;

        friend ostream& operator<<(ostream& os, const Location& location);
        friend istream& operator>>(istream& is, Location& location);
        Location& operator=(const Location& other);
        int operator[](int index) const;
        Location operator+(const Location& other) const;
        Location& operator++();
        Location operator++(int);
        explicit operator bool() const;
        bool operator!() const;
        bool operator<(const Location& other) const;
        bool operator==(const Location& other) const;

        void displayLocationInfo() const;


        int generateRandomID() override {
            static bool seedInitialized = false;
            if (!seedInitialized) {
                srand(static_cast<unsigned>(time(nullptr)));
                seedInitialized = true;
            }
            return rand();
        }
    };

    // Implementation of Location class
    Location::Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow)
        : venueName(name), maxSeats(maxSeats), numRows(numRows), numSeatsPerRow(numSeatsPerRow) {}

    Location::Location(const Location& other)
        : venueName(other.venueName), maxSeats(other.maxSeats), numRows(other.numRows), numSeatsPerRow(other.numSeatsPerRow) {}

    /*

    The program can receive as a parameter in the command line mode of operation: if it uses a menu in the console or processes a text file with all input data (example: if the application is called oop.exe, then can be launched in execution in the following way: oop.exe data.txt, in which case it will process the data from the file received as a parameter)

    The application can process data from a text file and will display the results on the console according to the above

    The application will use binary files to save tickets issued to date; when restarting the application the data will be restored

    All entities needed to implement the above functionality will be added to the existing classes (or new classes related to the project can be defined)

    A menu will be implemented to help the user navigate through the different functionalities

    At least a new class will be created by deriving an existing class

    The application will contain at least one abstract class (can be interface) containing at least one pure virtual method. The pure method will be overdefined in a derived class.

    Existing classes will have at least 2 virtual methods other than pure virtual ones. Methods will be overdefined by derived classes.

    At least one STL class will be used in one of the existing classes

    The application must work turnkey (once started it will not require any further changes to the source code to expose all the functionality)

    This phase is considered implemented if at least 75% of the requirements are implemented

    Changes to the project source code are managed using a Git repository. Is mandatory that students do multiple commits after each class implementation/update. Each commit must contain a short message detailing the changes. If the phase has less than 5 commits (in different days), it will not be taken into account.

    */

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

    Location::Location(const string& name, int maxSeats, int numRows, int numSeatsPerRow,
        const string& defaultType, double defaultPrice)
        : venueName(name), maxSeats(maxSeats), numRows(numRows), numSeatsPerRow(numSeatsPerRow),
        venueDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {
        setDefaultTicketType(defaultType);
        setDefaultTicketPrice(defaultPrice);
    }

    Location::Location()
        : maxSeats(0), numRows(0), numSeatsPerRow(0), venueDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {
        setDefaultTicketType("Regular");
        setDefaultTicketPrice(30.0);
    }

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

    void Location::setVenueDescription(const string& description) {
        if (venueDescription == nullptr) {
            venueDescription = new string(description);
        }
        else {
            *venueDescription = description;
        }
    }

    void Location::addToNumericalVector(int value) {
        numericalVector.push_back(value);
    }

    Location::~Location() {
        delete venueDescription;
    }



    ostream& operator<<(ostream& os, const Location& location) {
        os << "Venue: " << location.venueName << "\nMax Seats: " << location.maxSeats << "\nNumber of Rows: "
            << location.numRows << "\nSeats Per Row: " << location.numSeatsPerRow << "\n";

        return os;
    }

    istream& operator>>(istream& is, Location& location) {
        cout << "Enter venue name: ";
        is >> location.venueName;

        cout << "Enter maximum seats: ";
        is >> location.maxSeats;

        cout << "Enter number of rows: ";
        is >> location.numRows;

        cout << "Enter seats per row: ";
        is >> location.numSeatsPerRow;

        cout << "Enter default ticket type: ";
        is >> location.defaultTicketType;

        cout << "Enter default ticket price: ";
        is >> location.defaultTicketPrice;

        cout << "Enter venue description: ";
        is.ignore();

        return is;
    }


    Location& Location::operator=(const Location& other) {
        if (this != &other) {
            venueName = other.venueName;
            maxSeats = other.maxSeats;
            numRows = other.numRows;
            numSeatsPerRow = other.numSeatsPerRow;

        }
        return *this;
    }

    int Location::operator[](int index) const {
        if (index >= 0 && index < numericalVector.size()) {
            return numericalVector[index];
        }
        else {
            throw out_of_range("Index out of range.");
        }
    }

    Location Location::operator+(const Location& other) const {
        Location result = *this;

        return result;
    }

    Location& Location::operator++() {

        ++maxSeats;
        ++numRows;
        ++numSeatsPerRow;

        return *this;
    }


    Location Location::operator++(int) {
        Location temp = *this;  

        maxSeats++;
        numRows++;
        numSeatsPerRow++;

        return temp;  
    }


    Location::operator bool() const {
        return maxSeats > 0 && numRows > 0 && numSeatsPerRow > 0;  
    }


    bool Location::operator!() const {
        return !(maxSeats > 0 && numRows > 0 && numSeatsPerRow > 0);  
    }


    bool Location::operator<(const Location& other) const {
        return (maxSeats * numRows) < (other.maxSeats * other.numRows);
    }


    bool Location::operator==(const Location& other) const {
        return venueName == other.venueName && maxSeats == other.maxSeats &&
            numRows == other.numRows && numSeatsPerRow == other.numSeatsPerRow;

    }


    //-----------------------------------------------------------------------------------------------------------------------------------------

    class Event : public AbstractEntity {
    private:
        string eventName;
        string eventDate;
        string eventTime;
        string* eventDescription;
        static const int staticArraySize = 5;
        int staticArray[staticArraySize];
        vector<int> numericalVector;

    public:
        static const int MAX_EVENT_NAME_LENGTH = 50;

        Event(const string& name, const string& date, const string& time);
        Event(const Event& other);

        Event()
            : eventName(""), eventDate(""), eventTime(""), eventDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {}
    
        ~Event();


        void setEventName(const string& name);
        void setEventDate(const string& date);
        void setEventTime(const string& time);
        void setEventDescription(const string& description);
        void addToNumericalVector(int value);

        string getEventDescription() const;
        string getEventName() const;
        string getEventDate() const;
        string getEventTime() const;


        friend ostream& operator<<(ostream& os, const Event& event);
        friend istream& operator>>(istream& is, Event& event);
        Event& operator=(const Event& other);
        int operator[](int index) const;
        Event operator+(const Event& other) const;
        Event& operator++();
        Event operator++(int);
        explicit operator bool() const;
        bool operator!() const;
        bool operator<(const Event& other) const;
        bool operator==(const Event& other) const;


        void displayEventInfo() const;


        int generateRandomID() override {
            static bool seedInitialized = false;
            if (!seedInitialized) {
                srand(static_cast<unsigned>(time(nullptr)));
                seedInitialized = true;
            }
            return rand();
        }
    };

    // Implementation of Event class
    Event::Event(const string& name, const string& date, const string& time)
        : eventName(name), eventDate(date), eventTime(time), eventDescription(nullptr),
        staticArray{ 1, 2, 3, 4, 5 } {}

    Event::Event(const Event& other)
        : eventName(other.eventName), eventDate(other.eventDate), eventTime(other.eventTime),
        eventDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {
        setEventDescription(other.eventDescription ? *other.eventDescription : "");
        numericalVector = other.numericalVector;
    }

    void Event::setEventDescription(const string& description) {
        if (eventDescription == nullptr) {
            eventDescription = new string(description);
        }
        else {
            *eventDescription = description;
        }
    }

    void Event::addToNumericalVector(int value) {
        numericalVector.push_back(value);
    }

    Event::~Event() {
        delete eventDescription;
    }

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
        if (eventDescription != nullptr) {
            cout << "Description: " << *eventDescription << "\n";
        }
        cout << "Static Array: [";
        for (int i = 0; i < staticArraySize; ++i) {
            cout << staticArray[i] << (i == staticArraySize - 1 ? "" : ", ");
        }
        cout << "]\n";

        cout << "Numerical Vector: [";
        for (int i = 0; i < numericalVector.size(); ++i) {
            cout << numericalVector[i] << (i == numericalVector.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }

    ostream& operator<<(ostream& os, const Event& event) {
        os << "Event Name: " << event.eventName << "\nDate: " << event.eventDate << "\nTime: " << event.eventTime << "\n";
        return os;
    }

    istream& operator>>(istream& is, Event& event) {
        cout << "Enter event name: ";
        is >> event.eventName;

        cout << "Enter event date: ";
        is >> event.eventDate;

        cout << "Enter event time: ";
        is >> event.eventTime;



        return is;
    }

    Event& Event::operator=(const Event& other) {
        if (this != &other) {
            eventName = other.eventName;
            eventDate = other.eventDate;
            eventTime = other.eventTime;
            setEventDescription(other.eventDescription ? *other.eventDescription : "");
            numericalVector = other.numericalVector;
        }
        return *this;
    }

    int Event::operator[](int index) const {
        if (index >= 0 && index < numericalVector.size()) {
            return numericalVector[index];
        }
        else {
            throw out_of_range("Index out of range.");
        }
    }

    Event Event::operator+(const Event& other) const {
        Event result = *this;
    
        return result;
    }


    Event& Event::operator++() {

        ++staticArray[0];
        return *this;
    }


    Event Event::operator++(int) {
        Event temp = *this;  

        staticArray[0]++;
        return temp;  
    }


    Event::operator bool() const {

        return !eventName.empty();
    }


    bool Event::operator!() const {

        return eventName.empty();
    }


    bool Event::operator<(const Event& other) const {

        return eventName < other.eventName;
    }


    bool Event::operator==(const Event& other) const {

        return eventName == other.eventName &&
            eventDate == other.eventDate &&
            eventTime == other.eventTime;
    }


    //----------------------------------------------------------------------------------------------------------

    class Ticket : public AbstractEntity {
    private:
        static int ticketIDCounter;
        int ticketID;
        string ticketType;
        double ticketPrice;
        bool isBooked;
        char* ticketDescription;  
        static const int staticArraySize = 5;
        int staticArray[staticArraySize];
        vector<int> numericalVector;
        int generateTicketID();


    public:

        Ticket(const string& type, double price);
        Ticket(const Ticket& other);

        Ticket()
            : ticketID(generateTicketID()), ticketType(""), ticketPrice(0.0), isBooked(false),
            ticketDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {}

        ~Ticket();

        void setTicketID(int id);
        void setTicketType(const string& type);
        void setTicketPrice(double price);
        void bookTicket();
        void setTicketDescription(const string& description); 



        int getTicketID() const;
        string getTicketType() const;
        double getTicketPrice() const;
        bool isTicketBooked() const;
        string getTicketDescription() const;  


        void displayTicketInfo() const;


        Ticket& operator=(const Ticket& other);
        int operator[](int index) const;
        Ticket operator+(const Ticket& other) const;
        Ticket& operator++();
        Ticket operator++(int);
        explicit operator bool() const;
        bool operator!() const;
        bool operator<(const Ticket& other) const;
        bool operator==(const Ticket& other) const;


        friend ostream& operator<<(ostream& os, const Ticket& ticket);
        friend istream& operator>>(istream& is, Ticket& ticket);

        int generateRandomID() override {
            static bool seedInitialized = false;
            if (!seedInitialized) {
                srand(static_cast<unsigned>(time(nullptr)));
                seedInitialized = true;
            }
            return rand();
        }
    };

    // Initialize static member
    int Ticket::ticketIDCounter = 1000;

    // Implementation of Ticket class
    Ticket::Ticket(const string& type, double price)
        : ticketID(ticketIDCounter++), ticketType(type), ticketPrice(price), isBooked(false),
        ticketDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {}

    Ticket::Ticket(const Ticket& other)
        : ticketID(other.ticketID), ticketType(other.ticketType), ticketPrice(other.ticketPrice),
        isBooked(other.isBooked), ticketDescription(nullptr), staticArray{ 1, 2, 3, 4, 5 } {
        setTicketDescription(other.ticketDescription ? other.ticketDescription : "");
        numericalVector = other.numericalVector;
    }

    Ticket::~Ticket() {
        delete[] ticketDescription;
    }

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

    void Ticket::setTicketID(int id) {
        if (id >= 0) {
            ticketID = id;
        }
        else {
            throw invalid_argument("Invalid value for ticket ID.");
        }
    }

    bool Ticket::isTicketBooked() const {
        return isBooked;
    }

    void Ticket::setTicketDescription(const string& description) {
        if (ticketDescription == nullptr) {
            ticketDescription = new char[description.length() + 1];
            strcpy(ticketDescription, description.c_str());
        }
        else {
            delete[] ticketDescription;
            ticketDescription = new char[description.length() + 1];
            strcpy(ticketDescription, description.c_str());
        }
    }

    string Ticket::getTicketDescription() const {
        return ticketDescription ? string(ticketDescription) : "";
    }

    void Ticket::displayTicketInfo() const {
        cout << "Ticket ID: " << ticketID << "\nType: " << ticketType << "\nPrice: $" << ticketPrice
            << "\nStatus: " << (isBooked ? "Booked" : "Available") << "\n";

        cout << "Static Array: [";
        for (int i = 0; i < staticArraySize; ++i) {
            cout << staticArray[i] << (i == staticArraySize - 1 ? "" : ", ");
        }
        cout << "]\n";

        cout << "Numerical Vector: [";
        for (int i = 0; i < numericalVector.size(); ++i) {
            cout << numericalVector[i] << (i == numericalVector.size() - 1 ? "" : ", ");
        }
        cout << "]\n";

        cout << "Description: " << (ticketDescription ? ticketDescription : "N/A") << "\n";
    }

    Ticket& Ticket::operator=(const Ticket& other) {
        if (this != &other) {
            ticketID = other.ticketID;
            ticketType = other.ticketType;
            ticketPrice = other.ticketPrice;
            isBooked = other.isBooked;
            setTicketDescription(other.ticketDescription ? other.ticketDescription : "");
            numericalVector = other.numericalVector;
        }
        return *this;
    }

    int Ticket::operator[](int index) const {
        if (index >= 0 && index < numericalVector.size()) {
            return numericalVector[index];
        }
        else {
            throw out_of_range("Index out of range.");
        }
    }

    Ticket Ticket::operator+(const Ticket& other) const {
        Ticket result = *this;
        result.ticketPrice += other.ticketPrice;
        return result;
    }

    Ticket& Ticket::operator++() {

        if (!numericalVector.empty()) {
            ++numericalVector[0];
        }
        return *this;
    }

    Ticket Ticket::operator++(int) {
        Ticket temp = *this;

        if (!numericalVector.empty()) {
            numericalVector[0]++;
        }
        return temp;
    }

    Ticket::operator bool() const {

        return isBooked;
    }

    bool Ticket::operator!() const {

        return !isBooked;
    }

    bool Ticket::operator<(const Ticket& other) const {

        return ticketPrice < other.ticketPrice;
    }

    bool Ticket::operator==(const Ticket& other) const {
        return ticketID == other.ticketID && ticketType == other.ticketType &&
            ticketPrice == other.ticketPrice && isBooked == other.isBooked &&
            numericalVector == other.numericalVector &&
            (strcmp(ticketDescription ? ticketDescription : "", other.ticketDescription ? other.ticketDescription : "") == 0);
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

        ticket.isBooked = false; 

        cout << "Enter ticket description: ";
        string description;
        is.ignore();  
        getline(is, description);
        ticket.setTicketDescription(description);

        cout << "Enter numerical vector (space-separated values): ";
        int value;
        while (is >> value) {
            ticket.numericalVector.push_back(value);
        }

        ticket.ticketID = ticket.generateTicketID();
        cout << "Ticket ID: " << ticket.getTicketID() << "\n";

        return is;
    }

    int Ticket::generateTicketID() {
        return ++ticketIDCounter;
    }

    // Function to generate a random ticket ID
    int generateRandomTicketID() {
        static bool seedInitialized = false;
        if (!seedInitialized) {
            srand(static_cast<unsigned>(time(nullptr)));
            seedInitialized = true;
        }
        return rand();
    }

    Location enterLocationDetails() {
        Location location;
        cin >> location;
        return location;
    }

    Event enterEventDetails() {
        Event event;
        cin >> event;
        return event;
    }

    Ticket generateNominalTicket(const Location& location, const Event& event) {
        Ticket ticket;

        cout << "Available ticket types:\n1. VIP\n2. Regular\n";
        int ticketTypeChoice;
        cout << "Enter your choice (1 or 2): ";
        cin >> ticketTypeChoice;

        switch (ticketTypeChoice) {
        case 1:
            ticket.setTicketType("VIP");
            ticket.setTicketPrice(100.0); 
            break;
        case 2:
            ticket.setTicketType("Regular");
            ticket.setTicketPrice(30.0); 
            break;
        default:
            cout << "Invalid choice for ticket type. Generating a default Regular ticket.\n";
            ticket.setTicketType("Regular");
            ticket.setTicketPrice(30.0);
        }

        ticket.setTicketID(generateRandomTicketID());

        return ticket;
    }


    bool validateTicket(const Ticket& ticket) {
        // ticket is considered balid if it is vip (for now)
        return ticket.getTicketType() == "VIP";
    }

    //----------------------------------------------------------------------------------- PHASE 2

    // File handling class
    class FileHandler {
    public:
        template <typename T>
        static void saveToFile(const string& filename, const vector<T>& entities) {
            ofstream outputFile(filename, ios::binary);
            if (!outputFile.is_open()) {
                cerr << "Error opening file for writing: " << filename << "\n";
                return;
            }

            for (const auto& entity : entities) {
                outputFile.write(reinterpret_cast<const char*>(&entity), sizeof(T));
            }
        }

        template <typename T>
        static vector<T> loadFromFile(const string& filename) {
            vector<T> entities;
            ifstream inputFile(filename, ios::binary);
            if (!inputFile.is_open()) {
                cerr << "Error opening file for reading: " << filename << "\n";
                return entities;
            }

            T tempEntity;
            while (inputFile.read(reinterpret_cast<char*>(&tempEntity), sizeof(T))) {
                entities.push_back(tempEntity);
            }

            return entities;
        }

        template <typename T>
        static void saveEntityToFile(const string& filename, const T& entity) {
            ofstream outputFile(filename, ios::binary | ios::app);
            if (!outputFile.is_open()) {
                cerr << "Error opening file for writing: " << filename << "\n";
                return;
            }

            outputFile.write(reinterpret_cast<const char*>(&entity), sizeof(T));
        }

        template <typename T>
        static vector<T> loadEntitiesFromFile(const string& filename) {
            vector<T> entities;
            ifstream inputFile(filename, ios::binary);
            if (!inputFile.is_open()) {
                cerr << "Error opening file for reading: " << filename << "\n";
                return entities;
            }

            T tempEntity;
            while (inputFile.read(reinterpret_cast<char*>(&tempEntity), sizeof(T))) {
                entities.push_back(tempEntity);
            }

            return entities;
        }
    };


    int AbstractEntity::generateRandomID() {
        static bool seedInitialized = false;
        if (!seedInitialized) {
            srand(static_cast<unsigned>(time(nullptr)));
            seedInitialized = true;
        }
        return rand();
    }

    Location enterLocationDetails() {
        Location location;
        cin >> location;
        return location;
    }

    Event enterEventDetails() {
        Event event;
        cin >> event;
        return event;
    }

    //-----------------------------------------------------------------------------------

    int main() {
        Location location;
        Event event;

        int choice;
        do {
            cout << "1. Enter location details\n"
                << "2. Enter event details\n"
                << "3. Generate nominal ticket\n"
                << "4. Validate ticket\n"
                << "5. Save entities to file\n"
                << "6. Load entities from file\n"
                << "7. Exit\n\n";
            
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
            {location = enterLocationDetails();
            break; }
            case 2:
            { event = enterEventDetails();
            break; }
            case 3:
            { 
                if (!location || !event) {
                cout << "Please enter location and event details before generating a ticket.\n";
                break;
                }
                Ticket ticket = generateNominalTicket(location, event);
                cout << "Generated Ticket:\n";
                ticket.displayTicketInfo();
                break; 
            }
            case 4:
            {
                if (!location || !event) {
                cout << "Please enter location and event details before validating a ticket.\n";
                break;
                }
                Ticket ticketToValidate;
                cin >> ticketToValidate;
                if (validateTicket(ticketToValidate)) {
                    cout << "Ticket is valid.\n";
                }
                else {
                    cout << "Ticket is not valid.\n";
                }
            break; 
            }
            case 5: {
                FileHandler::saveEntityToFile("data.txt", location);
                FileHandler::saveEntityToFile("data.txt", event);
                cout << "Entities saved to file.\n";
                break;
            }
            case 6: {
                vector<Location> savedLocations = FileHandler::loadEntitiesFromFile<Location>("data.txt");
                vector<Event> savedEvents = FileHandler::loadEntitiesFromFile<Event>("data.txt");

                // Display loaded entities
                cout << "Loaded Locations:\n";
                for (const auto& savedLocation : savedLocations) {
                    savedLocation.displayLocationInfo();
                }

                cout << "\nLoaded Events:\n";
                for (const auto& savedEvent : savedEvents) {
                    savedEvent.displayEventInfo();
                }
                break;
            }
        
            default:
                cout << "Invalid choice. Please try again.\n";
            }


            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (choice != 7);

        return 0;
    }

