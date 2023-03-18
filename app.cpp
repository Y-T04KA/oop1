#include <app.h>



    void App::welcome() {
        std::cout << "Список команд:\n1 ввести матрицу\n2 найти определитель\n3 транспонировать\n4 найти ранг\n5 текущий объект\n6 выход\n";
        std::cin >> state;
        move(state);
    }
    void App::enter() {
        std::cout << "Введите размер новой матрицы:\n";
        int size;
        std::cin >> size;
        std::cout << "Введите числа через Enter\n";
        instance.make(size);
        state = 0;
        move(state);
    }
    void App::deter() {
        std::cout << "Определитель матрицы - ";
        instance.findDet();
        state = 0;
        move(state);
    }
    void App::trans() {
        std::cout << "Транспонирование матрицы:\n";
        instance.transpon();
        state = 0;
        move(state);
    }
    void App::rank() {
        instance.ranking();
        state = 0;
        move(state);
    }
    void App::move(int state) {
        switch (state)
        {
        case 0:return welcome(); break;
        case 1:return enter(); break;
        case 2:return deter(); break;
        case 3:return trans(); break;
        case 4:return rank(); break;
        case 5:return current(); break;
        default:
            break;
        }
    }
    void App::current() {
        std::cout << "Текущий объект матрицы:\n";
        instance.show();
        state = 0;
        move(state);
    }