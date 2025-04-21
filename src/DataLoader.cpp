#include "DataLoader.h"

DataLoader& DataLoader::Init()
{
    static DataLoader instance;
    return instance;
}

sf::Font& DataLoader::getP2Font()
{
    auto& instance = Init();
    return instance.m_font;
}

DataLoader::DataLoader()
{
    m_font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
}
