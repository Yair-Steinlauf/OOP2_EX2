#include "CarRentalForm.h"
#include "DialogueManager.h"
#include "ConfimationWindow.h"
#include <iostream>
#include <ctime>  // For getting current date
#include "IDValidator.h"
#include "Address.h"
#include "AddressValidator.h"
#include "EmailValidator.h"
#include "RentTotalDayValidator.h"
#include "YesNoValidator.h"
#include "CarAndGpsValidator.h"
#include "DateValidator.h"


CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
    fieldLabels.insert(fieldLabels.end(), {
        "Pickup Location:",
        "Pickup Date:", "Rent total days:",
        "GPS needed?", "Child Seat needed?",
        "Car Type:"
        });
    
    createFields();
    std::vector<std::unique_ptr<SelectionButton>> selectionButton;    

    int yOffset = 60 + 50 * m_textFields.size();
    createTextFieldsAndSetFieldLocation(yOffset);
   yOffset -= 10;

   createPickButton(selectionButton, yOffset);

   int buttonY = yOffset + 40;
   createConfirmationBtn(buttonY);

  }

void CarRentalForm::createConfirmationBtn(int buttonY)
{
    m_Done = ConfirmationBtn("Done", sf::Vector2f(20, buttonY), sf::Color(50, 150, 50));
    m_Cancel = ConfirmationBtn("Cancel", sf::Vector2f(200, buttonY), sf::Color(180, 0, 0));
}

void CarRentalForm::createPickButton(std::vector<std::unique_ptr<SelectionButton>>& selectionButton, int yOffset)
{
    float carTypeButtonX = 20;
    for (int i = 0; i < carTypeSelection.size(); ++i) {
        selectionButton.push_back(std::make_unique<SelectionButton>(carTypeSelection[i], sf::Vector2f(carTypeButtonX, yOffset)));
        carTypeButtonX += 105;  // ✅ Increased spacing

    }
    auto field = std::move(m_inputFields.back());
    m_inputFields.pop_back();
    m_selectionField = SelectionField(std::move(field), std::move(selectionButton));
}

void CarRentalForm::createTextFieldsAndSetFieldLocation(int& yOffset)
{
    for (int i = m_textFields.size(); i < fieldLabels.size(); i++) {
        m_textFields.push_back((Text(fieldLabels[i], sf::Vector2f(20, yOffset))));
        m_inputFields[i].get()->setLocation(sf::Vector2f(250, yOffset));
        yOffset += 50;
    }
}

void CarRentalForm::createFields()
{
    m_inputFields.push_back(std::make_unique<Field<AddressValidator, Address>>(Address())); // pickup location
    m_inputFields.push_back(std::make_unique<Field<DateValidator, Date>>(Date())); // pickup location
    m_inputFields.push_back(std::make_unique<Field<RentTotalDayValidator, int>>(0)); // rent total days
    m_inputFields.push_back(std::make_unique<Field<YesNoValidator, std::string>>("")); // gps needed
    m_inputFields.push_back(std::make_unique<Field<YesNoValidator, std::string>>("")); // child seat
    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>("")); // car type
}



void CarRentalForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);  

    userInput[5] = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);
	userInput[9] = "Economy";
}

std::string CarRentalForm::getFormType() const {
    return "Car Rental";
}

void CarRentalForm::render(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    window.clear(sf::Color(235, 235, 235));

    // ✅ Title
    sf::Text title("Car Rental Form", font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    for (auto& object : m_inputFields) {
        object.get()->draw(window);
    }
    for (auto& object : m_textFields) {
        object.draw(window);
    }
    m_selectionField.draw(window);
    m_selectionField.update(cursorTimer.getElapsedTime());

    m_Done.draw(window);
    m_Cancel.draw(window);
    // ✅ Render input fields dynamically
   int yOffset = 60;
   for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
        yOffset += 50;
    }
  
}

void CarRentalForm::handleInput(sf::Event event) {
    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
    if (event.type == sf::Event::MouseButtonPressed) {

        for (int i = 0; i < m_inputFields.size(); i++)
        {
            m_inputFields[i].get()->onReleaseClick();
            if (m_inputFields[i].get()->contains(mousePos)) {
                activeField = i;
                m_inputFields[i].get()->onPressClick();
            }
        }
        if (m_selectionField.contains(mousePos))
            m_selectionField.handleEvent(event);

        if (m_Cancel.contains(mousePos))
            window.close();
        if (m_Done.contains(mousePos)) {
            std::vector<std::string> errors = this->validate();
            std::vector<std::string> speicalErrors = this->multiFieldValidate();
            std::vector<std::string> userInputs;
            for (auto& input : m_inputFields)
            {
                userInputs.push_back(input.get()->getText());
            }
            userInputs.push_back(m_selectionField.getString());
            errors.push_back(""); // not error option in last field
            auto confirmationWindow = ConfimationWindow("Car Rental", fieldLabels, userInputs, errors,  speicalErrors);
            confirmationWindow.render();
        }


    }
    if (event.type == sf::Event::TextEntered) {
        m_inputFields[activeField].get()->handleInput(event);
    }

}

std::vector<std::string> CarRentalForm::validate()
{
    std::vector<std::string> errors;
    for (auto& field : m_inputFields) {
        errors.push_back(field.get()->getError());
    }
    return errors;
}

std::vector<std::string> CarRentalForm::multiFieldValidate()
{
    std::vector<std::string> errorList;
    std::vector<std::string> data;
    data.push_back(m_inputFields[7].get()->getText());
    data.push_back(m_selectionField.getString());
    bool isCarGpsValid = CarAndGpsValidator::validate(data);
    
    isCarGpsValid ? errorList.push_back("") : errorList.push_back(CarAndGpsValidator::getError());
    return errorList;
}


