#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

/*
    Klasa szablonowa MergeSort implementująca algorytm sortowania przez scalanie.
    Dzięki zastosowaniu szablonów (template) może obsługiwać dowolny typ danych:
    int, long, float, double, itp.
*/
template <typename T>
class MergeSort
{
public:
    /*
        Publiczna funkcja sortująca.
        Przyjmuje wektor i sortuje go rosnąco.
        Jeśli tablica ma 0 lub 1 element – nic nie robi.
    */
    void sort(std::vector<T>& arr)
    {
        if (arr.size() <= 1) return;   // tablica pusta lub jednoelementowa
        mergeSort(arr, 0, arr.size() - 1);
    }

private:

    /*
        Główna rekursywna funkcja mergeSort.
        Dzieli tablicę na dwie części, sortuje obie części, a następnie scala.
    */
    void mergeSort(std::vector<T>& arr, int left, int right)
    {
        if (left >= right) return; // warunek zakończenia – jeden element

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // sortuj lewą część
        mergeSort(arr, mid + 1, right);  // sortuj prawą część

        merge(arr, left, mid, right);    // scal posortowane części
    }

    /*
        Funkcja scalająca dwie posortowane połowy tablicy.
        Wynik scalania zapisuje z powrotem do arr.
    */
    void merge(std::vector<T>& arr, int left, int mid, int right)
    {
        std::vector<T> temp;
        int i = left;       // początek lewej części
        int j = mid + 1;    // początek prawej części

        // Scalanie dwóch uporządkowanych podtablic
        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        // Dopisz pozostałe elementy lewej części
        while (i <= mid)
            temp.push_back(arr[i++]);

        // Dopisz pozostałe elementy prawej części
        while (j <= right)
            temp.push_back(arr[j++]);

        // Zapisz scalony fragment do oryginalnej tablicy
        for (int k = 0; k < temp.size(); k++)
            arr[left + k] = temp[k];
    }
};

#endif
