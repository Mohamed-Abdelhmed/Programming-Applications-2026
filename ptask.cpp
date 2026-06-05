/*
A)

a) Recursion:
   A function that calls itself to solve a smaller version of the same problem,
   with a base case that stops the recursion.

b) Iteration vs Recursion:
   - Iteration uses loops (for/while) to repeat code.
   - Recursion uses a function calling itself.
   - Iteration is generally more memory-efficient; recursion is often more readable
     for problems that are naturally self-similar (e.g. tree traversal, factorial).

c) Infinite Recursion:
   When a recursive function never reaches its base case, causing it to call itself
   forever until the stack overflows. Similar to an infinite loop but crashes
   the program with a stack overflow error.

d) Guides when writing Recursive Functions:
   1. Identify the base case(s) — the condition(s) that stop the recursion.
   2. Ensure each recursive call moves closer to the base case.
   3. Make sure the problem is divided into smaller sub-problems each call.
   4. Avoid redundant recursive calls (or use memoization).
   5. Be aware of stack depth — deep recursion can cause stack overflow.

e) Demerits of Recursive Techniques:
   1. High memory usage — each call adds a frame to the call stack.
   2. Slower than iteration due to function call overhead.
   3. Risk of stack overflow for deep or infinite recursion.
   4. Harder to debug and trace for complex problems.
   5. Some languages/compilers don't optimize tail recursion.
*/


// B)

#include <iostream>
using namespace std;

int multiplyIterative(int a, int b) {
    int result = 0;
    bool negative = (a < 0) != (b < 0);
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    for (int i = 0; i < b; i++)
        result += a;
    return negative ? -result : result;
}

int multiplyRecursive(int a, int b) {
    if (b == 0) return 0;
    if (b < 0) return -multiplyRecursive(a, -b);
    return a + multiplyRecursive(a, b - 1);
}

// C)

int largest(const int list[], int lowerIndex, int upperIndex) {
    if (lowerIndex == upperIndex)
        return list[lowerIndex];
    int maxOfRest = largest(list, lowerIndex + 1, upperIndex);
    return (list[lowerIndex] > maxOfRest) ? list[lowerIndex] : maxOfRest;
}

// D)

bool ValueInList(int list[], int searchItem, int startIndex, int length) {
    while (startIndex <= length - 1) {
        if (list[startIndex] == searchItem) {
            cout << "Found at index: " << startIndex << endl;
            return true;
        }
        startIndex++;
    }
    return false;
}

int main() {
    cout << "B: Multiply" << endl;
    cout << "Iterative 6 x 7 = " << multiplyIterative(6, 7) << endl;
    cout << "Recursive 6 x 7 = " << multiplyRecursive(6, 7) << endl;

    cout << "\nC: Largest in array" << endl;
    int arr[] = {3, 1, 9, 4, 7, 2};
    int n = 6;
    cout << "Largest = " << largest(arr, 0, n - 1) << endl;

    cout << "\nD: ValueInList (iterative)" << endl;
    int list[] = {10, 20, 30, 40, 50};
    int len = 5;
    bool found = ValueInList(list, 30, 0, len);
    if (!found) cout << "Not found" << endl;
    found = ValueInList(list, 99, 0, len);
    if (!found) cout << "99 not found" << endl;

    return 0;
}
