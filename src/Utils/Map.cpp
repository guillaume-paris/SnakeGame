/*
** EPITECH PROJECT, 2022
** SnakeGame
** File description:
** TODO: add description
*/

#include "Map.hpp"

#include <utility>

Map::Map()
= default;

Map::~Map()
= default;

void Map::setAsset(std::string path_asset)
{
    _path_asset = std::move(path_asset);
}

std::string Map::getAsset()
{
    return _path_asset;
}

void Map::setChar(std::string char_)
{
    _char = std::move(char_);
}

std::string Map::getChar()
{
    return _char;
}