#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <exception>

using namespace std;

template<typename T, size_t size>
int sumOfMultiples(const array<T, size>& multiples, int max);

template<typename T, size_t size>
int containsMultiple(const array<T, size>& multiples, int number);

int evenFibNums(int max);

unsigned long long largestPrimeFactor(unsigned long long max);

bool isPrime(unsigned long long number);

pair<int,int> largestPalidromeProduct(int n);

bool isPalindrome(vector<int> arr);

vector<int> intToVector(int number);

long smallestMultiple(vector<int> numbers);

long sumSquare(vector<int> numbers);

long squareSum(vector<int> numbers);

long sumSquareDifference(int min, int max);

unsigned long long getPrimeNumber(int number);

unsigned long long getNextPrime(unsigned long long number);

vector<int> readVectorIntFromFile(string filename);

unsigned long long largestProductInSeries(const vector<int>& series, int n);

unsigned long specialPythagoreanTriplet(int answer);

unsigned long long sumPrimesUnder(int max);

long largestProductInGrid(array<array<int,20>,20> matrix);

long findHighestAdjacentRow(const array<array<int, 20>, 20> & matrix, pair<int,int> source);

array<array<int, 20>, 20> readMatrix(string filename);

unsigned long long factorCountofTriangle(int divisors);

int divisorCounter(unsigned long long number);

vector<string> readVectorStrFromFile(string filename);

string addLargeSums(vector<string> sums);

/*
All problems taken from Project Euler (www.projecteuler.net/archives)
*/

int main(){

	/*
	Problem 1. Sum of Mutliples (sumOfMultiples) (containsMultiple)
	Return int which is the sum of all multiples below max number
	*/
	//array <int, 2> arr = { 3, 5 };
	//cout << sumOfMultiples(arr, 1000) << endl;

	/*
	Problem 2. Even Fibonacci Numbers (evenFibNums)
	Return int which is sum of all even numbers below max that are fibonacci numbers
	*/
	//cout << evenFibNums(4000000) << endl;

	/*
	Problem 3. Largest Prime Factor (largestPrimeFactor) (isPrime)
	Return unsigned long of largest prime factor
	*/
	//cout << largestPrimeFactor(600851475143) << endl;

	/*
	Problem 4. Largest palindrome product (largestPalidromeProduct) (isPalindrome) (intToArray)
	Return array<int,2> with two n digit numbers which sum a palidrome
	*/
	//pair<int, int> answer = largestPalidromeProduct(3);
	//cout << answer.first * answer.second << endl;

	/*
	Problem 5. Smallest Multiple (smallestMultiple)
	Return long that is smallest multiple of all numbers enetered
	*/
	//cout << smallestMultiple({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	//							11, 12, 13, 14, 15, 16, 17, 18, 19, 20}) << endl;

	/*
	Problem 6. Sum Square Difference (sumSquare) (squareSum) (sumSquareDifference)
	Return long of difference between sumSquare and squareSum
	*/
	//cout << sumSquareDifference(1, 100);

	/*
	Problem 7. 10001st prime (getPrimeNumber) (isPrime) (getNextPrime)
	Return long to the [number]st prime number
	*/
	//cout << getPrimeNumber(10001);

	/*
	Problem 8. Largest product in a series (readVectorIntFromFile) (largestProductInSeries)
	Read numbers into vector and find largest series of n length
	*/
	//vector<int> series = readVectorIntFromFile("problem8.txt");
	//cout << largestProductInSeries(series, 13);

	/*
	Problem 9. Special Pythagorean triplet (specialPythagoreanTriplet)
	*/
	//cout << specialPythagoreanTriplet(1000) << endl;

	/*
	Problem 10. Summation of primes (sumPrimesUnder)
	*/
	//cout << sumPrimesUnder(2000000);

	/*
	Problem 11. Largest product in a grid (largestProductInGrid) (findHighestAdjacent) (readMatrix)
	*/
	//auto matrix = readMatrix("problem11.txt");
	//cout << largestProductInGrid(matrix) << endl;

	/*
	Problem 12. Highly divisble triangular number (factorCountofTriangle) (factorial) (divisorCounter)
	*/
	//cout << factorCountofTriangle(500);

	/*
	Problem 13. Large sum (readVectorStrFromFile) (addLargeSums)
	*/

	return 0;
}

template<typename T,size_t size>
int sumOfMultiples(const array<T,size>& multiples, int max)
{
	int sum = 0;

	for (int i = 1; i < max; ++i)
	{
		sum += containsMultiple(multiples, i);
	}

	return sum;
}

template<typename T, size_t size>
int containsMultiple(const array<T, size>& multiples, int number)
{
	for (auto& x : multiples)
		if (number % x == 0)
			return number;

	return 0;
}

int evenFibNums(int max)
{
	int sum = 2;

	array<int, 3> fib = { 1, 2, 3 };

	while (fib[2] < max)
	{
		fib[0] = fib[1];
		fib[1] = fib[2];
		fib[2] = fib[0] + fib[1];

		if (fib[2] % 2 == 0)
			sum += fib[2];
	}

	return sum;
}

unsigned long long largestPrimeFactor(unsigned long long max)
{
	for (unsigned long long i = 3; i < max; i++)
	{
		if ((max % i == 0) && isPrime(i))
			cout << i << ' ';
	}

	return 1;
}

bool isPrime(unsigned long long number)
{
	if (number == 0 || (number % 2 == 0))
		return false;
	for (long i = 3; i < number/2; i+=2)
		if (number % i == 0)
			return false;

	return true;
}

pair<int,int> largestPalidromeProduct(int n)
{
	string maxStr = "";
	for (int i = 0; i < n; ++i)
		maxStr += '9';
	int num1 = stoi(maxStr), num2 = num1;
	int min = floor(num1 / 10), max = num1;
	pair<int, int> toReturn(num1, num2);

	while (num1 > min)
	{
		while (num2 > min)
		{
			if (isPalindrome(intToVector(num1*num2)))
				if (num1*num2 > max)
				{
					max = num1*num2;
					toReturn.first = num1;
					toReturn.second = num2;
				}
			num2--;
		}
		num2 = --num1;
	}

	return toReturn;
}

bool isPalindrome(vector<int> arr)
{
	int size = arr.size();

	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != arr[size - i - 1])
			return false;
	}

	return true;
}

vector<int> intToVector(int number)
{
	double count = 1;
	unsigned long long check;
	vector<int> toReturn;
	do
	{
		check = pow(10.0, count++);
	} while (number % check != number);

	--count;
	for (double i = 0; i < count; ++i)
	{
		toReturn.push_back(floor(number % 10));
		number /= 10;
	}

	return toReturn;
}

long smallestMultiple(vector<int> numbers)
{
	if (numbers.size() < 3)
		return 0;

	long toReturn = 0;
	long i = numbers.size();
	if (i % 2 == 1)
		++i;

	for (i; toReturn == 0; i += 2)
	{
		for (int k = 0; k < numbers.size(); ++k)
		{
			if (i % numbers[k] != 0)
				break;
			else if (k == numbers.size() - 1)
				toReturn = i;
		}
	}

	return toReturn;
}

long squareSum(vector<int> numbers)
{
	long toReturn = 0;

	for (int i = 0; i < numbers.size(); ++i)
	{
		toReturn += numbers[i];
	}

	return pow(toReturn,2);
}

long sumSquare(vector<int> numbers)
{
	long toReturn = 0;

	for (int i = 0; i < numbers.size(); ++i)
	{
		toReturn += pow(numbers[i], 2);
	}

	return toReturn;
}

long sumSquareDifference(int min, int max)
{
	vector<int> numbers;

	for (int i = min; i <= max; ++i)
	{
		numbers.push_back(i);
	}

	return abs(sumSquare(numbers) - squareSum(numbers));
}

unsigned long long getPrimeNumber(int number)
{
	if (number < 4)
		return number;

	unsigned long long lastPrime = 3;

	for (int i = 3; i <= number; ++i)
		lastPrime = getNextPrime(lastPrime);

	return lastPrime;
}

//Takes a prime number and finds the next one
unsigned long long getNextPrime(unsigned long long number)
{
	if (!isPrime(number))
		return 0;

	while (true)
	{
		number += 2;
		if (isPrime(number))
			break;
	}

	return number;
}

unsigned long long getNextPrimeWPrime(unsigned long long number)
{
	
	while (true)
	{
		number += 2;
		if (isPrime(number))
			break;
	}

	return number;
}

vector<int> readVectorIntFromFile(string filename)
{
	ifstream file;
	char next;
	vector<int> series;
	try {
		file.open(filename, fstream::in);

		if (file.is_open())
		{
			// Add chars to vector, minus 48 to offset ACSII
			while (file.get(next))
			{
				if (next - 48 >= 0)
					series.push_back(next - 48);
			}
		}
		else
			throw "Could not find " + filename;

		file.close();
	}
	catch (exception e) {
		cout << "Error opening file: " << e.what() << endl;
		file.close();
	}

	return series;
}

unsigned long long largestProductInSeries(const vector<int>& series, int n)
{
	unsigned long long currProduct = 1;

	for (int i = 0; i < n; i++)
	{
		currProduct *= series[i];
	}
	unsigned long long max = currProduct;

	for (int i = 1; i < series.size() - n; i++)
	{
		currProduct = 1;

		for (int j = 0; j < n; j++)
		{
			currProduct *= series[i + j];
		}

		if (currProduct > max)
			max = currProduct;
	}

	return max;
}

unsigned long specialPythagoreanTriplet(int answer)
{
	array<int, 3> abc;
	bool notDone = true;

	for (int i = 1, x = 2; i <= answer-3 && notDone; i++, x++)
	{
		for (int j = x; j <= answer-3; j++)
		{
			int k = answer - i - j;
			if (pow(i, 2) + pow(j, 2) == pow(k, 2))
			{
				abc[0] = i;
				abc[1] = j;
				abc[2] = k;
				notDone = false;
				break;
			}
		}
	}
	
	return abc[0] * abc[1] * abc[2];
}

unsigned long long sumPrimesUnder(int max)
{
	if (max == 2)
		return 2;
	else if (max < 3)
		return 0;

	int currPrime = 3;
	unsigned long long sum = 5;

	while (currPrime <= max)
	{
		currPrime = getNextPrimeWPrime(currPrime);
		sum += currPrime;
	}

	return sum - currPrime;
}

long largestProductInGrid(array<array<int, 20>, 20> matrix)
{
	long max = 0;
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			long temp = findHighestAdjacentRow(matrix, pair<int, int>(i, j));
			if (temp > max)
				max = temp;
		}
	}

	return max;
}

long findHighestAdjacentRow(const array<array<int, 20>, 20> & matrix, pair<int, int> source)
{
	long max = 0;
	long current;

	pair<int, int> temp;
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			current = matrix[source.first][source.second];
			temp = source;

			for (int i = 0; i < 3; i++)
			{
				if (x == 0 && y == 0)
					y++;
				temp.first += x;
				temp.second += y;

				if (temp.first < 0 || temp.second < 0 || temp.first >= 20 || temp.second >= 20)
				{
					break;
				}
				else
					current *= matrix[temp.second][temp.first]; 

				if (i == 2)
					if (current > max)
						max = current;
			}
		}
	}

	return max;
}

array<array<int, 20>, 20> readMatrix(string filename)
{
	ifstream file;
	int next;
	array<array<int, 20>, 20> series;
	pair<int, int> loc = { 0, 0 };
	try {
		file.open(filename, fstream::in);

		if (file.is_open())
		{
			while (file >> next)
			{
				series[loc.first][loc.second++] = next;

				if (loc.second > 19)
				{
					loc.first++;
					loc.second = 0;
				}
			}
		}
		else
			throw "Could not find " + filename;

		file.close();
	}
	catch (exception e) {
		cout << "Error opening file: " << e.what() << endl;
		file.close();
	}

	return series;
}

unsigned long long factorCountofTriangle(int divisors)
{
	int currentTriangle = 1;
	unsigned long long lastSum = 1;

	while (true)
	{
		unsigned long long sum = ++currentTriangle + lastSum;
		lastSum = sum;
		int count = divisorCounter(sum);
		cout << count << ",";
		if (count > 500)
			return sum;
	}
}

int divisorCounter(unsigned long long number)
{
	int count = 2;

	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			count += 2;
	}

	return count;
}

vector<string> readVectorStrFromFile(string filename)
{

}

string addLargeSums(vector<string> sums)
{

}