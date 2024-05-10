#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// Class representing a flight
class Flight
{
public:
    string flight_name;              // Name of the flight
    int flight_id;                  // Unique identifier for the flight
    int flight_cap;                 // Capacity of the flight
    float flight_arrival_time, flight_departure_time; // Arrival and departure times of the flight
    string flight_class;            // Class of the flight (e.g., economy, business)

    // Parameterized constructor
    Flight(string f_name, int f_id, int f_cap, float f_at, float f_dt, string f_class)
        : flight_name(f_name), flight_id(f_id), flight_cap(f_cap),
          flight_arrival_time(f_at), flight_departure_time(f_dt), flight_class(f_class) {}
};

// Class for managing flights
class FlightManagement
{
private:
    vector<Flight> flights;         // Vector to store flight records

public:
    // Function to insert a new record of a flight
    void insert_record(string flight_name, int flight_id, int flight_cap,
                       float flight_arrival_time, float flight_departure_time, string flight_class)
    {
        flights.push_back(Flight(flight_name, flight_id, flight_cap, flight_arrival_time, flight_departure_time, flight_class));
        cout << "Record inserted successfully.\n";
    }

    // Function to delete a record of a flight
    void delete_record(int id)
    {
        auto it = find_if(flights.begin(), flights.end(), [id](const Flight &f) { return f.flight_id == id; });
        if (it != flights.end())
        {
            flights.erase(it);
            cout << "Record deleted successfully.\n";
        }
        else
        {
            cout << "No such record exists.\n";
        }
    }

    // Function to print all flight records
    void print_records()
    {
        for (const auto &flight : flights)
        {
            cout << flight.flight_name << " " << flight.flight_id << " "
                 << flight.flight_class << " " << flight.flight_arrival_time
                 << " " << flight.flight_departure_time << endl;
        }
    }
};

void clearInputBuffer()
{
    // Read and discard characters until newline is encountered
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Main function
int main()
{
    // Create an instance of FlightManagement
    FlightManagement fm;

    // Menu-driven loop
    int choice;
    do
    {
        cout << "\nFlight Management System Menu:\n";
        cout << "1. Insert a flight record\n";
        cout << "2. Delete a flight record\n";
        cout << "3. Print all flight records\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string flight_name, flight_class;
            int flight_id, flight_cap;
            float flight_arrival_time, flight_departure_time;
            cout << "Enter flight name: ";
            cin >> flight_name;
            cout << "Enter flight ID: ";
            cin >> flight_id;
            cout << "Enter flight capacity: ";
            cin >> flight_cap;
            cout << "Enter arrival time: ";
            cin >> flight_arrival_time;
            cout << "Enter departure time: ";
            cin >> flight_departure_time;
            cout << "Enter flight class: ";
            cin >> flight_class;
            fm.insert_record(flight_name, flight_id, flight_cap, flight_arrival_time, flight_departure_time, flight_class);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter the flight ID to delete: ";
            cin >> id;
            fm.delete_record(id);
            break;
        }
        case 3:
        {
            cout << "Flight records:\n";
            fm.print_records();
            break;
        }
        case 0:
        {
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
