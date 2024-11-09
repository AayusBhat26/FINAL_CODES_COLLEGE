#include<iostream>
using namespace std; 
// subsequence 

// abc => a, b, c, ab, bc, ac, abc, "" 
// subsequence => two or characters maintaining the sequence as in main string, whether they consecutive or not. 
// here, common subsequences are ab, ac and abc
// powerset or recursion.

// number of subsequences = 2^n
// s1 = "adebc" => a d e b c ad ae .... 
// s2 = "dcadb" => d c a d b dc da dd db ... 

// f(index1, index2) => substring till index 1 and substring till index 2
// do comparisons character wise
// 1 + f(index1 - 1, index2 - 1)  if they match.
// string1 = "ec" and string2 ="ce" 
// index1 = 1 and index2 = 1
// idhar ye match nhi krenge toh hume dono side jana padega
// 0 + max(f(index1 - 1, index2), f(index1, index2-1))
// match => s1[index1] == s2[index2] => return 1 + f(index1 -1, index2-1)
// note -> negative means end of string.
// if(index1 < 0 || index2 < 0) return 0;
// acd ||  ced  index1 = 2 and index2 = 2 
// d matches => index1 = index - 1 && index2 = index2 - 1;
// ac || ce => index1 = 1 and index2 = 1
// c and e do not matches, therefore we will have two different function call 

// f(index1-1, index2) and f(index1, index2) and we will take the maximum of these.
// bruteforce => saari subsequencies generate kro and ek ek krke compare kro
// recursion => 2^m * 2^n, where m and n are legnth of strings, 
// memoization => 2d dp array to store the cases
// dp[n][m]  initialize everything to -1 
#define MAX 10
int dpArray[MAX][MAX];
int getMax(int n1, int n2){
    return n1 > n2 ? n1: n2;
}
void reverse(string &str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        // starting and ending characters ko reverse kro 
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int helperfunction(int i, int j, string &first, string &second){
    if(i < 0 || j < 0)return 0;
    // agar phele visit nhi kri hai
    if(dpArray[i][j] != -1) return dpArray[i][j];
    if (first[i] == second[j]) {
        return dpArray[i][j] = 1 + helperfunction(i - 1, j - 1, first, second);
    }
    // do not matches
    return dpArray[i][j] = getMax(helperfunction(i - 1, j, first, second), helperfunction(i, j - 1, first, second));
}

int longestSubSeq(string first, string second, string& subsequence){
    int n = first.size();
    int m = second.size();
    // initializing the dp array with -1
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            dpArray[i][j] = -1;
        }
    }

    int subSeqLength = helperfunction(n - 1, m - 1, first, second);

    // back tracking the subsequence and check which characters are present
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (first[i] == second[j]) {
            // match mil gya toh hum decrease krenge
            subsequence.push_back(first[i]);
            i--;
            j--;
        } else if (i > 0 && dpArray[i - 1][j] >= dpArray[i][j - 1]) {
            // dpArray[i-1][j] => first string ka current character ko exclude
            // dpArray[i][j-1] => second string ka current character ko exclude
            i--;
        } else {
            j--;
        }
    }

    // humne subsequence ko backtrack krke bnaya hai toh vo reverse hogi original se toh hume reverse krna pdega
    reverse(subsequence);
    return subSeqLength;
}

int main(){
    string first, second, subsequence; 
    cout << "Enter the first string: ";
    cin >> first;
    cout << "\nEnter the second string: ";
    cin >> second;
    int lengthOfLCS = longestSubSeq(first, second, subsequence);
    cout << "Length of longest common subsequence: " << lengthOfLCS << endl;
    cout << "Longest common subsequence: " << subsequence << endl;
    return 0;
}
