

#include "Menu+helpful functions.h"
#include <time.h>
#include <fstream>

int stoi (const char *str)
{
    int ans = 0, i = 0;
    int sign = (str[0] == '-') ? -1: (((str[0] >= '0') && (str[0] <= '9')) ? 1: 0);
    if (sign == 0)
        return -1;
    while (str[i] != '\0')
    {
        if ((str[i] <= '9') && (str[i] >= '0'))
            ans = 10 * ans + str[i] - '0';
        else
            return -1;
        i++;
    }
    return sign * ans;
}

int *generate_seq (size_t size)
{
    int *data = (int *) calloc (size, sizeof(int));
    for (size_t i = 0; i < size; i++)
    {
        int t = rand() % 100000 - 20000;
        *(data + i) = t;
    }
    return data;
}


int variable_choice()
{
    while (1)
    {
        std::cout << "What type of data do u use?" << std::endl << "1. Integer" << std::endl << "2. Float" << std::endl
        << "3. Complex" << std::endl << "4. Strings" << std::endl;
        char *c = new char (100);
        std::cin >> c;
        int ans = stoi (c);
        delete c;
        if ((ans > 0) && (ans < 5))
            return ans;
        else
            std::cout << "Wrong number, plaese, try again!" << std::endl;
    }
}

int choice_()
{
    while (true) {
        char *ch = new char (100);
        std::cout << "What do you wanna do?" << std::endl;
        for (auto & i : MSGS)
            std::cout << i << std::endl;
        std::cin >> ch;
        int choice = stoi(ch);
        delete ch;
        if ((choice >= 0) && (choice < MSGS_SIZE))
            return choice;
        else
            std::cout << "You entered a wrong number, plaese, try again!" << std::endl;
        }
}


template <class T>
int dialog()
{
    int choice = choice_();
    while (true)
    switch (choice)
    {
        case(0):
        {
            std::cout << "Good Bye!" << std::endl;
            return 0;
        }
        case(1)://Shell sort
        {
            size_t size = 0;
            T* data = EnterSequence<T>(&size);
            Sequence<T> *array = NewSequence(2, data, size);
            std::cout << "Shell sort result: " << std::endl;
            (shell_sort(array, comp))->Print();
            delete[] data;
            array->Delete();
            choice = choice_();
            break;
        }
        case(2):
        {
            size_t size = 0;
            T* data = EnterSequence<T>(&size);
            Sequence<T> *array = NewSequence(2, data, size);
            std::cout << "Selection sort result: " << std::endl;
            (selection_sort(array, comp))->Print();
            delete[] data;
            array->Delete();
            choice = choice_();
            break;
        }
        case (3):
        {
            size_t size = 0;
            T* data = EnterSequence<T>(&size);
            Sequence<T> *array = NewSequence(2, data, size);
            std::cout << "Bubblesort result: " << std::endl;
            (bubble_sort(array, comp))->Print();
            delete[] data;
            array->Delete();
            choice = choice_();
            break;
        }
        case (4):
        {
            size_t size = 0;
            T* data = EnterSequence<T>(&size);
            Sequence<T> *array = NewSequence(2, data, size);
            std::cout << "Insertion sort result: " << std::endl;
            (insertion_sort(array, comp))->Print();
            delete[] data;
            array->Delete();
            choice = choice_();
            break;
        }
        case (5):
        {
            size_t size = 0;
            T* data = EnterSequence<T>(&size);
            Sequence<T> *array = NewSequence(2, data, size);
            std::cout << "Pair insertion sort result: " << std::endl;
            (pair_insertion_sort(array, comp))->Print();
            delete[] data;
            array->Delete();
            choice = choice_();
            break;
        }
        case(6):
        {
            size_t size = 0;
            std::cout << "Enter length of sequence :";
            std::cin >> size;
            int *data = generate_seq(size);
            Sequence<int> *array = NewSequence(2, data, size);
            std::cout << "Time of shell sort for dynamic array: " << sort_timer<int>(shell_sort, array, comp) << std::endl;
            array->Delete();
            array = NewSequence(2, data, size);
            std::cout << "Time of selection sort for dynamic array: " << sort_timer<int>(selection_sort, array, comp) << std::endl;
            array->Delete();
            array = NewSequence(2, data, size);
            std::cout << "Time of bubblesort for dynamic array: " << sort_timer<int>(bubble_sort, array, comp) << std::endl;
            array->Delete();
            array = NewSequence(2, data, size);
            std::cout << "Time of insertion sort for dynamic array: " << sort_timer<int>(insertion_sort, array, comp) << std::endl;
            array->Delete();
            array = NewSequence(2, data, size);
            std::cout << "Time of pair insertion sort for dynamic array: " << sort_timer<int>(pair_insertion_sort, array, comp) << std::endl;
            delete[] data;
            array->Delete();
            choice = choice_();
            break;
        }
        case (7):
        {
            VAR = variable_choice();
            return 1;
        }
    }
}

int comp (int a, int b)
{
    return a > b? 1 : (a == b)? 0: -1;
}

int comp (double a, double b)
{
    return a > b? 1 : (a == b)? 0: -1;
}

int comp (const std::string a, const std::string b) // Лексикографическое сравнение.
{
    return a > b? 1 : (a == b)? 0: -1;
}

int comp (complex a, complex b)
{
    return a.module() > b.module() ? 1: (a.module() == b.module() ? 0: -1);
}

template <class T>
void swap (T *first, T *second)
{
    T temp = *first;
    *first = *second;
    *second = temp;
}

template<class T>
Sequence<T> *NewSequence(int seqtype, T *data, size_t size)
{
    if (seqtype == 1)
        return data == NULL? (Sequence<T> *) new ListSeq<T>(): (Sequence<T> *) new ListSeq<T>(data, size);
    else
        return data == NULL? (Sequence<T> *) new ArrSeq<T> (): (Sequence<T> *) new ArrSeq<T> (data, size);
}

template <class T>
Sequence<T> *selection_sort (Sequence<T> *seq, int (*comp)(T, T))
{
    size_t size = seq->GetSize();
    for (size_t now_i = 0; now_i < size; now_i++)
    {
        T* min_item = seq->GetPointer(now_i);
        for (size_t j = now_i; j < size; j++)
        {
            T *temp = seq->GetPointer(j);
            if (comp(*temp, *min_item) < 0)
                min_item = temp;
        }
        swap (min_item, seq->GetPointer(now_i));
    }
    return seq;
}

template<class T>
Sequence<T> *shell_sort(Sequence<T> *seq, int (comp)(T, T))
{
    size_t size = seq->GetSize();
    for (size_t dist = size / 2; dist > 0; dist /= 2) // Выбираем интервалы
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i; j < size; j += dist)
            {
                T *lptr = seq->GetPointer(i), *rptr = seq->GetPointer(j);
                if (comp(*lptr, *rptr) > 0)
                    swap(lptr, rptr);
            }
        }
    }
    return seq;
}

template <class T>
Sequence<T> *bubble_sort (Sequence<T> *seq, int (comp)(T, T))
{
    size_t size = seq->GetSize();
    for (size_t i = 0; i < size; i++)
        for (size_t j = i; j < size; j++)
        {
            T *first = seq->GetPointer(i), *second = seq->GetPointer(j);
            if (comp (*second, *first) < 0)
                swap (first, second);
        }
    return seq;
}

template <class T>
Sequence<T> *insertion_sort (Sequence<T> *seq, int (comp)(T, T))
{
    size_t size = seq->GetSize();
    for (int i = 0; i < size; i++)
    {
        T *item = seq->GetPointer(i);
        int j = i - 1;
        while ((j >= 0) && (comp(*(seq->GetPointer(j)), *item) > 0))
        {
            T *j_pointer = seq->GetPointer(j);
            swap (item, j_pointer);
            item = j_pointer;
            j--;
        }
    }
    return seq;
}

template <class T>
Sequence <T> *pair_insertion_sort (Sequence<T> *seq, int (comp)(T, T))
{
    size_t size = seq->GetSize();
    for (int i = 0; i < size; i += 2)
    {
        T* big_item = seq->GetPointer(i), *small_item = seq->GetPointer(0);
        if (i != size - 1)
            small_item = seq->GetPointer(i + 1);
        if (comp (*small_item, *big_item) > 0)
            swap (small_item, big_item);
        int big_index = i;
        int j = big_index - 1;
        while ((j >= 0) && (comp(*(seq->GetPointer(j)), *big_item) > 0))
        {
            T *j_pointer = seq->GetPointer(j);
            swap (big_item, j_pointer);
            big_item = j_pointer;
            j--;
        }
        if (i == size - 1)
            break;
        j++;
        for (size_t index = i + 1; ((index > 0) && (index > j)); index--)
            swap (seq->GetPointer(index), seq->GetPointer(index - 1));
        small_item = seq->GetPointer(j);
        j--;
        while ((j >= 0) && (comp(*(seq->GetPointer(j)), *small_item) > 0))
        {
            T *j_pointer = seq->GetPointer(j);
            swap (small_item, j_pointer);
            small_item = j_pointer;
            j--;
        }
    }
    return seq;
}

template<class T>
T *EnterSequence(size_t *size)
{
    std::cout << "Enter number of elements: ";
    int n = -1;
    while (n < 1)
    {
        char *ch = new char (100);
        std::cin >> ch;
        n = stoi(ch);
        delete ch;
    }
    *size = n;
    T *data = (T *) new T [n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> data[i];
    }
    return data;
}

template<class T>
double sort_timer(Sequence<T> *(*sort_function)(Sequence<T> *, int (*)(T, T)), Sequence<T> *seq, int (*comp)(T, T))
{
    clock_t begin = clock();
    sort_function(seq, comp);
    begin = clock() - begin;
    return ((double)begin / CLOCKS_PER_SEC);
}

int *generate_straight_seq (size_t size)
{
    int *data = (int *) calloc (size, sizeof(int));
    for (int i = 0; i < size; i++)
        *(data + i) = i;
    return data;
}

void reverse_data (int *data, size_t size)
{
    for (size_t i = 0; 2 * i < size; i++)
        swap (data + i, data + size - 1 - i);
}

void make_straight_tests (size_t size, std::ofstream &outstr, std::ofstream &outrev)
{
    int *data = generate_straight_seq(size);
    Sequence<int> *array = NewSequence(2, data, size);
    outstr << size << " ";
    outstr << sort_timer<int>(shell_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outstr << sort_timer<int>(selection_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outstr << sort_timer<int>(bubble_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outstr << sort_timer<int>(insertion_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outstr << sort_timer<int>(pair_insertion_sort, array, comp) << std::endl;
    array->Delete();
    reverse_data(data, size);
    std::cout << "Reversed";
    array = NewSequence(2, data, size);
    outrev << size << " ";
    outrev << sort_timer<int>(shell_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outrev << sort_timer<int>(selection_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outrev << sort_timer<int>(pair_insertion_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outrev << sort_timer<int>(pair_insertion_sort, array, comp) << " ";
    array->Delete();
    array = NewSequence(2, data, size);
    outrev << sort_timer<int>(pair_insertion_sort, array, comp) << std::endl;
    array->Delete();
    delete[] data;
}
void make_random_tests (size_t size, std::ofstream &out)
{
    size_t number_of_iterations = 20;
    double time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0;
    for (size_t iteration = 0; iteration < number_of_iterations; iteration++)
    {
        int *data = generate_seq(size);
        Sequence<int> *array = NewSequence(2, data, size);
        time1 += sort_timer<int>(shell_sort, array, comp);
        array->Delete();
        array = NewSequence(2, data, size);
        time2 += sort_timer<int>(selection_sort, array, comp);
        array->Delete();
        array = NewSequence(2, data, size);
        time3 += sort_timer<int>(bubble_sort, array, comp);
        array->Delete();
        array = NewSequence(2, data, size);
        time4 += sort_timer<int>(insertion_sort, array, comp);
        array->Delete();
        array = NewSequence(2, data, size);
        time5 += sort_timer<int>(pair_insertion_sort, array, comp);
        array->Delete();
        delete[] data;
    }
    out << size << " " << time1 / (float)number_of_iterations << " "  << time2 / (float)number_of_iterations << " " <<
    time3 / (float)number_of_iterations << " " << time4 / (float)number_of_iterations << " " <<
    time5 / (float)number_of_iterations << std::endl;
}