/* 
Lilah has a string,s, of lowercase English letters that she repeated infinitely many times.

Given an integer,n, find and print the number of letter a's in the first  letters of Lilah's infinite string.
For example, if the string s='abcac' and n=10, the substring we consider is "abcacabcac", the first 10 characters of her infinite string. 
There are 4 occurrences of a in the substring.

Function Description:
Complete the repeatedString function in the editor below. It should return an integer representing the number of occurrences of a in the prefix of length n in the infinitely repeating string.
repeatedString has the following parameter(s):

s: a string to repeat
n: the number of characters to consider

Input Format:
The first line contains a single string, .
The second line contains an integer, .

Output Format:
Print a single integer denoting the number of letter a's in the first n letters of the infinite string created by repeating  infinitely many times.

Sample Input 0:
aba
10

Sample Output 0:
7

Explanation 0:
The first  letters of the infinite string are abaabaabaa. Because there are  a's, we print  on a new line.

Sample Input 1:
a
1000000000000

Sample Output 1:
1000000000000

Explanation 1:
Because all of the first "n = 1000000000000"letters of the infinite string are a, we print  on a new line.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) 
{   long count=0;
    long len =s.length();
    long factor = n/len;
    for(long i=0;i<len;i++)
    {
        if(s[i]=='a')
        count++;
    }
    count = factor*count;
    int mod = n%len;
    for(long i=0;i<mod;i++)
    {
        if(s[i]=='a')
        count++;
    }
   return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
