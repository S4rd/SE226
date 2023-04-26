# Question 1
def common_elements(list1, list2):
    return list(set(list1) & set(list2))


list1 = [1, 2, 3, 4, 5]
list2 = [3, 4, 5, 6, 7]
common = common_elements(list1, list2)
print(common)


# Question 2
def get_palindromes(stringsList):
    palindromesList = []
    for string in stringsList:
        if string == string[::-1]:
            palindromesList.append(string)

    return palindromesList

stringsList = ['mouse', 'keyboard', 'radar', 'level', 'computer']
palindromes = get_palindromes(stringsList)
print(palindromes)


# Question 3
def sieveOfEratosthenes(nums):
    isPrime = [True] * (max(nums) + 1)
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(len(isPrime) ** 0.5) + 1):
        if isPrime[i]:
            for j in range(i * i, len(isPrime), i):
                isPrime[j] = False
    primes = []
    for num in nums:
        if isPrime[num]:
            primes.append(num)
    return primes


nums = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
primes = sieveOfEratosthenes(nums)
print(primes)


# Question 4
def anagrams(word, word_list):

    sorted_word = sorted(word.lower().replace(' ', ''))

    anagrams_list = []

    for w in word_list:
        sorted_w = sorted(w.lower().replace(' ', ''))
        if sorted_w == sorted_word and len(sorted_w) == len(sorted_word):
            anagrams_list.append(w)

    return anagrams_list

word = "listen"
word_list = ["inlets", "google", "enlists", "banana"]
anagram_list = anagrams(word, word_list)
# Erdem hocam enlists can't be anagram, i struggled at that part
# because they have different number of words.
print(anagram_list)

