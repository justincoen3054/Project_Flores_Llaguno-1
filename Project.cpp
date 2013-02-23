#include "Project.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

// -------------------------/UTILITY FUNCTIONS/-------------------------------
void factorial(vector<int> &, int);
void  carryNum(vector<int> &);
bool is_leap(unsigned int);
unsigned int sd(short, short, unsigned int);
unsigned int value = 11;//one thousand = 11
short small(short x);
void two(short third);
int C2I(char);
char I2C(int);
string X2(string);
const int MAX_SOLUTIONS = 1000;
typedef unsigned long long Long;
int getSolutions(Long n);
bool Project::isPalindrome(int num) {
    int n = num;
    int rev = 0;
    int digit = 0;
    while (num > 0)
    {
          digit = num % 10;
          rev = rev * 10 + digit;
          num = num / 10;
    }
    if (n == rev) {
        return true;
    }
    else {return false;}



}

// -------------------------/MAIN PROGRAM FUNCTIONS/-------------------------------


void Project::multiples_of_3_and_5()
{
    int i = 1;
    int total = 0;

    while (i < 1000) {
        if ((i%3) == 0 || i%5==0) {
            total = total +i;
        }
        i++;
    }
    cout << "The total is "<< total <<endl;
}

void Project::even_fibonacci()
{
    int fibo = 1;
    int i = fibo;
    int sum = 0;
    while (fibo < 4000000) {
        fibo = i + fibo;
        i = fibo - i;

        if ((fibo%2) == 0) {
            sum+=fibo;
        }
    }
    cout <<"The sum is " << sum <<endl;
}

void Project::largest_prime_factor()
{
    long int factor = 3;
    long long int num = 600851475143;
    int s = sqrt(num);
    long long int lFactor = 1;
    bool complete;

    for (; factor < s ; factor+=2) {
        for (int i = 3; i < s; i+=2) {
            if (factor == i) {
                if (num%factor == 0) {
                    lFactor = lFactor * factor;
                    if (lFactor == num){
                        complete = true;
                    }
                    break;
                }
                else break;
            }
            else if (factor%i == 0)
                break;
        }
        if (complete)
            break;
    }
    cout <<"The largest factor is "<< factor << endl;

}

void Project::largest_palindrome_product()
{
    int numOne = 100;
    int numTwo = 100;
    int pdrome = 0;
    int largPalindrome = 0;
    bool aPdrome;

    for (int j = 0; j < 900; j++) {
        for (int i = 0; i < 900; i++) {
            pdrome = (numOne+i) * (numTwo+j);
            aPdrome = isPalindrome(pdrome);
            if (aPdrome && (pdrome > largPalindrome)) {
                largPalindrome = pdrome;
            }
            pdrome = (numOne+j) * (numTwo+i);
            aPdrome = isPalindrome(pdrome);
            if (aPdrome && (pdrome > largPalindrome)) {
                largPalindrome = pdrome;
            }
        }
    }
    cout << "The largest palindrome is " <<largPalindrome <<endl;
}

void Project::smallest_multiple()
{
    long long int number = 2520;
    bool loop;

    while (!loop) {
        for (int a = 2; a < 21; a++) {
            if (number%a != 0) {
                break;
            }
            if (a == 20) {
                loop = true;
            }
        }
        if (!loop) {
            number+=20;                              //+20 increment because 20 is the maximum divisor; e.g. 30 is not divisible by 20.
        }
    }
    cout <<"The smallest number is "<< number <<endl;
}

void Project::sum_square_diff()
{
    int i = 1;
    int squared = 0;
    int sum = 0;
    int diff;
    for (;i<101; i++) {
        sum = sum + i;
        squared = squared + pow(i,2);
    }
    diff = pow(sum,2) - squared;
    cout << "The difference is "<< diff <<endl;
}

void Project::the_10001st_prime()
{
    int prime = 3;
    int count = 0;

    while (count < 9999) {                       //9999 because 2,3 and 5 are already given so 10001 - 3 = 9999.
        prime+=2;
        for (int i = 3; i < i+1; i+=2) {
            if (prime == i) {
                count++;
                break;
            }
            else if (prime%i == 0) {
                break;
            }
        }
    }
    cout << "The 10001st prime is "<< prime << endl;
}

void Project::largest_product_in_a_series()
{
    string serArray;
    int n = 0;
    int product = 1;
    int largProduct = 0;
    ifstream serFile;
    serFile.open("series2.txt");

    getline(serFile, serArray);

    serFile.close();

    while (serArray[n]) {
        for (int l = 0; l < 5; l++) {
            if ((serArray[n+l] == 0)) {
                n = n+l;
                break;
            }
            product = (serArray[n+l] - '0') * product;
        }
        if (product > largProduct) {
            largProduct = product;
        }
        product = 1;
        n++;
    }
    cout << "The largest product of the series is "<< largProduct <<endl;
}

void Project::special_pyth_triplet()
{
    int a = 0, b = 0, c = 0;
    int d = 1000;
    bool found = false;

    for (a = 1; a < d / 3; a++) {
        for (b = a; b < d / 2; b++) {
            c = d - a - b;

            if (a * a + b * b == c * c) {
                found = true;
                break;
            }
        }

        if (found) {
            break;
        }
    }
    cout << "The product of abc is "<< (a*b*c) <<endl;
}

void Project::summation_of_primes()
{
    long int prime = 3;
    long long int num = 2000000;
    int s = sqrt(num);
    long long int sum = 2;
    bool add;

    for (; prime < num ; prime+=2) {
        for (int i = 3; i < s; i+=2) {
            if (prime == i) {
                add = true;
                break;
            }
            else if (prime%i == 0) {
                add = false;
                break;
            }
            add = true;
        }
        if (add) {
            sum+=prime;
        }
    }
    cout << "The sum of primes under 2 million is "<< sum << endl;
}

void Project::largest_product_grid()
{
    int product = 1, backSlash = 0, forSlash = 0;
    long long int largProduct = 0;
    int matrix[20][20];
    ifstream myfile;
    myfile.open("grid20x20.txt");

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            myfile >> matrix[i][j];
        }
    }
    myfile.close();

    //horizontal
    for (int y = 0; y<20 ; y++){
        for (int left = 0; left<17 ; left++){
            for (int x = 0; x<4; x++){
                product*=matrix[y][left+x];
            }
            if (product > largProduct) {
                largProduct = product;
            }
            product = 1;
        }
    }
    product = 1;
    //vertical
    for (int i = 0; i<20 ; i++){
        for (int down = 0; down<17 ; down++){
            for (int j = 0; j<4; j++){
                product*=matrix[down+j][i];
            }
            if (product > largProduct) {
                largProduct = product;
            }
            product = 1;
        }
    }

    for (int row = 0; row<17 ; row++){
        for (int col = 0; col<17 ; col++){
            backSlash = (matrix[row][col]*matrix[row+1][col+1]*matrix[row+1][col+2]*matrix[row+1][col+3]);
            forSlash = (matrix[row+3][col]*matrix[row+2][col+1]*matrix[row+1][col+2]*matrix[row][col+3]);
            if (backSlash > largProduct)
                largProduct = backSlash;
            if (forSlash > largProduct)
                largProduct = forSlash;
            forSlash = 0;
            backSlash = 0;
        }
    }

    cout <<"The largest product is "<< largProduct <<endl;
}

void Project::divisible_triangular_number()
{
    int number = 0;
    int i = 1;
    int nod = 0;
    int s;

    while (nod < 500){
        nod = 0;
        s = sqrt(number);
        for(int a = 1; a<=s ; a++){
            if(number % a == 0){
                nod += 2;
            }
        }
        if (s * s == number) {
            nod--;
        }
        if (nod > 500)
            break;
        number += i;
        i++;
    }
    cout <<"The first value to have over 500 divisors is " <<number <<endl;
}

void Project::largest_sum()
{
    long long int number[100];
    string mynumbers[100];
    int a = 0;
    long long int total = 0;
    ifstream myfile;
    myfile.open("fiftydigits013.txt");

    while (a < 100){
        getline(myfile,mynumbers[a]);
        a++;
    }

    myfile.close();

    for (int i = 0; i<100; i++) {
        for (int j = 10; j>=0 ; j--){
            number[i] = (mynumbers[i][j]-'0')*(pow(10,10-j));
            total+= number[i];
        }
    }
    total*= pow(10,-3);
    cout <<"The first ten digits are " <<total <<endl;
}


void Project::longest_collatz_sequence()
{
    int number = 1000000;
    int maxTerms = 0;
    int maxNumber = 0;
    long long int sequence;
    int i;

    for (i = 2; i < number; i++) {
        sequence = i;
        int count = 0;
        while (sequence != 1) {

            count++;
            if ((sequence%2) == 0) {
                sequence = sequence / 2;
            }
            else {
                sequence = sequence * 3 + 1;
            }
        }

        if (count > maxTerms){
            maxTerms = count;
            maxNumber = i;
        }
    }
    cout << "The largest number with the longest Collatz sequence is "<<maxNumber <<endl;
}

void Project::diophantine_reciprocals_a()
{
int solutions = 0;
    Long n=2*3*5*7*11*13;
    Long x = 2*3*5*7*11*13;

    while(solutions <= MAX_SOLUTIONS)
    {
        solutions = getSolutions(n);
          n+=x;
    }

    cout<<"The least value of n for which the number of distinct solutions exceeds one-thousand is: "<<n - x<<endl;
}
int getSolutions(Long  n)
{
    Long maxX = 2*n;
    register int solutions=0;
    Long differ;
    long double y;
    Long x;
    for(x = n+1; x<=maxX; x++)
    {
        differ = x-n;
            y = (x*n)/(long double)differ;
                        if((Long)y == y)
            {
                solutions++;
            }
    }
    return solutions;
}

void Project::power_digit_sum()
{
string two = "2";

    for (int i = 0; i < 999; i++)
        two = X2(two);


    int sum = 0;

    for (int i = 0; i < (int)two.length(); i++)
        sum += (int)two[i] - 48;

    cout <<"The sum of the digits of the number 2^1000 is: "<< sum << endl;
   // return 0;
}

int C2I(char c)
{
    return int(c) - 48;
}
char I2C(int n)
{
    return char(n) + 48;
}
string X2(string number)
{
    string answer = "";
    int digit, result, carry = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        digit = C2I(number[i]);
        result = (digit * 2) + carry;

        if (result >= 10)
        {
            carry = result / 10;
            result = result % 10;
        }
        else
            carry = 0;
        answer = I2C(result) + answer;
    }
    if (carry != 0)
        answer = I2C(carry) + answer;
    return answer;
}

void Project::number_letter_counts()
{
for(short count = 0;count<10;count++)
    {
        two(count);
    }
   std::cout<<value<<" letters are used when all the nos. from 1-1000 are written in words"<<endl;
    std::cin.get();
    //return 0;
}

void two(short third)
{

    std::string temp;
    if(third>0)
    {
         third = (small(third) + 10);//10 = and(3) + hundred(7)
    }
    for(short i = 0;i<20;i++)//0-20
    {
        value += (small(i) + third);
    }
    for(short i = 20;i<60;i++)//20-40 + 80-100
    {
         std::stringstream ss;
         ss<<i;
         temp = ss.str();
         value += ((small(temp[1]-'0') + 6) + third);
    }
    for(short i = 40;i<70;i++)//40-70
    {
         std::stringstream ss;
         ss<<i;
         temp = ss.str();
         value += ((small(temp[1]-'0') + 5) + third);
    }
    for(short i = 70;i<80;i++)//70-80
    {
         std::stringstream ss;
         ss<<i;
         temp = ss.str();
         value += ((small(temp[1]-'0') + 7) + third);
    }
}

short small(short x)
{
              switch(x)
             {
                case 0:
                     return 0;
                case 1:
                     return 3;
                case 2:
                     return 3;
                case 3:
                     return 5;
                case 4:
                     return 4;
                case 5:
                     return 4;
                case 6:
                     return 3;
                case 7:
                     return 5;
                case 8:
                     return 5;
                case 9:
                     return 4;
                case 10:
                     return 3;
                case 11:
                     return 6;
                case 12:
                     return 6;
                case 13:
                     return 8;
                case 14:
                     return 8;
                case 15:
                     return 7;
                case 16:
                     return 7;
                case 17:
                     return 9;
                case 18:
                     return 8;
                case 19:
                     return 8;
          }
}


void Project::max_path_sum_one(){
      int tri [15][15] = {
    {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
    {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
    {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};
    cout <<"The maximum total from top to bottom of the triangleis: "<< checkPath(15, tri) << endl;
}
int Project::maxTotal (int num1, int num2, int up) {
    int biggest = num1;
    if(num2 > biggest)
        biggest = num2;
    return biggest + up;
}
int Project::checkPath(int num, int tri[][15]) {
    for(int i = num-1; i >= 0; i--) {
        for(int j = 0; j+1 < num && tri[i][j+1] != 0; j++)
            tri[i-1][j] = maxTotal(tri[i][j], tri[i][j+1], tri[i-1][j]);
    }
    return tri[0][0];
}




void Project::counting_sundays()
{
 cout << sd(31, 12, 2000)-sd(31, 12, 1900) <<" Sundays fell on the first of the month during the twentieth century"<< endl;
            //return 0;
    }

    bool is_leap(unsigned int y) {
            if(y%400 == 0) return true;
            else if(y%100==0) return false;
            else if(y%4==0) return true;
            else return false;
    }

    unsigned int sd(short d, short m, unsigned int y) {
            short _d=1, _m=1;
            unsigned int _y=1900, _n=1, _s=0;

            while(true) {
                    if(_n%7+1==1 && _d==1) ++_s;
                    if(_d==30 && (_m==4 || _m==6 || _m==9 || _m==11)) {
                            ++_m;
                            _d = 1;
                            ++_n;
                            continue;
                    } else if(_m==2) {
                            if(!is_leap(_y) && _d==28) {
                                    ++_m;
                                    _d = 1;
                                    ++_n;
                                    continue;
                            }
                            else if(is_leap(_y) && _d==29) {
                                    ++_m;
                                    _d = 1;
                                    ++_n;
                                    continue;
                            }
                    } else if(_d==31) {
                            if(_m!=12) {
                                    ++_m;
                            } else {
                                    _m=1;
                                    ++_y;
                                    if(_y>y) break;
                            }

                            _d = 1;
                            ++_n;
                            continue;
                    }

                    if(_d==d && _m==m && _y==y) break;
                    ++_d;
                    ++_n;
            }

            return _s;
    }

void Project::factorial_digit_sum(){
int sumDigits = 0;
    vector<int>     v1;
    int number =100;
    v1.push_back(number);

    for(int i = 2; i < number; i++)
    {
        factorial(v1, i);
    }

    for(int i = 0; i < v1.size(); i++)
    {
        sumDigits += v1[i];
    }
    cout<<"The sum of the digits of 100! is: " << sumDigits << endl;

}

void carryNum(vector<int> & vect)
{
    int carry = 0;
    for(int i = 0; i < vect.size(); i++)
    {
        if( 9 < vect[i] )                        //Need to carry
        {
           if( i+1 == vect.size() )            //Last element
           {
              vect.push_back(vect[i]/10);
              vect[i] = vect[i]%10;
           }
           else
           {
               carry   = vect[i]/10;
               vect[i] = vect[i]%10;
               vect[i+1] += carry;
           }
        }
    }
}

void factorial(vector<int> & vect, int num)
{
    for (int j = 0; j < vect.size(); j++)
    {
        vect[j] = vect[j] * num;              //Calculate the carry value
    }                                     //after the multiplication cycle
    carryNum(vect);                          //finishes.
}



