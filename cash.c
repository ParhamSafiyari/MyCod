#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt user for the amount of change owed
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0); // make sure cents are non-negative

    // Calculate the number of each type of coin
    int quarters = calculate_quarters(cents);
    cents -= (quarters * 25);

    int dimes = calculate_dimes(cents);
    cents -= (dimes * 10);

    int nickels = calculate_nickels(cents);
    cents -= (nickels * 5);

    int pennies = calculate_pennies(cents);

    // Calculate and print the total number of coins
    int total_coins = quarters + dimes + nickels + pennies;

    // Print the number of each type of coin and the total
    printf("Quarters: %d\n", quarters);
    printf("Dimes: %d\n", dimes);
    printf("Nickels: %d\n", nickels);
    printf("Pennies: %d\n", pennies);
    printf("Total coins: %d\n", total_coins);
}

// Calculate quarters
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents -= 25;
    }
    return quarters;
}

// Calculate dimes
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents -= 10;
    }
    return dimes;
}

// Calculate nickels
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents -= 5;
    }
    return nickels;
}

// Calculate pennies
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents -= 1;
    }
    return pennies;
}
