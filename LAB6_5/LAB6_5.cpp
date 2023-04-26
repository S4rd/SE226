#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Question 1
int* common_elements(int* arr1, int n1, int* arr2, int n2, int& n3) {
    int* res = new int[n1];
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                res[k++] = arr1[i];
                break;
            }
        }
    }
    n3 = k;
    return res;
}
// Question 2
bool is_palindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

string* get_palindromes(string* stringsList, int len, int& palindrome_len) {
    string* palindrome_arr = new string[len];
    palindrome_len = 0;
    for (int i = 0; i < len; i++) {
        if (is_palindrome(stringsList[i])) {
            palindrome_arr[palindrome_len++] = stringsList[i];
        }
    }
    return palindrome_arr;
}

// Question 3
bool* sieveOfEratosthenes(int* nums, int len) {
    int max_num = *max_element(nums, nums + len);
    bool* isPrime = new bool[max_num + 1];
    fill_n(isPrime, max_num + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= sqrt(max_num); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int* get_primes(int* nums, int len, int& prime_len) {
    bool* isPrime = sieveOfEratosthenes(nums, len);
    int* prime_arr = new int[len];
    prime_len = 0;
    for (int i = 0; i < len; i++) {
        if (isPrime[nums[i]]) {
            prime_arr[prime_len++] = nums[i];
        }
    }
    delete[] isPrime;
    return prime_arr;
}

// Question 4
string* anagrams(string word, string* word_list, int len, int& anagram_len) {
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    string* anagram_arr = new string[len];
    anagram_len = 0;
    for (int i = 0; i < len; i++) {
        string sorted_w = word_list[i];
        sort(sorted_w.begin(), sorted_w.end());
        if (sorted_w == sorted_word && sorted_w.length() == sorted_word.length() && sorted_w != word_list[i]) {
            anagram_arr[anagram_len++] = word_list[i];
        }
    }
    return anagram_arr;
}


    int main() {
        // Test intersection function
        int arr1[] = {1, 2, 3, 4, 5};
        int n1 = 5;
        int arr2[] = {3, 4, 5, 6, 7};
        int n2 = 5;
        int n3;
        int *res = common_elements(arr1, n1, arr2, n2, n3);
        cout << "Intersection: ";
        for (int i = 0; i < n3; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        delete[] res;

        // Test palindromes function
        string arr[] = {"mouse", "keyboard", "radar", "level", "computer"};
        int n = 5;
        int ni;
        string *res2 = get_palindromes(arr, n, ni);
        cout << "Palindromes: ";
        for (int i = 0; i < ni; i++) {
            cout << res2[i] << " ";
        }
        cout << endl;
        delete[] res2;

        // Test primes function
        int arr3[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
        int nl = 9;
        int n4;
        int *res3 = get_primes(arr3, nl, n4);
        cout << "Primes: ";
        for (int i = 0; i < n4; i++) {
            cout << res3[i] << " ";
        }
        cout << endl;
        delete[] res3;

        // Test anagrams function

            string word = "listen";
            string word_list[] = {"enlists", "google", "inlets", "banana"};
            int len = 4;
            int anagram_len;
            string* anagram_arr = anagrams(word, word_list, len, anagram_len);

            cout << "Anagrams of " << word << ": ";
            for (int i = 0; i < anagram_len; i++) {
                cout << anagram_arr[i] << endl;
            }

            delete[] anagram_arr;
            return 0;


        return 0;


    }
