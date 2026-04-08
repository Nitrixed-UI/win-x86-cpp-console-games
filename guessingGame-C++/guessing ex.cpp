#include <iostream>
#include <random>
#include <chrono>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

int create_num(u64 low, u64 high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<u64> dis(low, high);
    return dis(gen);
}

int main()
{
    u64 number = create_num(1, 100);
    u64 guess = 0;
    u64 attempts = 0;

    while (guess != number)
    {
        std::cout << "Enter your guess (between 1 and 100): ";
        std::cin >> guess;
        attempts++;

        if (guess < number)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else if (guess > number)
        {
            std::cout << "Too high! Try again." << std::endl;
        }
        else
        {
            std::cout << "Congratulations! You've guessed the number in " << attempts << " attempts!" << std::endl;
        }
    }
    return 0;
}