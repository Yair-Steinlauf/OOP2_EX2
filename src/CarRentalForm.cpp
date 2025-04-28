#include "CarRentalForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {  // ✅ Calls base constructor
    fieldLabels.insert(fieldLabels.end(), {
        "Pickup Location:",
        "Pickup Date:", "Rent total days:",
        "GPS needed?", "Child Seat needed?",
        "Car Type:"
        });

    // add field:

    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>(""));
    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>(""));
    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>(""));
    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>(""));
    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>(""));
    m_inputFields.push_back(std::make_unique<Field<NameValidator, std::string>>(""));
    
    std::vector<std::unique_ptr<SelectionButton>> selectionButton;
    



    int yOffset = 60 + 50 * m_textFields.size();
    for (int i = m_textFields.size(); i < fieldLabels.size(); i++) {
        m_textFields.push_back((Text(fieldLabels[i], sf::Vector2f(20, yOffset))));
        m_inputFields[i].get()->setLocation(sf::Vector2f(250, yOffset));
        yOffset += 50;
    }


   yOffset -= 10;
   float carTypeButtonX = 20;
   for (int i = 0; i < carTypeSelection.size(); ++i) {
       selectionButton.push_back(std::make_unique<SelectionButton>(carTypeSelection[i], sf::Vector2f(carTypeButtonX, yOffset)));
       carTypeButtonX += 105;  // ✅ Increased spacing

   }
   auto field = std::move(m_inputFields.back());
   m_inputFields.pop_back();
   m_selectionField = SelectionField(std::move(field), std::move(selectionButton));

   //    sf::RectangleShape roomButton(sf::Vector2f(90, 30));
   //    roomButton.setPosition(carTypeButtonX, yOffset);
   //    roomButton.setFillColor(selectedCarType == i ? sf::Color(0, 120, 255) : sf::Color::White);  // ✅ Highlight selected
   //    roomButton.setOutlineThickness(2);
   //    roomButton.setOutlineColor(sf::Color(160, 160, 160));
   //    window.draw(roomButton);

   //    sf::Text roomText(carTypeSelection[i], font, 16);
   //    roomText.setFillColor(selectedCarType == i ? sf::Color::White : sf::Color::Black);
   //    roomText.setPosition(carTypeButtonX+10, yOffset + 5);
   //    window.draw(roomText);
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
    // ✅ Render input fields dynamically
   int yOffset = 60;
   for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
        /*sf::Text label(fieldLabels[i], font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(250, 35));
        inputBox.setPosition(250, yOffset - 5);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
        window.draw(inputBox);

        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible) {
            displayText += "|";
        }

        sf::Text inputText(displayText, font, 16);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(255, yOffset);
        window.draw(inputText);*/

        yOffset += 50;
    }
    //yOffset -= 10;
    //float carTypeButtonX = 20;
    //for (int i = 0; i < carTypeSelection.size(); ++i) {
    //    sf::RectangleShape roomButton(sf::Vector2f(90, 30));
    //    roomButton.setPosition(carTypeButtonX, yOffset);
    //    roomButton.setFillColor(selectedCarType == i ? sf::Color(0, 120, 255) : sf::Color::White);  // ✅ Highlight selected
    //    roomButton.setOutlineThickness(2);
    //    roomButton.setOutlineColor(sf::Color(160, 160, 160));
    //    window.draw(roomButton);

    //    sf::Text roomText(carTypeSelection[i], font, 16);
    //    roomText.setFillColor(selectedCarType == i ? sf::Color::White : sf::Color::Black);
    //    roomText.setPosition(carTypeButtonX+10, yOffset + 5);
    //    window.draw(roomText);

    //    carTypeButtonX += 105;  // ✅ Increased spacing
    //}
    //// ✅ "Done" and "Cancel" Buttons (positioned dynamically)
    //int buttonY = yOffset + 40;

    //sf::RectangleShape submitButton(sf::Vector2f(140, 40));
    //submitButton.setPosition(20, buttonY);
    //submitButton.setFillColor(sf::Color(50, 150, 50));
    //window.draw(submitButton);

    //sf::Text submitText("DONE", font, 20);
    //submitText.setFillColor(sf::Color::White);
    //submitText.setPosition(50, buttonY + 10);
    //window.draw(submitText);

    //sf::RectangleShape cancelButton(sf::Vector2f(140, 40));
    //cancelButton.setPosition(200, buttonY);
    //cancelButton.setFillColor(sf::Color(180, 0, 0));
    //window.draw(cancelButton);

    //sf::Text cancelText("CANCEL", font, 20);
    //cancelText.setFillColor(sf::Color::White);
    //cancelText.setPosition(230, buttonY + 10);
    //window.draw(cancelText);
   
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

    }
    if (event.type == sf::Event::TextEntered) {
        m_inputFields[activeField].get()->handleInput(event);
    }

    // TODO: אם מישהו נלחץ לשנות את שאר הצבעים בחזרה לרגיל.


   /* if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !userInput[activeField].empty()) {
            userInput[activeField].pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            userInput[activeField] += static_cast<char>(event.text.unicode);
        }
    }*/
   /* else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % userInput.size();
        }
        if (event.key.code == sf::Keyboard::Return) {
            std::cout << "Entered Data: ";
            for (const auto& field : userInput) std::cout << field << " ";
            std::cout << std::endl;
        }
    }*/
    //else if (event.type == sf::Event::MouseButtonPressed) {
    //    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
    //    int yOffset = 60;

    //    for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
    //        sf::FloatRect inputBoxBounds(240, yOffset - 5, 250, 35);
    //        if (inputBoxBounds.contains(mousePos)) {
    //            activeField = i;
    //            return;
    //        }
    //        yOffset += 50;
    //    }
    //    yOffset -= 10;
    //    // ✅ Handle Car Type Button Click          
    //    float carTypeButtonX = 20;
    //    for (int i = 0; i < carTypeSelection.size(); ++i) {
    //        sf::FloatRect timeButtonBounds(carTypeButtonX, yOffset, 90, 30);
    //        if (timeButtonBounds.contains(mousePos)) {
    //            selectedCarType = i;
    //            //Update the "Car Type" input box
    //            userInput[9] = carTypeSelection[i];

    //            return;
    //        }
    //        carTypeButtonX += 105;  // Move to next button
    //    }
    //     yOffset += 40;

        /*if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Car Rental Confirmed!\n";
            openConfirmationWindow();
            return;
        }

        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= yOffset && mousePos.y <= yOffset + 40) {
            std::cout << "Cancelled Car Rental\n";
            formManager->closeForm();
            return;
        }*/
    //}
}


