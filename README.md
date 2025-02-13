Zoek Invoegpositie
Makkelijk
Onderwerpen: Algoritmen

Gegeven een gesorteerde array met unieke gehele getallen en een doelwaarde (target), retourneer de index als de doelwaarde wordt gevonden. Als de doelwaarde niet in de array zit, retourneer dan de index waar deze zou worden ingevoegd om de volgorde te behouden.

uitbreiding
Je moet een algoritme schrijven met een tijdcomplexiteit van O(log n).

Voorbeeld 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Voorbeeld 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Voorbeeld 3:
Input: nums = [1,3,5,6], target = 7
Output: 4


#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
   int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // Target is gevonden op de index mid
        } else if (nums[mid] < target) {
            left = mid + 1;  // Target is groter, dus zoek rechts
        } else {
            right = mid - 1; // Target is kleiner, dus zoek links
        }
    }

    return left;  // Het invoegpunt van het target als het niet gevonden is//Vul hier jouw code in

}

// Testfunctie
void runTests() {
    struct TestCase {
        int nums[10]; // Maximale grootte voor testcases
        int size;
        int target;
        int expected;
    };

    struct TestCase testCases[] = {
        {{1, 3, 5, 6}, 4, 5, 2},  // Doelwaarde zit in de array
        {{1, 3, 5, 6}, 4, 2, 1},  // Doelwaarde zou op index 1 moeten worden ingevoegd
        {{1, 3, 5, 6}, 4, 7, 4},  // Doelwaarde komt achteraan
        {{1, 3, 5, 6}, 4, 0, 0},  // Doelwaarde komt vooraan
        {{1}, 1, 0, 0},           // Enkelvoudige element test (voor de waarde)
        {{1}, 1, 2, 1},           // Enkelvoudige element test (achter de waarde)
        {{1, 2, 4, 6, 8, 10}, 6, 3, 2},  // Tussen twee getallen
        {{1, 3, 5, 7, 9}, 5, 6, 3}       // Getal past tussen 5 en 7
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    int passed = 0;

    for (int i = 0; i < numTests; i++) {
        struct TestCase test = testCases[i];
        int result = searchInsert(test.nums, test.size, test.target);
        if (result == test.expected) {
            printf("✅ Test %d geslaagd: target = %d, verwacht = %d, output = %d\n", 
                   i + 1, test.target, test.expected, result);
            passed++;
        } else {
            printf("❌ Test %d mislukt: target = %d, verwacht = %d, output = %d\n", 
                   i + 1, test.target, test.expected, result);
        }
    }

    printf("\nTests voltooid: %d/%d geslaagd\n", passed, numTests);
}

int main() {
    runTests();
    return 0;
}

Beperkingen:

1 <= nums.length <= 10⁴
-10⁴ <= nums[i] <= 10⁴
De array nums bevat unieke waarden die in oplopende volgorde zijn gesorteerd.
-10⁴ <= target <= 10⁴
