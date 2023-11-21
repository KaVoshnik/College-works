#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

#ifdef _WIN32
#define msleep(x) Sleep(x)
#else
#include <unistd.h>
#define msleep(x) usleep(x * 1000)
#endif

using namespace std;

#define __WORLD_HEIGHT__ 9
#define __WORLD_WIDTH__ 9

struct point {
    unsigned is_live = 1;
};

void init_world(point world[][__WORLD_HEIGHT__])
{
    unsigned int i, j;

    ifstream save2("save2.txt", ios::in);

    if (save2.is_open())
    {
        cout << "You selected this save:" << endl;

        for (i = 0; i < __WORLD_WIDTH__; i++) {
            for (j = 0; j < __WORLD_HEIGHT__; j++) {
                save2 >> world[i][j].is_live;
            }
        }

        cout << endl;
        cout << endl;
    }
}

/*
 * Вывести на экран игровое поле
*/
void print_world(point world[][__WORLD_HEIGHT__])
{
    unsigned int i, j;
    for (i = 0; i < __WORLD_WIDTH__; i++) {
        for (j = 0; j < __WORLD_HEIGHT__; j++) {
            if (world[i][j].is_live == 1) {
                cout << "@";
            }
            else {
                cout << ".";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}


/*
 * Количество живых клеток на игровом поле
*/
unsigned int get_live_count(point world[][__WORLD_HEIGHT__])
{
    unsigned int count = 0;
    unsigned i, j;
    for (i = 0; i < __WORLD_WIDTH__; i++) {
        for (j = 0; j < __WORLD_HEIGHT__; j++) {
            if (world[i][j].is_live == 1) {
                count++;
            }
        }
    }
    return count;
}


/*
 * Получение координат соседей точки (окрестность мура 1 порядка)
*/
void read_point_neighbors(signed int nb[][2], unsigned int x, unsigned int y)
{
    unsigned int i, j;
    unsigned int k = 0;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) {
                continue;
            }
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
    }
}


/*
 * Количество живых соседей у клетки с координатами x, y
 */
unsigned int count_live_neighbors(point world[][__WORLD_HEIGHT__], unsigned int x, unsigned int y)
{
    unsigned int count = 0;
    unsigned int i;
    signed int nb[8][2];
    signed int _x, _y;

    read_point_neighbors(nb, x, y);

    for (i = 0; i < 8; i++) {
        _x = nb[i][0];
        _y = nb[i][1];

        if (_x < 0 || _y < 0) {
            continue;
        }
        if (_x >= __WORLD_WIDTH__ || _y >= __WORLD_HEIGHT__) {
            continue;
        }

        if (world[_x][_y].is_live == 1) {
            count++;
        }
    }

    return count;
}


/*
 * Сгенерировать следующее поколение игрового мира
 */
void next_generation(point world[][__WORLD_HEIGHT__], point prev_world[][__WORLD_HEIGHT__])
{
    unsigned int i, j;
    unsigned int live_nb;
    point p;

    for (i = 0; i < __WORLD_WIDTH__; i++) {
        for (j = 0; j < __WORLD_HEIGHT__; j++) {
            p = prev_world[i][j];
            live_nb = count_live_neighbors(prev_world, i, j);

            if (p.is_live == 0) {
                if (live_nb == 3) {
                    world[i][j].is_live = 1;
                }
            }
            else {
                if (live_nb < 2 || live_nb > 3) {
                    world[i][j].is_live = 0;
                }
            }
        }
    }
}


/*
 * Копирование игрового мира. Используется для сохранения предыдущего поколения
*/
void copy_world(point src[][__WORLD_HEIGHT__], point dest[][__WORLD_HEIGHT__])
{
    unsigned int i, j;
    for (i = 0; i < __WORLD_WIDTH__; i++) {
        for (j = 0; j < __WORLD_HEIGHT__; j++) {
            dest[i][j] = src[i][j];
        }
    }
}


/*
 * Сравнение игровых миров текущего и предыдущего поколения
 */
int cmp_world(point w1[][__WORLD_HEIGHT__], point w2[][__WORLD_HEIGHT__])
{
    unsigned int i, j;
    for (i = 0; i < __WORLD_WIDTH__; i++) {
        for (j = 0; j < __WORLD_HEIGHT__; j++) {
            if (w1[i][j].is_live != w2[i][j].is_live) {
                return -1;
            }
        }
    }
    return 0;
}


int main()
{
    point world[__WORLD_WIDTH__][__WORLD_HEIGHT__];
    point prev_world[__WORLD_WIDTH__][__WORLD_HEIGHT__];

    init_world(world);
    unsigned int live_points = -1;
    bool is_optimal = false;

    bool isKeyPressed = false;

    
    do {
       
        while (true) {
            if (GetAsyncKeyState(VK_SPACE)) {
                if (!isKeyPressed) {

                    print_world(world);
                    copy_world(world, prev_world);
                    next_generation(world, prev_world);


                    isKeyPressed = true;
                }
            }
            else {
                isKeyPressed = false;
            }
        }

        is_optimal = cmp_world(world, prev_world) == 0;
        live_points = get_live_count(world);

        if (is_optimal) {
            cout << "Optimal configuration detected" << endl;
        }

        if (live_points == 0) {
            cout << "All points died" << endl;
        }
        msleep(1000);
    } while (live_points != 0 && !is_optimal);

    return 0;
}
