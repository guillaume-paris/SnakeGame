/*
** EPITECH PROJECT, 2022
** SnakeGame
** File description:
** TODO: add description
*/
#ifndef SNAKEGAME_MAP_HPP
#define SNAKEGAME_MAP_HPP

#include <iostream>
#include <memory>
#include <string>
#include <array>

class Map
{
public:
    Map();
    ~Map();

    void setAsset(std::string path_asset);
    void setChar(std::string char_);
    std::string getAsset();
    std::string getChar();
private:
    std::string _path_asset;
    std::string _char;
protected:
};

#endif //SNAKEGAME_MAP_HPP
