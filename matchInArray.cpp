// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in January 2021
// Program generates random numbers and checks for matches with user input

#include <iostream>
#include <random>
#include <array>


template<size_t N>
int match(std::array<int, N> random_numbers, int number) {
    // Checks if there are any matches

    int match;

    for (int single_element : random_numbers) {
        if (number == single_element) {
            match = 1;
            break;
        } else {
            match = 0;
        }
    }

    return match;
}


int main() {
    // Generates random numbers and displays a match

    const int NUMBER_OF_ELEMENTS = 10;
    int number;
    int match_number;
    std::string number_string;
    std::array<int, 10> random_numbers;

    std::cout << "I check if your number matches a number in"
    << "a random list of elements!" << std::endl;

    for (int loop_counter = 0; loop_counter < NUMBER_OF_ELEMENTS;
         loop_counter++) {
        auto resized_random_numbers = random_numbers;

        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1, 100);
        random_numbers[loop_counter] = idist(rgen);

        if (loop_counter < NUMBER_OF_ELEMENTS - 1) {
            std::cout << random_numbers[loop_counter] << ", ";
        } else {
            std::cout << random_numbers[loop_counter] << '\n' << std::endl;
        }
    }

    while (true) {
        std::cout << "Number to check: ";
        std::cin >> number_string;
        try {
            number = std::stoi(number_string);
            break;
        } catch (std::invalid_argument) {
            std::cout << "This isn't a valid input" << std::endl;
        }
    }

    match_number = match(random_numbers, number);

    if (match_number == 1) {
        std::cout << "Your number matches at least "
        << "one element in the list!" << std::endl;
    } else {
        std::cout << "Your number does not match "
        << "any number in the list!" << std::endl;
    }
}
