/*
CODE : POLYNOMIAL CLASS
level: moderate
  
Problem statement
Implement a polynomial class, with the following properties and functions.

Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices 
as degree and A[i] as coefficient of ith degree.

2. An integer holding total size of array A.

Functions : 1. Default constructor 2. Copy constructor 3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater
than the current capacity of polynomial, increase the capacity accordingly and add then set 
the required coefficient. If the degree is within limits, then previous coefficient value is
replaced by given coefficient value

4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.

5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result

6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result

7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.

8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing 
order of degree.

Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print 
new line. For more clarity, refer sample test cases


-------------------------------------------------------------------------------------------------
Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
-------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------
Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2
Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5
Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3
Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8
-------------------------------------------------------------------------------------------------
*/



#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
public:
    int *degCoeff;
    int capacity;

    // Default Constructor
    Polynomial() {
        capacity = 5;
        degCoeff = new int[capacity]();
    }

    // Copy Constructor
    Polynomial(const Polynomial &P) {
        capacity = P.capacity;
        degCoeff = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            degCoeff[i] = P.degCoeff[i];
        }
    }

    // Set Coefficient
    void setCoefficient(int degree, int coeff) {
        while (degree >= capacity) {
            int *newDegCoeff = new int[2 * capacity]();
            for (int i = 0; i < capacity; i++) {
                newDegCoeff[i] = degCoeff[i];
            }
            delete[] degCoeff;
            degCoeff = newDegCoeff;
            capacity *= 2;
        }
        degCoeff[degree] = coeff;
    }

    // Overload "+" operator
    Polynomial operator+(const Polynomial &P) {
        Polynomial result;
        int maxCapacity = max(this->capacity, P.capacity);
        result.setCapacity(maxCapacity);
        for (int i = 0; i < maxCapacity; i++) {
            int coeff1 = (i < this->capacity) ? this->degCoeff[i] : 0;
            int coeff2 = (i < P.capacity) ? P.degCoeff[i] : 0;
            result.degCoeff[i] = coeff1 + coeff2;
        }
        return result;
    }

    // Overload "-" operator
    Polynomial operator-(const Polynomial &P) {
        Polynomial result;
        int maxCapacity = max(this->capacity, P.capacity);
        result.setCapacity(maxCapacity);
        for (int i = 0; i < maxCapacity; i++) {
            int coeff1 = (i < this->capacity) ? this->degCoeff[i] : 0;
            int coeff2 = (i < P.capacity) ? P.degCoeff[i] : 0;
            result.degCoeff[i] = coeff1 - coeff2;
        }
        return result;
    }

    // Overload "*" operator
    Polynomial operator*(const Polynomial &P) {
        Polynomial result;
        result.setCapacity(this->capacity + P.capacity);
        for (int i = 0; i < this->capacity; i++) {
            for (int j = 0; j < P.capacity; j++) {
                result.degCoeff[i + j] += this->degCoeff[i] * P.degCoeff[j];
            }
        }
        return result;
    }

    // Copy assignment operator
    void operator=(const Polynomial &P) {
        delete[] degCoeff;
        capacity = P.capacity;
        degCoeff = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            degCoeff[i] = P.degCoeff[i];
        }
    }

    // Print polynomial
    void print() const {
        for (int i = 0; i < capacity; i++) {
            if (degCoeff[i] != 0) {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }

private:
    void setCapacity(int newCapacity) {
        int *newDegCoeff = new int[newCapacity]();
        for (int i = 0; i < min(capacity, newCapacity); i++) {
            newDegCoeff[i] = degCoeff[i];
        }
        delete[] degCoeff;
        degCoeff = newDegCoeff;
        capacity = newCapacity;
    }
};


//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}



