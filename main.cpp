/*
 * This project was written in C++14 standard,
 * and can only be used in Linux.
 */

#include <iostream>
#include <random>
#include <vector>

#define UPPER_LIMIT 10000
#define LOWER_LIMIT 100

std::vector<int> g_exercise_num = {5, 25, 125};

int generateTrueRandomNum(int lower_limit, int upper_limit) {
    std::random_device rand;
    return rand() % (upper_limit - lower_limit + 1) + lower_limit;
}

int main() {
    int multiplier1, multiplier2, answer, result, which;

    restart:

    which = generateTrueRandomNum(0, g_exercise_num.size() - 1);
    multiplier1 = generateTrueRandomNum(LOWER_LIMIT, UPPER_LIMIT);
    multiplier2 = g_exercise_num[which];
    result = multiplier1 * multiplier2;

    std::cout << "The question is: " << std::endl;
    std::cout << multiplier1 << " * " << multiplier2 << " =  ";
    std::cin >> answer;

    if (answer == result) {
        std::cout << "You are right!" << std::endl;
    } else {
        std::cout << "You are wrong! The correct answer is " << result << std::endl;
    }

    std::cout << "Do you want to try again? [y/n]: ";
    char ch;
    std::cin >> ch;
    if (ch == 'y' || ch == 'Y') goto restart;

    return 0;
}