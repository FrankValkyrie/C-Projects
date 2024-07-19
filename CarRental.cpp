#include <iostream>
#include <vector>
#include <string>
#include <climits>
//Franklin Cerball
class Car {
public:
    std::string make;
    std::string model;
    int year;
    bool is_rented;
    int rental_duration; // the duration is in days

    Car(std::string make, std::string model, int year) : make(make), model(model), year(year), is_rented(false), rental_duration(0) {}
};

class CarRental {
private:
    std::vector<Car> cars;

public:
    void addCar(std::string make, std::string model, int year) {
        cars.push_back(Car(make, model, year));
    }

    void viewCars() {
        for (int i = 0; i < cars.size(); i++) {
            std::cout << i + 1 << ". " << cars[i].make << " " << cars[i].model << " (" << cars[i].year << ")";
            if (cars[i].is_rented) {
                std::cout << " (Rented for " << cars[i].rental_duration << " days)";
            }
            std::cout << std::endl;
        }
    }

    void rentCar(int carNumber, int days) {
        if (carNumber > 0 && carNumber <= cars.size()) {
            if (!cars[carNumber - 1].is_rented) {
                cars[carNumber - 1].is_rented = true;
                cars[carNumber - 1].rental_duration = days;
                std::cout << "You've successfully rented the car for " << days << " days." << std::endl;
            } else {
                std::cout << "Sorry, this car is already rented." << std::endl;
            }
        } else {
            std::cout << "Invalid car number." << std::endl;
        }
    }

    double calculateRentalPrice(int carNumber, int days) {
        double price_per_day = 50.0;
        return days * price_per_day;
    }

    void viewRentedCars() {
        std::cout << "Cars currently being rented:\n";
        for (int i = 0; i < cars.size(); i++) {
            if (cars[i].is_rented) {
                std::cout << i + 1 << ". " << cars[i].make << " " << cars[i].model << " (" << cars[i].year << ")";
                std::cout << " - Rented for " << cars[i].rental_duration << " days";
                std::cout << " - Rental price: $" << calculateRentalPrice(i + 1, cars[i].rental_duration);
                std::cout << std::endl;
            }
        }
    }
    void returnCar(int carNumber) {
    if (carNumber > 0 && carNumber <= cars.size()) {
        if (cars[carNumber - 1].is_rented) {
            cars[carNumber - 1].is_rented = false;
            cars[carNumber - 1].rental_duration = 0;
            std::cout << "You've successfully returned the car." << std::endl;
        } else {
            std::cout << "This car is not currently rented." << std::endl;
        }
    } else {
        std::cout << "Invalid car number." << std::endl;
    }
}
};

int main() {
    CarRental app;
    std::cout << "\nWelcome to Franklin's Car Rental, type (1-7) to select the menu options.";
    while (true) {
        std::cout << "\n1. Add Car\n2. View Cars\n3. Rent a Car\n4. Calculate Rental Price\n5. View Rented Cars\n6. Return Car\n7. Exit\n\n";
        int choice;
        std::cin >> choice;
        

        if (choice == 1) {
            std::string make, model;
            int year;
            std::cout << "Enter Make: ";
            std::cin >> make;
            std::cout << "Enter Model: ";
            std::cin >> model;
            std::cout << "Enter Year: ";
            std::cin >> year;
            app.addCar(make, model, year);
            std::cout << "Successfully added car.\n";
        } else if (choice == 2) {
            app.viewCars();
        } else if (choice == 3) {
            int carNumber, days;
            std::cout << "Enter the car number you want to rent: ";
            std::cin >> carNumber;
            std::cout << "Enter the number of days you want to rent the car: ";
            std::cin >> days;
            app.rentCar(carNumber, days);
        } else if (choice == 4) {
            int carNumber, days;
            std::cout << "Enter the car number: ";
            std::cin >> carNumber;
            std::cout << "Enter the number of days: ";
            std::cin >> days;
            double price = app.calculateRentalPrice(carNumber, days);
            std::cout << "The rental price for car number " << carNumber << " for " << days << " days is $" << price << std::endl;
        } else if (choice == 5) {
            app.viewRentedCars();
        } else if (choice == 6) {
            int carNumber;
            std::cout << "Enter the car number you want to return: ";
            std::cin >> carNumber;
            app.returnCar(carNumber);
        } 
        
        else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
            while(!(std::cin >> choice)){
                std::cin.clear(); //clear input buffer to restore cin to a usable state
                std::cin.ignore(INT_MAX, '\n'); //ignore last input
                std::cout << "Only enter numbers from 1 to 7, please.\n";
                break; 
            }
        }
    }

    return 0;
}