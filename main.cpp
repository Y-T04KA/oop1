#include <QtCore/QCoreApplication>
#include <iostream>
#include <number.h>
#include <cmath>


class matrix {
public:
    void make(int s) {//метод когда матрицу вводим на месте
        size = s;
        for (size_t i = 0; i < s; ++i)
        {
            Row row(s);

            for (size_t j = 0; j < s; ++j)
            {
                std::cin >> row[j];
            }

            m.push_back(row); // push each row after you fill it
        }
        isUsed = true;
    };

    void make(int s, bool based) {//метод когда у нас уже есть значения, should start with make(3,true)
        size_t x = 0; size = s;
        for (size_t i = 0; i < s; ++i)
        {
            Row row(s);

            for (size_t j = 0; j < s; ++j,++x)
            {
                row[j]=def[x];
            }

            m.push_back(row); // push each row after you fill it
        }
        isUsed = true;
    };

    void show() {
        check();
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }

    void findDet() {
        check();
        cc = m;//copy matrix for safety
        for (int i = 0; i < size; i++) {
            int k = i;
            for (int j = i + 1; j < size; j++) {
                if (abs(cc[j][i]) > abs(cc[k][i])) k = j;
            }
            if (abs(cc[k][i]) < eps) {
                det = 0;
                break;
            }
            cc[i].swap(cc[k]);//тут должны меняться строки матрицы
            if (i != k) det *= -1;
            det *= cc[i][i];
            for (int j = i + 1; j < size; j++) cc[i][j] /= cc[i][i];
            for (int j = 0; j < size; j++)
                if ((j != i) && abs(cc[j][i] > eps))
                    for (k = i + 1; k < size; k++)
                        cc[j][k] -= cc[i][k] * cc[j][i];
            
        }
        std::cout << det << std::endl;
    };

    void transphobia() {
        check();
        std::cout << "matrix above is first check\n";
        cc = m;
        number cache;
        for (int i = 0; i<size; i++)
            for (int j = 0; j < size; j++) {
                cache = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = cache;
                std::cout << "puff\n";
            }
        std::cout << "before show()\n";
        show();
        //m = cc; 
    }
        
private:
    number det = 1;
    typedef std::vector<std::vector<number>> Matrix;
    typedef std::vector<number> Row;
    Matrix m,cc;
    int size=3;
    const number eps = 0.01;
    bool isUsed = false;//показывает иницилизирована ли матрица, если нет возьмем дефолтную
    void check() {
        if (!isUsed) {
            make(3, true);
            std::cout << "No matrix found, using default\n";
        }
    };
    number def[9] = { 1,2,3,4,1,6,7,8,1 };
    
};

class App {
public:
    void wellcum() {
        std::cout << "Список команд:\n1 to enter matrix\n2 to find deter of matrix\n3 to form transpon matrix\n4 to find rank\n5 to show current object of matrix\n6 to exit\n";
        std::cin >> state;
        move(state);
    }
    
    void deter() {
        std::cout << "Определитель матрицы - ";
        instance.findDet();
        state = 0;
        move(state);
    }
    void trans() {
        std::cout << "Транспонирование матрицы:\n";
        instance.transphobia();
        state = 0;
        move(state);
    }

    void rank() {
        std::cout << "will count rank here\n";
        state = 0;
        move(state);
    }

    void current(){
        std::cout<< "something current\n";
        instance.show();
        state = 0;
        move(state);
    }
    
private:
    int state=0,size=3;
    void enter() {
        std::cout << "Введите размер новой матрицы:\n";
        std::cin >> size;
        std::cout << "Введите числа через Enter\n";
        instance.make(size);
        state = 0;
        move(state);
    }
    void move(int state) {
        switch (state)
        {
        case 0:return wellcum(); break;
        case 1:return enter(); break;
        case 2:return deter(); break;
        case 3:return trans(); break;
        case 4:return rank(); break;
        case 5:return current(); break;
        default:
            break;
        }
    }
    matrix instance;
};

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    std::cout << "ООП 1\n";
    App l;
    l.wellcum();
    //return a.exec();
    return 0;
}
