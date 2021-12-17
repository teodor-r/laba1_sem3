

#ifndef LAB2_VECTOR_MENU_HELPFUL_FUNCTIONS_H
#define LAB2_VECTOR_MENU_HELPFUL_FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
#include "Sequence.h"
#include <cstring>
#include "complex.h"
#include <string>
#include <time.h>
#include <fstream>

int variable_choice();

int VAR = variable_choice();

const char *MSGS[] = {"0. Exit", "1. Shell sort", "2. Selection sort", "3. Bubble sort", "4. Insertion sort",
                      "5. Pair insertion sort", "6. Comparison all of methods", "7. Change variable type"};

const size_t MSGS_SIZE = (sizeof(MSGS) / sizeof(MSGS[0]));

template <class T>
Sequence<T> *NewSequence (int, T * = NULL, size_t = 0);

int stoi (const char *);

int choice_();

int dialog ();

template <class T>
void swap (T *, T *);

int comp (int, int);

int comp (double, double);

int comp (const std::string, const std::string);

int comp (complex, complex);

template <class T>
T *EnterSequence (size_t *);

template <class T>
Sequence<T> *selection_sort (Sequence<T> *, int (*)(T, T));

template <class T>
Sequence<T> *shell_sort (Sequence<T> *, int(*)(T, T));

template <class T>
Sequence<T> *bubble_sort (Sequence<T> *, int (*)(T, T));

template <class T>
Sequence<T> *insertion_sort (Sequence<T> *, int (*)(T, T));

template <class T>
Sequence<T> *pair_insertion_sort (Sequence <T> *, int (*)(T, T));

template <class T>
double sort_timer (Sequence<T> *(*)(Sequence<T> *, int (*)(T, T)), Sequence<T> *, int (*)(T, T));

int *generate_seq (size_t);

int *generate_straight_seq (size_t);

void reverse_data (int *, size_t);

void make_random_tests (size_t, std::ofstream &);

void make_straight_tests (size_t, std::ofstream &, std::ofstream &);


#endif //LAB2_VECTOR_MENU_HELPFUL_FUNCTIONS_H
