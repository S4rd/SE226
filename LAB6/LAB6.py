# Question 1
n = int(input("Enter the value of n: "))
x = int(input("Enter the value of x: "))

factorial = lambda n: 1 if n == 0 else n * factorial(n - 1)

terms = [(lambda i: (n ** i) / factorial(i))(i) for i in range(x + 1)]

result = sum(terms)

print(f"e^{n} = {result}")


# Question 2
summation = 0
number = int(input("Enter your number: "))
def recursive_sum(k):
    """Calculating of summation of series using recursive function
    without returning the result"""

    global summation


    if k == 0:
       summation = 0

    else:
     term = (-1) ** (k + 1) / k
     summation += term
     recursive_sum(k - 1)

recursive_sum(number)
print("Summation: ", summation)
