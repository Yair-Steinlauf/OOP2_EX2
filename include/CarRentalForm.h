// CarRentalForm.h - Handles Car Rental Bookings
#ifndef CARRENTALFORM_H
#define CARRENTALFORM_H

#include "BookingForm.h"
#include <array>
#include <vector>

class CarRentalForm : public BookingForm {
public:
    CarRentalForm(sf::RenderWindow& win, DialogueManager* manager);    
    std::string getFormType() const override;
    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
private:

    std::string pickupLocation, dropOffLocation, carType;
    void setDefaultValues();
    std::array<std::string, 5> carTypeSelection = { "Economy","Compact","Sedan","SUV","Luxury"};
    int selectedCarType = 0;
};

#endif // CARRENTALFORM_H
