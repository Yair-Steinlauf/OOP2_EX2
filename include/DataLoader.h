#pragma once
#include "SFML/Graphics.hpp"

class DataLoader
{
public:
    static DataLoader& Init();
    DataLoader(const DataLoader&) = delete;
    void operator=(const DataLoader&) = delete;
    static sf::Font& getP2Font();

private:
    DataLoader();
    sf::Font m_font;
};