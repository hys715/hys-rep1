#include <cstdio>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;

void gotoxy(int x, int y)
{
    COORD C;
    C.X = x, C.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
}

class Screen{
    public:
        static const int width = 80;
        static const int height = 40;
        int record = 0, mode = 0;

        void init();

        bool game_start();
        bool game_over(int);
        bool game_win();

        void print_map();
        void print_info();
        void print_speed(int);
        void print_score(int);
};

void Screen::init()
{
    char buff[32];
    sprintf_s(buff, "mode con cols=%d lines=%d", width, height);
    system(buff);

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(handle, &cursor);
    cursor.bVisible = false;
    SetConsoleCursorInfo(handle, &cursor);

    srand((unsigned int)time(0));
}

bool Screen::game_start()
{
    char ch;
    system("cls");
    gotoxy(width / 2 - 5, height / 2 - 5);
    printf("请选择游戏模式：");
    gotoxy(width / 2 - 5, height / 2 - 3);
    printf("1.简单模式");
    gotoxy(width / 2 - 5, height / 2 - 1);
    printf("2.困难模式");
    gotoxy(width / 2 - 5, height / 2 + 1);
    printf("请输入你的选择->");
    ch = _getch();
    gotoxy(width / 2 - 5, height / 2 + 3);
    printf("按任意键开始...");
    if (ch == '1' || ch == '2')
        mode = ch - '0';
    else
        return false;
    ch = _getch();
    return true;
}

bool Screen::game_over(int score)
{
    record = score > record ? score : record;
    char ch;
    bool f = true;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
    gotoxy(width / 2 - 25, height / 2 - 5);
    printf("游戏结束    得分：%d", score);
    gotoxy(width / 2 - 25, height / 2 - 3);
    printf("1.我不服，再来一局");
    gotoxy(width / 2 - 25, height / 2 - 1);
    printf("2.辣鸡游戏，退了退了");
    gotoxy(width / 2 - 25, height / 2 + 1);
    printf("请输入你的选择->");
    ch = _getch();
    gotoxy(width / 2 - 25, height / 2 + 3);
    printf("按任意键继续...");
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (ch == '1')
        f = false;
    else
        f = true;
    ch = _getch();
    system("cls");
    return f;
}

bool Screen::game_win()
{
    record = 1000;
    char ch;
    bool f = true;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
    gotoxy(width / 2 - 25, height / 2 - 5);
    printf("---恭喜 你赢了---");
    gotoxy(width / 2 - 25, height / 2 - 3);
    printf("1.再虐它一次");
    gotoxy(width / 2 - 25, height / 2 - 1);
    printf("2.̫太简单了，退了退了");
    gotoxy(width / 2 - 25, height / 2 + 1);
    printf("请输入你的选择->");
    ch = _getch();
    gotoxy(width / 2 - 25, height / 2 + 3);
    printf("按任意键继续...");
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (ch == '1')
        f = false;
    else
        f = true;
    ch = _getch();
    system("cls");
    return f;
}

void Screen::print_map()
{
    system("cls");
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            if (i == 0 || i == height - 1)
                putchar('#');
            else if (j == 0 || j == width - 30 || j == width - 1)
                putchar('#');
            else if (i == height / 2 - 1 && j > width - 30)
                putchar('#');
            else
                putchar(' ');
        putchar('\n');
    }
}

void Screen::print_info()
{
    gotoxy(width - 22, height / 2 - 10);
    printf("当前游戏模式：");
    printf(mode == 1 ? "简单" : "困难");
    gotoxy(width - 22, height / 2 - 8);
    printf("历史最高分数：%d", record);

    gotoxy(width - 22, height / 2 + 4);
    printf("游戏操作说明：");
    gotoxy(width - 22, height / 2 + 6);
    printf("W：上    S：下");
    gotoxy(width - 22, height / 2 + 8);
    printf("A：左    D：右");
    
    gotoxy(width - 22, height - 8);
    printf("作者：HYS666");
    gotoxy(width - 22, height - 6);
    printf("版本：1.0");
}

void Screen::print_speed(int speed)
{
    gotoxy(width - 22, 6);
    printf("当前游戏速度：%d", speed);
}

void Screen::print_score(int score)
{
    gotoxy(width - 22, 8);
    printf("当前游戏分数：%d", score);
}

class Food{
    private:
        pair<int, int> coord;

    public:
        Food();
        void Ramdom(const vector<pair<int, int>> &);
        void drawfood();
        pair<int, int> getfood();
};

Food::Food() : coord({30, 20}) {}

void Food::Ramdom(const vector<pair<int, int>> &crd)
{
    coord.first = rand() % (Screen::width - 31) + 1;
    coord.second = rand() % (Screen::height - 2) + 1;
    for (int i = 0; i < (int)crd.size(); ++i)
        if (crd[i].first == coord.first && crd[i].second == coord.second)
        {
            coord.first = rand() % (Screen::width - 30) + 1;
            coord.second = rand() % (Screen::height - 4) + 2;
            i = 0;
        }
}

void Food::drawfood()
{
    gotoxy(coord.first, coord.second);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    putchar('$');
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

pair<int, int> Food::getfood() { return coord; }

class Snake{
    private:
        char direction;
        vector<pair<int, int>> crd;

    public:
        Snake();
        bool is_alive();
        bool is_eat(const pair<int, int> &, int &, int &);

        void move();
        void clear_tail();
        void draw_snake();
        vector<pair<int, int>> &get_snake();
};

Snake::Snake()
{
    direction = 'R';
    for (int i = 25; i > 20; --i)
        crd.push_back(make_pair(i, 20));
}

bool Snake::is_alive()
{
    if (crd[0].first < 1 || crd[0].first >= Screen::width - 30)
        return false;
    if (crd[0].second < 2 || crd[0].second >= Screen::height - 1)
        return false;
    for (int i = 1; i < (int)crd.size(); ++i)
        if (crd[0].first == crd[i].first && crd[0].second == crd[i].second)
            return false;
    return true;
}

bool Snake::is_eat(const pair<int, int> &food, int &score, int &speed)
{
    if (crd[0].first != food.first || crd[0].second != food.second)
        return false;
    score += 5;
    if (score % 50 == 0 && speed >= 75)
        speed -= 25;
    return true;
}

void Snake::move()
{
    char ch;
    if (_kbhit())
    {
        ch = _getch();
        switch(ch)
        {
            case 'w':
            case 'W':
                if (direction == 'D')
                    break;
                direction = 'U';
                break;
            case 's':
            case 'S':
                if (direction == 'U')
                    break;
                direction = 'D';
                break;
            case 'a':
            case 'A':
                if (direction == 'R')
                    break;
                direction = 'L';
                break;
            case 'd':
            case 'D':
                if (direction == 'L')
                    break;
                direction = 'R';
                break;
        }
    }

    pair<int, int> co({crd[0].first, crd[0].second});
    if (direction == 'U')
        --co.second;
    else if (direction == 'D')
        ++co.second;
    else if (direction == 'L')
        --co.first;
    else
        ++co.first;
    crd.insert(crd.begin(), co);
    gotoxy(crd[0].first, crd[0].second);

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    putchar('*');
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Snake::draw_snake()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    for (int i = 0; i < (int)crd.size(); ++i)
    {
        gotoxy(crd[i].first, crd[i].second);
        putchar('*');
    }
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Snake::clear_tail()
{
    gotoxy(crd[crd.size() - 1].first, crd[crd.size() - 1].second);
    putchar(' ');
    crd.erase(crd.end() - 1);
}

vector<pair<int, int>> &Snake::get_snake() { return crd; }

int main()
{
    Screen srn;
    int score, speed, flag;
    srn.init();
    while (true)
    {
        Food fd;
        Snake snk;
        if (srn.game_start())
        {
            score = 0, speed = srn.mode == 1 ? 300 : 200, flag = 0;
            srn.print_map();
            srn.print_info();
            snk.draw_snake();
            while (true)
            {
                srn.print_score(score);
                srn.print_speed(300 - speed);
                fd.drawfood();
                snk.move();
                if (snk.is_eat(fd.getfood(), score, speed))
                    fd.Ramdom(snk.get_snake());
                else
                    snk.clear_tail();
                if (!snk.is_alive())
                    break;
                if (score >= 1000)
                {
                    flag = 1;
                    break;
                }
                Sleep(speed);
            }
            if (flag == 1 && srn.game_win())
                break;
            else if (flag == 0 && srn.game_over(score))
                break;
        }
    }
    return 0;
}