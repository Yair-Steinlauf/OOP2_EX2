// CarRentalForm.h - Handles Car Rental Bookings
#ifndef CARRENTALFORM_H
#define CARRENTALFORM_H

#include "BookingForm.h"
#include <array>
#include <vector>
#include "SelectionField.h"
#include "ConfirmationBtn.h"

class CarRentalForm : public BookingForm {
public:
    std::string getFormType() const override;
    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
    CarRentalForm(sf::RenderWindow& win, DialogueManager* manager);
    
private:
    void createPickButton(std::vector<std::unique_ptr<SelectionButton>>& selectionButton, int yOffset);
    void createConfirmationBtn(int buttonY);
    void createTextFieldsAndSetFieldLocation(int& yOffset);
    void createFields();
    std::vector<std::string> validate() override;
    std::vector<std::string> multiFieldValidate();
    std::string pickupLocation, dropOffLocation, carType;
    void setDefaultValues();
    std::array<std::string, 5> carTypeSelection = { "Economy","Compact","Sedan","SUV","Luxury"};
    int selectedCarType = 0;
    SelectionField m_selectionField;
    ConfirmationBtn m_Done;
    ConfirmationBtn m_Cancel;
};

#endif // CARRENTALFORM_H
