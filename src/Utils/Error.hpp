/*
** EPITECH PROJECT, 2022
** SnakeGame
** File description:
** TODO: add description
*/
#ifndef SNAKEGAME_ERROR_HPP
#define SNAKEGAME_ERROR_HPP

#include <stdexcept>
#include <limits>
#include <utility>

class Error : std::exception
{
public:
    explicit Error(std::string error_msg) : _error_msg(std::move(error_msg)){};
    ~Error() override= default;;

    [[nodiscard]] const char *what() const noexcept override {return _error_msg.c_str();};
private:
    std::string _error_msg;
protected:
};

#endif //SNAKEGAME_ERROR_HPP
