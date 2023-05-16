from abc import ABC, abstractmethod

#question 1
class WordFrequencyAnalyzer(ABC):
    def __init__(self, address):
        self.address = address

    @abstractmethod
    def calculateFreqs(self):
        pass

#question 2-3
class ListCount(WordFrequencyAnalyzer):
    def calculateFreqs(self):
        freq_dict = {}
        with open(self.address, 'r') as file:
            for line in file:
                for char in line:
                    if char.isalpha():
                        char = char.lower()
                        if char in freq_dict:
                            freq_dict[char] += 1
                        else:
                            freq_dict[char] = 1
        for char, count in freq_dict.items():
            print(f"{char} = {count}")

#question 4
class DictCount(WordFrequencyAnalyzer):
    def calculateFreqs(self):
        freq_dict = {}
        with open(self.address, 'r') as file:
            for line in file:
                for char in line:
                    if char.isalpha():
                        char = char.lower()
                        freq_dict[char] = freq_dict.get(char, 0) + 1
        print(freq_dict)


#question 5
weirdWords = "weirdWords.txt"

list_count_obj = ListCount(weirdWords)
print("List Count:")
list_count_obj.calculateFreqs()

dict_count_obj = DictCount(weirdWords)
print("Updated Dict:")
dict_count_obj.calculateFreqs()