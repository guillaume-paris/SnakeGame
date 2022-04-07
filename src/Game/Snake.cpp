/*
** Personal PROJECT, 2022
** SnakeGame
** File description:
** SnakeGame Engine
*/

#include "Snake.hpp"

game::Snake::Snake(std::array<std::array<Map, 16>, 16> &map) {
    // generate the map
    for(int x = 0; x != 16; x++) {
        for(int y = 0; y != 16; y++) {
            if (x == 0 || y == 0 || x == 15 || y == 15) {
                map[x][y].setAsset("Wall");
                map[x][y].setChar("X");
            } else {
                map[x][y].setAsset("Empty");
                map[x][y].setChar(" ");
            }
        }
    }
    // place the snake at the middle of the screen
    this->snake_pos = {
        {7, 9},
        {7, 8},
        {7, 7},
        {7, 6},
        {7, 5},
    };
    // Generate 4 candies in the map randomly
    for (int i = 0; i != 4; i++)
        this->generateCandy(i);
}

game::Snake::~Snake() = default;

void game::Snake::generateCandy(int seed)
{
    srand((seed + time(NULL)));
    int x_candy = rand() % 14 + 1;
    int y_candy = rand() % 14 + 1;
    int already_exist;

    std::list<std::pair<int, int>>::iterator it_snake;
    std::list<std::pair<int, int>>::iterator it_candy;
    do {
        already_exist = 0;
        x_candy = rand() % 14 + 1;
        y_candy = rand() % 14 + 1;
        for (it_snake = this->snake_pos.begin(); it_snake != this->snake_pos.end(); ++it_snake){
            if (it_snake->first == x_candy && it_snake->second == y_candy)
                already_exist = 1;
        }
        for (it_candy = this->candy_pos.begin(); it_candy != this->candy_pos.end(); ++it_candy){
            if (it_candy->first == x_candy && it_candy->second == y_candy)
                already_exist = 1;
        }
    }
    while (already_exist == 1);
    this->candy_pos.push_front({x_candy, y_candy});
}

void game::Snake::eraseSnakeCandyOnMap(std::array<std::array<Map, Y_MAP>, X_MAP>& map)
{
    for(int x = 0; x != 16; x++) {
        for(int y = 0; y != 16; y++) {
            if (x == 0 || y == 0 || x == 15 || y == 15) {
                map[x][y].setAsset("Wall");
                map[x][y].setChar("X");
            } else {
                map[x][y].setAsset("Empty");
                map[x][y].setChar(" ");
            }
        }
    }
}

void game::Snake::moveBody()
{
    std::list<std::pair<int, int>>::iterator it;
    int x_prev, y_prev;
    int x_tmp, y_tmp;
    int tmp = 0;

    for (it = snake_pos.begin(); it != snake_pos.end(); ++it, tmp++){
        if (tmp == 0) {
            x_prev = it->first;
            y_prev = it->second;
        }
        else {
            x_tmp = it->first;
            y_tmp = it->second;
            it->first = x_prev;
            it->second = y_prev;
            x_prev = x_tmp;
            y_prev = y_tmp;
        }
    }
}

void game::Snake::moveSnakeHead(std::tuple<Inputs, std::size_t, std::size_t> input)
{
    std::list<std::pair<int, int>>::iterator it;
    int tmp = 0;
    int x_head = this->snake_pos.front().first;
    int y_head = this->snake_pos.front().second;
    int x_second;
    int y_second;

    for (it = this->snake_pos.begin(); it != this->snake_pos.end(); ++it, tmp++){
        if (tmp == 1) {
            x_second = it->first;
            y_second = it->second;
        }
    }
    // std::get<0>(input) to access to the first value of std::tuple
    if (x_head == x_second) {
        if (std::get<0>(input) == KEY_Q) {
            this->moveBody();
            this->snake_pos.front().first--;
        }
        else if (std::get<0>(input) == KEY_D) {
            this->moveBody();
            this->snake_pos.front().first++;
        }
        else if (y_head < y_second) {
            this->moveBody();
            this->snake_pos.front().second--;
        }
        else {
            this->moveBody();
            this->snake_pos.front().second++;
        }
    }
    // cas : (y_head == y_second)
    else {
        if (std::get<0>(input) == KEY_S) {
            this->moveBody();
            this->snake_pos.front().second++;
        }
        else if (std::get<0>(input) == KEY_Z) {
            this->moveBody();
            this->snake_pos.front().second--;
        }
        else if (x_head < x_second) {
            this->moveBody();
            this->snake_pos.front().first--;
        }
        else {
            this->moveBody();
            this->snake_pos.front().first++;
        }
    }
}

void game::Snake::addTailSnake()
{
    std::list<std::pair<int, int>>::iterator it_snake;
    std::list<std::pair<int, int>>::iterator penultimate;
    std::list<std::pair<int, int>>::iterator last;

    for (it_snake = this->snake_pos.begin(); it_snake != this->snake_pos.end(); ++it_snake){
        penultimate = last;
        last = it_snake;
    }
    // place a tail at the end horizontal
    if (penultimate->first == last->first) {
        this->snake_pos.emplace_back(last->first, (last->second + 1));

    }
    // place a tail at the end vertical
    if (penultimate->second == last->second) {
        this->snake_pos.emplace_back((last->first + 1), last->second);
    }
}

void game::Snake::eventSnakeEatCandy()
{
    // variable used for a better random seed
    int seed = 0;
    std::list<std::pair<int, int>>::iterator it_snake;
    std::list<std::pair<int, int>>::iterator it_candy;

    for (it_snake = this->snake_pos.begin(); it_snake != this->snake_pos.end(); ++it_snake, seed++){
        for (it_candy = this->candy_pos.begin(); it_candy != this->candy_pos.end(); ++it_candy){
            if (it_candy->first == it_snake->first && it_candy->second == it_snake->second) {
                it_candy = this->candy_pos.erase(it_candy);
                this->generateCandy(seed);
                this->addTailSnake();
            }
        }
    }
}

void game::Snake::placeSnakeCandyInMap(std::array<std::array<Map, X_MAP>, Y_MAP>&map)
{
    int tmp = 0;
    std::list<std::pair<int, int>>::iterator n;
    for (n = this->snake_pos.begin(); n != this->snake_pos.end(); n++) {
        if (tmp != 0) {
            map[n->first][n->second].setAsset("Body");
            map[n->first][n->second].setChar("O");
        }
        if (tmp == 0 || (this->snake_pos.front().first == n->first && this->snake_pos.front().second == n->second)) {
            map[n->first][n->second].setAsset("Head");
            map[n->first][n->second].setChar("0");
            tmp++;
        }
    }
    std::list<std::pair<int, int>>::iterator n_candy;

    for (n_candy = this->candy_pos.begin(); n_candy != this->candy_pos.end(); n_candy++) {
        map[n_candy->first][n_candy->second].setAsset("Candy");
        map[n_candy->first][n_candy->second].setChar("8");
    }
}

bool game::Snake::detectIfSnakeEatBody()
{
    std::list<std::pair<int, int>>::iterator it;
    int skip_first = 0;

    for (it = this->snake_pos.begin(); it != this->snake_pos.end(); ++it, skip_first++){
        if (skip_first != 0) {
            if (this->snake_pos.front().first == it->first && this->snake_pos.front().second == it->second)
                return (true);
        }
    }
    return (false);
}

bool game::Snake::detectIfSnakeHeadHitWall()
{
    if (this->snake_pos.front().first == 15 || this->snake_pos.front().second == 15 ||
        this->snake_pos.front().first == 0 || this->snake_pos.front().second == 0)
        return (true);
    return (false);
}

void game::Snake::print_map(std::array<std::array<Map, Y_MAP>, X_MAP> &map)
{
    for(int x = 0; x != 16; x++) {
        for(int y = 0; y != 16; y++) {
            std::cout << map[y][x].getChar();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool game::Snake::gameLogic(std::array<std::array<Map, X_MAP>, Y_MAP> &map,
                            std::tuple<Inputs, std::size_t, std::size_t> input) {
        //    delete the snake & candy in the map
        this->eraseSnakeCandyOnMap(map);
        //    move snake with the input
        this->moveSnakeHead(input);
        //    detect if snake eat a candy;
        this->eventSnakeEatCandy();
        //    place snake & candy in the map
        this->placeSnakeCandyInMap(map);
        //    detect if the snake eat his body
        if (this->detectIfSnakeEatBody())
            return (false);
        if (this->detectIfSnakeHeadHitWall())
            return (false);
        return (true);
}
