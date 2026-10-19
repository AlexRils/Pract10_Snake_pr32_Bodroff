// pr32_pract10_Bodroff.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>


struct Snake
{
    int y;

    int x;
};


struct SnakeSegment
{

    Snake snake;

    SnakeSegment* next;

};


struct Records
{
    char name[150];

    int points;

};


int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(0));

    SnakeSegment* listsegment = new SnakeSegment;

    listsegment->next = nullptr;

    bool cheksnake = false;

    int vibor = 0;

    int y = 20;

    int x = 20;

    bool chekfalse = false;

      /*  int map[20][20] = {

            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},


        };*/

        int map[20][20];
        
        for (int i = 0; i < 20; i++) {

            for (int j = 0; j < 20; j++) {

                map[i][j] = 0;

            }

        }
            
        int upravl = 2;

        int foody = 0;

        int foodx = 0;

        int chek = 0;

        int length = 1;

        char name[150];

    while (true) {

        chekfalse = false;

        std::cout << "\n1. Новая игра" << std::endl;
        std::cout << "2. Загрузить игру" << std::endl;
        std::cout << "3. Таблица рекордов" << std::endl;
        std::cout << "4. Выход" << std::endl;

        std::cin >> vibor;

        system("cls");

        if (vibor == 1) {

            SnakeSegment* current = listsegment;

            while (current != nullptr)
            {
                SnakeSegment* next = current->next;
                delete current;
                current = next;
            }

            listsegment = new SnakeSegment;
            listsegment->next = nullptr;

            length = 1;

            chek = 0;


            std::cout << "выберите координаты змейки y:" << std::endl;

            int y = 0;

            std::cin >> y;

            std::cout << "выберите координаты змейки x:" << std::endl;

            int x = 0;

            std::cin >> x;

            listsegment->snake.y = y;

            listsegment->snake.x = x;

            for (int i = 0; i < 20; i++) {

                for (int j = 0; j < 20; j++) {

                    if (i == listsegment->snake.y && j == listsegment->snake.x) {

                        map[i][j] = 5;

                   }

                }

            }

              upravl = 3;


             do {

                 foody = rand() % 20;

                 foodx = rand() % 20;

             } while ( listsegment->snake.y == foody && listsegment->snake.x == foodx);

              chek = 0;

              cheksnake = true;

        }
        else {

            if (vibor == 2) {

                std::ifstream file("snake.dat", std::ios::binary);

                if (file.is_open()) {

                    file.read((char*)&chek, sizeof(chek));

                    file.read((char*)&upravl, sizeof(upravl));

                    file.read((char*)&foody, sizeof(foody));

                    file.read((char*)&foodx, sizeof(foodx));

                    file.read((char*)&length, sizeof(length));

                    cheksnake = true;




                    SnakeSegment* current = listsegment;

                    while (current != nullptr) {

                        SnakeSegment* next = current->next;

                        delete current;

                        current = next;
                    }


                    listsegment = nullptr;

                    for (int i = 0; i < length; i++) {

                        int y;
                        int x;

                        file.read((char*)&y, sizeof(y));
                        file.read((char*)&x, sizeof(x));

                        SnakeSegment* newsegment = new SnakeSegment;

                        newsegment->snake.y = y;
                        newsegment->snake.x = x;

                        newsegment->next = nullptr;

                        if (listsegment == nullptr) {

                            listsegment = newsegment;
                        }
                        else {

                            current = listsegment;

                            while (current->next != nullptr) {

                                current = current->next;
                            }

                            current->next = newsegment;
                        }
                    }

                    file.close();

                }
                else {

                    std::cout << "файл не найден" << std::endl;
                }

               



            }
            else {


                if (vibor == 3) {

                    
                        std::ifstream file("record.dat", std::ios::binary);

                        if (file.is_open())
                        {
                            Records record;

                            while (file.read( reinterpret_cast<char*>(&record), sizeof(record)))
                            {
                                std::cout << "Имя: " << record.name << " Очки: " << record.points << std::endl;
                            }

                            file.close();
                        }
                        else
                        {
                            std::cout << "Файл не найден" << std::endl;
                        }
                    


                }


            }

        }



        if (cheksnake == true)
        {

            while (chekfalse != true)
            {


                if (_kbhit()) {

                    char knopka = _getch();


                    if (knopka == '1') {

                        if (upravl != 4) {
                           upravl = 1;
                        }
                        

                    }
                    else {

                        if (knopka == '2') {

                            if (upravl != 3) {
                             upravl = 2;
                            }
                          

                        }
                        else {

                            if (knopka == '3') {

                                if (upravl != 2) {

                                  upravl = 3;

                                }

                            }
                            else {
                                if (knopka == '4') {

                                    if (upravl != 1) {

                                    upravl = 4;

                                    }


                                }
                                else {

                                    if (knopka == '5') {

                                        length = 0;

                                        SnakeSegment* current = listsegment;

                                        while (current != nullptr) {

                                            length++;

                                            current = current->next;

                                        }

                                        std::ofstream file("snake.dat", std::ios::binary);

                                        if (file.is_open()) {

                                            file.write((char*)&chek, sizeof(chek));

                                            file.write((char*)&upravl, sizeof(upravl));

                                            file.write((char*)&foody, sizeof(foody));

                                            file.write((char*)&foodx, sizeof(foodx));

                                            file.write((char*)&length, sizeof(length));

                                            current = listsegment;

                                            while (current != nullptr) {

                                                file.write((char*)&current->snake.y, sizeof(current->snake.y));

                                                file.write((char*)&current->snake.x, sizeof(current->snake.x));

                                                current = current->next;
                                            }

                                            file.close();
                                        }
                                        else {

                                            std::cout << "файл не открылся" << std::endl;
                                        }

                                    }

                                }

                            }

                        }
                    }

                }


                int oldy = listsegment->snake.y;
                int oldx = listsegment->snake.x;

                int taily = listsegment->snake.y;
                int tailx = listsegment->snake.x;

                
                SnakeSegment* current = listsegment;

                while (current->next != nullptr)
                {
                    current = current->next;
                    taily = current->snake.y;
                    tailx = current->snake.x;
                }


                int tempy = listsegment->snake.y;
                int tempx = listsegment->snake.x;

                if (upravl == 1)
                {
                    listsegment->snake.y--;
                }
                else

                {
                    if (upravl == 2)
                    {

                        listsegment->snake.x--;

                    }
                    else {

                        if (upravl == 3)
                        {
                       
                           listsegment->snake.x++;

                        }
                        else {

                            if (upravl == 4)
                            {

                                listsegment->snake.y++;
                            }

                        }


                    }


                }

                map[tempy][tempx] = 0;

                if (listsegment->snake.x >= 20 || listsegment->snake.x < 0 || listsegment->snake.y >= 20 || listsegment->snake.y < 0) {

                    std::cout << "GAME OVER" << std::endl;

                    std::cout << "введите имя игрока" << std::endl;

                    std::cin >> name;

                    Records record;

                    for (int i = 0; i < 150; i++)
                    {
                        record.name[i] = name[i];
                    }

                    record.points = chek;

                    std::ofstream file("record.dat", std::ios::binary | std::ios::app);

                    file.write( reinterpret_cast<const char*>(&record), sizeof(record));

                    file.close();

                    break;

                }

                map[listsegment->snake.y][listsegment->snake.x] = 5;

                current = listsegment->next;

                while (current != nullptr)
                {
                    if (listsegment->snake.y == current->snake.y && listsegment->snake.x == current->snake.x)
                    {
                        std::cout << "GAME OVER" << std::endl;

                        std::cout << "введите имя игрока" << std::endl;

                        std::cin >> name;

                        Records record;

                        for (int i = 0; i < 150; i++)
                        {
                            record.name[i] = name[i];
                        }

                        record.points = chek;

                        std::ofstream file("record.dat", std::ios::binary | std::ios::app);

                        file.write(reinterpret_cast<const char*>(&record), sizeof(record));

                        file.close();

                        chekfalse = true;

                        break;
                    }

                    current = current->next;
                }

                if (chekfalse)
                {
                    break;
                }



                if (listsegment->snake.y == foody && listsegment->snake.x == foodx) {

                    chek++;

                    SnakeSegment* newsegment = new SnakeSegment;

                    newsegment->snake.y = taily;

                    newsegment->snake.x = tailx;

                    newsegment->next = nullptr;

                    current = listsegment;

                    while (current->next != nullptr)
                    {
                        current = current->next;
                    }

                    current->next = newsegment;

                    do {

                        foody = rand() % 20;

                        foodx = rand() % 20;

                    } while (listsegment->snake.y == foody && listsegment->snake.x == foodx);


                }

                int predy = oldy;

                int predx = oldx;

                current = listsegment->next;

                while (current != nullptr)
                {
                    int nexty = current->snake.y;

                    int nextx = current->snake.x;

                    current->snake.y = predy;

                    current->snake.x = predx;

                    predy = nexty;

                    predx = nextx;

                    current = current->next;
                }

                system("cls");

                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        map[i][j] = 0;
                    }
                }

                current = listsegment;

                while (current != nullptr)
                {
                    map[current->snake.y][current->snake.x] = 5;

                    current = current->next;
                }

                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (map[i][j] == 5)
                        {
                            std::cout << "O ";
                        }
                        else
                        {

                            if (i == foody && j == foodx) {

                                std::cout << "@ ";

                            }
                            else {

                                std::cout << ". ";

                            }
                        }
                    }

                    std::cout << std::endl;
                }



                std::cout << "_____Управление_____" << std::endl;
                std::cout << "вверх - 1 " << std::endl;
                std::cout << "влево - 2 " << std::endl;
                std::cout << "вправо - 3 " << std::endl;
                std::cout << "вниз - 4 " << std::endl;
                std::cout << "сохранение  - 5 " << std::endl;
                std::cout << "счет = " << chek << std::endl;
                std::cout << std::endl;

                Sleep(400);


            }

            cheksnake = false;
            
        }

    }



    




}


