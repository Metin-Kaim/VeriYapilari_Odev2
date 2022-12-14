#include <iostream>
#include "Queue.hpp"
#include "RadixSort.hpp"

// Function to get the maximum value in the array
int RadixSort::getMax(Hucre *arr, int n)
{
    int max = arr[0].veri;
    for (int i = 1; i < n; i++)
        if (arr[i].veri > max)
            max = arr[i].veri;
    return max;
}

// Function to implement radix sort
void RadixSort::radixSort(Hucre *arr, int n)
{
    // Get the maximum value in the array
    int max = getMax(arr, n);

    // Create a queue for each digit (0-9)
    Kuyruk digitQueues[10];

    // Process the array, digit by digit
    for (int digit = 1; digit <= max; digit *= 10)
    {
        // Place each element in the queue corresponding to its digit
        for (int i = 0; i < n; i++)
            digitQueues[arr[i].veri / digit % 10].ekle(arr[i].veri);

        // Merge the queues back into the array
        int k = 0;
        for (int i = 0; i < 10; i++)
            while (!digitQueues[i].bosmu())
            {
                arr[k++].veri = digitQueues[i].getir();
                digitQueues[i].cikar();
            }
    }
}