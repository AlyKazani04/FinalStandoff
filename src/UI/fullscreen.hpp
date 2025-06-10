#pragma once

#include <SFML/Graphics.hpp>
#include "../Constants/constants.hpp"

extern sf::Vector2u baseresolution;
extern sf::Vector2f baseresolutionbutfloat;

/// @brief  this function creates window in fullscreen or windowed depending on bool value
/// @param fullscreen true if screen to be created is fullscreen, false creates a windowed screen of size of baseresolution of map tiles
void createWindow(sf::RenderWindow& window, bool fullscreen);