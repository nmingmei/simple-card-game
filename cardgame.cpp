
/*

This is a program that reads 5 cards from the user, analyzes the cards and prints out the category of hand from these cards.

Poker hands are categorized according to the following labels: Straight flush,
four of a kind, full house, straight, flush, three of a kind, two pairs, pair, high card.

This program will ignore card suits, and face cards.
The values that the user inputs will be integer values from 2 to 9.
The program starts by collecting 5 integer values from the user and placing the integers into an array that has 5 elements.

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int ARRAY_SIZE = 5;

int cardCounter(const int hand[], int checkNumber);
int pairCounter(const int hand[]);
int handMax(const int hand[]);
int handMin(const int hand[]);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);

int main()
{
    int count = 0;
    int hand[ARRAY_SIZE];

    cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
    while (count < ARRAY_SIZE) {
        cout << "Card " << count + 1 << ": ";
        cin >> hand[count];
        count++;
    }
    if (containsFourOfaKind(hand)) {
        cout << "Four of a kind!" << endl;
    }
    else if (containsFullHouse(hand)) {
        cout << "Full house!" << endl;
    }
    else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    }
    else if (containsThreeOfaKind(hand)) {
        cout << "Three of a kind!" << endl;
    }
    else if (containsTwoPair(hand)) {
        cout << "Two Pair!" << endl;
    }
    else if (containsPair(hand)) {
            cout << "Pair!" << endl;
    }
    else {
        cout << "High Card!" << endl;
    }
    return 0;
}


/*
   Helper function that creates another array to help keep track of the number of occurrences (frequency) of all possible card values 2-9.

*/
int cardCounter(const int hand[], int checkNumber)
{
    // Length of cardCounts can be at max 8 => 9 - 2 + 1
    // Setting an array to {0} initializes it to all zeroes
    int cardCounts[8] = {0};

    for (int i = 0; i < 5; i++) {
        cardCounts[hand[i] - 2]++;
    }
    return cardCounts[checkNumber - 2];
}

/*
   Helper function that counts the number of pairs in the card hand.

*/
int pairCounter(const int hand[])
{
    int count = 0;
    for (int p = 0; p < 5; p++) {
        if ((cardCounter(hand, hand[p])) == 2) {
            count++;
        }
    }
    return count/2;
}


/*
   Helper function that returns the value of the highest card in the hand.

*/
int handMax(const int hand[])
{
    int max = hand[0];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        max = (hand[i] > max) ? hand[i] : max;
    }
    return max;
}

/*
   Helper function that returns the value of the lowest card in the hand.

*/
int handMin(const int hand[])
{
    int min = hand[0];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        min = (hand[i] < min) ? hand[i] : min;
    }
    return min;
}


/*
   Checks to see if the hand contains a pair.

*/
bool  containsPair(const int hand[])
{
    if (pairCounter(hand) == 1) {
        return true;
    }
    return false;
}


/*
   Checks to see if the hand contains two pairs.

*/
bool  containsTwoPair(const int hand[])
{
    if (pairCounter(hand) == 2) {
        return true;
    }
    return false;
}

/*
   Checks to see if the hand contains 3 cards that have the same value.

*/
bool  containsThreeOfaKind(const int hand[])
{
    for (int p = 0; p < 5; p++) {
        if ((cardCounter(hand, hand[p])) == 3) {
            return true;
        }
    }
    return false;
}


/*
   Checks to see if the entire hand consists of consecutive values.

*/
bool  containsStraight(const int hand[])
{
    for (int p = 0; p < 5; p++) {
        if (((cardCounter(hand, hand[p])) != 1) || (handMax(hand) - handMin(hand) != 4)) {
            return false;
        }
    }
    return true;
}

/*
   Checks to see if the hand contains 3 of the same value and the 2 remaining values are a pair as well.

*/
bool  containsFullHouse(const int hand[])
{
    if (containsThreeOfaKind(hand) && containsPair(hand)) {
        return true;
    }
    return false;
}

/*
   Checks to see if the hand contains four cards that are the same value.

*/
bool  containsFourOfaKind(const int hand[])
{
    for (int p = 0; p < 5; p++) {
        if ((cardCounter(hand, hand[p])) == 4) {
            return true;
        }
    }
    return false;
}






/*
output of program (not continuously playing, each game separated by a divider):

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 8
Card 2: 7
Card 3: 8
Card 4: 2
Card 5: 7
Two Pair!

________________________

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 8
Card 2: 7
Card 3: 4
Card 4: 6
Card 5: 5
Straight!
________________________

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 9
Card 2: 2
Card 3: 3
Card 4: 4
Card 5: 5
High Card!


*/
