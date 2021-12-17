#include "Sequence.cpp"
#include "List/ListSeq.cpp"
#include "Array/ArrSeq.cpp"
#include "Menu+helpful functions.cpp"
#include "complex.cpp"



const int SEQTYPE = 2; // Используем динамический массив (1 - односвязный список), так как с массивом быстрее.

int main()
{
    int check = 1;
    while (check) {
        switch (VAR) {
            case (1): {
                check = dialog<int>();
                break;
            }
            case (2): {
                check = dialog<double>();
                break;
            }
            case (3): {
                std::cout << "Complex numbers are compared modulo" << std::endl;
                std::cout << "Input it like a b (=a + bi)" << std::endl;
                check = dialog<complex>();
                break;
            }
            case (4): {
                check = dialog<std::string>();
                break;
            }
        }
    }
    return 0;
}

/*
int main()
{
    std::ofstream str("straight_tests.txt"), rev ("reverse_tests.txt"), random ("random_tests.txt");
    for (size_t size = 10; size <= 100000; size *= 10)
    {
        std::cout << size << std::endl;
        make_straight_tests(size, str, rev);
        make_random_tests(size, random);
    }
    return 0;
}
*/