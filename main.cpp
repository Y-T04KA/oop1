#include <QtCore/QCoreApplication>
#include <iostream>
#include <number.h>
#include <Tcomplex.h>


class matrix {
public:
    void make(int s) {//метод когда матрицу вводим на месте
        size = s;
        m.clear();//очищаем матрицу, если у нас была одна 
        for (size_t i = 0; i < s; ++i)
        {
            Row row(s);
            for (size_t j = 0; j < s; ++j) std::cin >> row[j];
            m.push_back(row); 
        }
        isUsed = true;
    };

    void show() {
        check();
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j) std::cout << m[i][j] << " ";
            std::cout << std::endl;
        }
        return;
    }

    void findDet() {
        check();
        cc = m;//на всякий случай, работаем с копией матрицы
        for (int i = 0; i < size; i++) {
            int k = i;
            for (int j = i + 1; j < size; j++) {
                number a = cc[j][i], b = cc[k][i];
                if (a.abs() > b.abs())
                    k = j;
            }
            cc[i].swap(cc[k]);//тут должны меняться строки матрицы
            if (i != k) det *= -1;
            det *= cc[i][i];
            for (int j = i + 1; j < size; j++) cc[i][j] /= cc[i][i];
            for (int j = 0; j < size; j++)
                if ((j != i))
                    for (k = i + 1; k < size; k++)
                        cc[j][k] -= cc[i][k] * cc[j][i];
        }
        std::cout << det << std::endl;
    };

    void transpon() {
        check();
        cc = m;
        number cache;
        for (int i = 0; i<size; i++)
            for (int j = i; j < size; j++) {
                cache = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = cache;
            }
       show();
       m = cc; 
    }

    void ranking() {
        check();
        cc = m;
        std::vector<bool> line_used(size);
        for (int i = 0; i < size; i++) {
            int j;
            for (j=0; j<size;j++) 
                if (!line_used[j]) break;
            if (j == size) --rank;
            else
            {
                line_used[j] = true;
                for (int p = i + 1; p < size; ++p) cc[j][p] /= cc[j][i];
                for (int k = 0; k < size; ++k)
                    if (k != j)
                        for (int p = i + 1; p < size; ++p)
                            cc[k][p] -= cc[j][p] * cc[k][i];
            }
        }
        std::cout << "ранг - " << rank << std::endl;
    }
        
private:
    number det = 1;
    typedef std::vector<std::vector<number>> Matrix;
    typedef std::vector<number> Row;
    Matrix m,cc;
    int size=3,rank=size;
    bool isUsed = false;//показывает иницилизирована ли матрица, если нет возьмем дефолтную
    void check() {
        if (!isUsed) {
            make(3, true);
            std::cout << "Не введена матрица, используется матрица по умолчанию\n";
        }
    };
    number def[9] = { 1,2,3,4,1,6,7,8,1 };
    void make(int s, bool based) {//метод когда у нас уже есть значения, should start with make(3,true)
        size_t x = 0; size = s;
        for (size_t i = 0; i < s; ++i)
        {
            Row row(s);
            for (size_t j = 0; j < s; ++j, ++x) row[j] = def[x];
            m.push_back(row); 
        }
        isUsed = true;
    };
};

class App {
public:
    void welcome() {
        std::cout << "Список команд:\n1 ввести матрицу\n2 найти определитель\n3 транспонировать\n4 найти ранг\n5 текущий объект\n6 выход\n";
        std::cin >> state;
        move(state);
    }
private:
    int state=0;
    void enter() {
        std::cout << "Введите размер новой матрицы:\n";
        int size;
        std::cin >> size;
        std::cout << "Введите числа через Enter\n";
        instance.make(size);
        state = 0;
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
        instance.transpon();
        state = 0;
        move(state);
    }
    void rank() {
        instance.ranking();
        state = 0;
        move(state);
    }
    void move(int state) {
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
    void current() {
        std::cout << "Текущий объект матрицы:\n";
        instance.show();
        state = 0;
        move(state);
    }
    matrix instance;
};

int main(int argc, char *argv[])
{
    std::cout << "ООП ПР1\n";
    std::cout << "Роженко К.Е., Матвеев С.А., группа 0375\n";
    App l;
    l.welcome();
    return 0;
}
