#include <curses.h>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <list>
using namespace std;

#define Winner_Score 500
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
        TypeName(const TypeName&);         \
        void operator=(const TypeName&)
typedef pair<int, int> Coord;

class Window{
    public:
        static const int _lines = 40, _cols = 100;
        static Window *getInstance();
        static void destroyInstance();

        void setmode(int order);
        int getmode();
        void error();
        bool begin();
        bool over(int score);
        void map_info();
        void game_info(int speed, int score);

    private:
        int mode, srecord = 0, hrecord = 0;
        static Window *_instance;

        Window() {};
        ~Window() {};
        DISALLOW_COPY_AND_ASSIGN(Window);
};

Window *Window::_instance = NULL;

Window *Window::getInstance()
{
    if (!_instance)
        _instance = new Window;
    return _instance;
}

void Window::destroyInstance()
{
    if (_instance)
        delete _instance;
    _instance = NULL;
}

void Window::setmode(int order) { mode = order; }

int Window::getmode() { return mode; }

void Window::error()
{
    clear();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvaddstr(_lines / 2, _cols / 2 - 5, "Error! Bye!");
    attroff(COLOR_PAIR(1));
}

bool Window::begin()
{
    char ch;
    clear();
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvaddstr(_lines / 2 - 4, _cols / 2 - 14, "Welcome to Game Snake!");
    mvaddstr(_lines / 2 - 2, _cols / 2 - 14, "Please select game mode:");
    mvaddstr(_lines / 2, _cols / 2 - 10, "1.Simple mode");
    mvaddstr(_lines / 2 + 2, _cols / 2 - 10, "2.Hard mode");
    ch = getch();
    if (ch == '1' || ch == '2')
    {
        setmode(ch - '0');
        mvaddstr(_lines / 2 + 4, _cols / 2 - 14, "Press any key to continue...");
        ch = getch();
        attroff(COLOR_PAIR(2));
        return true;
    }
    attroff(COLOR_PAIR(2));
    error();
    return false;
}

bool Window::over(int score)
{
    char ch;
    if (mode == 1)
        srecord = score > srecord ? score : srecord;
    else
        hrecord = score > hrecord ? score : hrecord;
    if (score == Winner_Score)
    {
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        attron(COLOR_PAIR(3));
        mvaddstr(_lines / 2 - 4, _cols / 2 - 34, "Congratulations! You win!");
        attroff(COLOR_PAIR(3));
    }
    else
    {
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        mvaddstr(_lines / 2 - 4, _cols / 2 - 34, "Sorry! You lost!");
        attroff(COLOR_PAIR(1));
    }
    attron(COLOR_PAIR(2));
    mvaddstr(_lines / 2 - 2, _cols / 2 - 32, "1.Once more");
    mvaddstr(_lines / 2, _cols / 2 - 32, "2.Quit");
    ch = getch();
    if (ch == '1' || ch == '2')
    {
        setmode(ch - '0');
        mvaddstr(_lines / 2 + 2, _cols / 2 - 34, "Press any key to continue...");
        attroff(COLOR_PAIR(2));
        if (ch == '1')
        {
            ch = getch();
            return false;
        }
        else
        {
            ch = getch();
            return true;
        }
    }
    attroff(COLOR_PAIR(2));
    error();
    return true;
}

void Window::map_info()
{
    clear();
    for (int i = 0; i < _lines; ++i)
        for (int j = 0; j < _cols; ++j)
            if (i == 0 || i == _lines - 1)
                mvaddch(i, j, '#');
            else if (j == 0 || j == _cols - 1 || j == _cols - 40)
                mvaddch(i, j, '#');
            else if (i == _lines / 2 - 1 && j > _cols - 40)
                mvaddch(i, j, '#');
    if (mode == 1)
        mvaddstr(_lines / 2 - 10, _cols - 30, "Current mode: Simple");
    else
        mvaddstr(_lines / 2 - 10, _cols - 30, "Current mode: Hard");
    if (mode == 1)
        mvprintw(_lines / 2 - 8, _cols - 30, "Record high: %d", srecord);
    else
        mvprintw(_lines / 2 - 8, _cols - 30, "Record high: %d", hrecord);
    mvaddstr(_lines / 2 + 4, _cols - 30, "Game instructions:");
    mvaddstr(_lines / 2 + 6, _cols - 30, "W:Up    S:Down");
    mvaddstr(_lines / 2 + 8, _cols - 30, "A:Left  D:Right");
    mvaddstr(_lines - 8, _cols - 30, "Developer: HYS666");
    mvaddstr(_lines - 6, _cols - 30, "Version: 1.0");
}

void Window::game_info(int speed, int score)
{
    mvprintw(6, _cols - 30, "Current speed: %d", speed);
    mvprintw(8, _cols - 30, "Current score: %d", score);
}

class Food{
    public:
        static Food *getInstance();
        static void destroyInstance();

        Coord &getpos();
        void product(list<Coord> &snake_body);
        void display();

    private:
        static Food *_instance;
        Coord pos = {20, 50};

        Food() {}
        ~Food() {}
        DISALLOW_COPY_AND_ASSIGN(Food);
};

Food *Food::_instance = NULL;

Food *Food::getInstance()
{
    if (!_instance)
        _instance = new Food;
    return _instance;
}

void Food::destroyInstance()
{
    if (_instance)
        delete _instance;
    _instance = NULL;
}

Coord &Food::getpos() { return pos; }

void Food::product(list<Coord> &snake_body)
{
    pos.first = rand() % (Window::_lines - 2) + 1;
    pos.second = rand() % (Window::_cols - 41) + 1;
    list<Coord>::iterator it = snake_body.begin();
    for (; it != snake_body.end(); ++it)
        if (pos.first == it->first && pos.second == it->second)
        {
            pos.first = rand() % (Window::_lines - 2) + 1;
            pos.second = rand() % (Window::_cols - 41) + 1;
        }
}

void Food::display()
{
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvaddch(pos.first, pos.second, '$');
    attroff(COLOR_PAIR(3));
}

class Snake{
    public:
        static Snake *getInstance();
        static void destroyInstance();

        bool is_eat(Coord &food);
        bool is_alive();

        list<Coord> &getbody();
        void move();
        void clear_tail();
        void display();

    private:
        static Snake *_instance;
        list<Coord> body;
        char toward = 'D';

        Snake() {}
        ~Snake() {}
        DISALLOW_COPY_AND_ASSIGN(Snake);
};

int kbhit()
{
    struct timeval tv;
    fd_set rdfs;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);
    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

Snake *Snake::_instance = NULL;

Snake *Snake::getInstance()
{
    if (!_instance)
        _instance = new Snake;
    return _instance;
}

void Snake::destroyInstance()
{
    if (_instance)
        delete _instance;
    _instance = NULL;
}

bool Snake::is_eat(Coord &food)
{
    if (body.front().first == food.first && body.front().second == food.second)
        return true;
    return false;
}

bool Snake::is_alive()
{
    if (body.front().first < 1 || body.front().first >= Window::_lines - 1)
        return false;
    if (body.front().second < 1 || body.front().second >= Window::_cols - 40)
        return false;
    list<Coord>::iterator it = body.begin();
    for (++it; it != body.end(); ++it)
        if (it->first == body.front().first && it->second == body.front().second)
            return false;
    return true;
}

list<Coord> &Snake::getbody() { return body; }

void Snake::move()
{
    char ch;
    if (kbhit())
    {
        ch = getch();
        switch(ch)
        {
            case 'w':
            case 'W':
                if (toward == 'S')
                    break;
                toward = 'W';
                break;
            case 's':
            case 'S':
                if (toward == 'W')
                    break;
                toward = 'S';
                break;
            case 'a':
            case 'A':
                if (toward == 'D')
                    break;
                toward = 'A';
                break;
            case 'd':
            case 'D':
                if (toward == 'A')
                    break;
                toward = 'D';
                break;
        }
    }

    Coord coo({body.front().first, body.front().second});
    if (toward == 'W')
        --coo.first;
    else if (toward == 'S')
        ++coo.first;
    else if (toward == 'A')
        --coo.second;
    else
        ++coo.second;
    body.push_front(coo);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvaddch(coo.first, coo.second, '*');
    attroff(COLOR_PAIR(4));
}

void Snake::clear_tail()
{
    mvaddch(body.back().first, body.back().second, ' ');
    body.pop_back();
}

void Snake::display()
{
    for (int i = 30; i > 25; --i)
        body.push_back({20, i});
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    for (list<Coord>::iterator it = body.begin(); it != body.end(); ++it)
        mvaddch(it->first, it->second, '*');
    attroff(COLOR_PAIR(4));
}

class Game{
    public:
        static Game *getInstance();
        static void destroyInstance();

        void init();
        bool start();
        void onging();
        bool end();

    private:
        static Game *_instance;
        Window *window;
        Food *food;
        Snake *snake;
        int speed, score;

        Game() { window = Window::getInstance(); }
        ~Game() { Window::destroyInstance(); }
        DISALLOW_COPY_AND_ASSIGN(Game);
};

Game *Game::_instance = NULL;

Game *Game::getInstance()
{
    if (!_instance)
        _instance = new Game;
    return _instance;
}

void Game::destroyInstance()
{
    endwin();
    if (_instance)
        delete _instance;
    _instance = NULL;
}

void Game::init()
{
    initscr();
    // keypad(stdscr, TRUE);
    curs_set(0);
    clear();
    raw();
    noecho();
    start_color();
}

bool Game::start()
{
    bool f = window->begin();
    if (f)
    {
        score = 0;
        speed = window->getmode() == 1 ? 300 : 150;
        food = Food::getInstance();
        snake = Snake::getInstance();
    }
    return f;
}

bool Game::end()
{
    Food::destroyInstance();
    Snake::destroyInstance();
    return window->over(score);
}

void Game::onging()
{
    window->map_info();
    snake->display();
    refresh();
    while (true)
    {
        window->game_info((310 - speed) / 10, score);
        food->display();
        snake->move();
        if (snake->is_eat(food->getpos()))
        {
            food->product(snake->getbody());
            ++score;
            if (score % 5 == 0 && speed >= 70)
                speed -= 20;
        }
        else
            snake->clear_tail();
        refresh();
        if (!snake->is_alive() || score >= 500)
            break;
        usleep(speed * 1000);
    }
}

int main()
{
    Game *game = Game::getInstance();
    game->init();
    while (true)
    {
        if (!game->start())
            break;
        game->onging();
        if (game->end())
            break;
    }
    usleep(1000 * 1000);
    game->destroyInstance();
    return 0;
}