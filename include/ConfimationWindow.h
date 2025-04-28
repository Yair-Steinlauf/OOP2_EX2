#pragma once
#include "BookingForm.h"
#include "ConfirmationBtn.h"




class ConfimationWindow {
public:
    ConfimationWindow(std::string formTitle,
        std::vector<std::string> texts,
        std::vector<std::string> fields,
        std::vector<std::string> errors,
        std::vector<std::string> specialErrors);
    void render();

private:   
    std::string formTitle;
    std::vector<Text> m_texts;
    ConfirmationBtn m_approve;
    ConfirmationBtn m_cancel;
    bool approved = true;
};