/* length of longest palindrome within a given string input */

#include <iostream>
#include <string>
using namespace std;

// we can use a suffix tree - O(nlogn) or Manacher algorithm - O(n) for better time complexity 
// but neither of them is more space efficient than this method - O(n2) time and O(1) space 

int longestPalindrome(string s, int center_this){
  int left_this = center_this-1;
  int right_this = center_this+1;
  while(s[left_this]==s[right_this]){//palindrome
    left_this--;right_this++;
  }
  return right_this-left_this-1;
}

int main() {
  string input = "abaaba";
  int result=0;
  if(input.size() == 2)
    (input[0]==input[1]) ? cout << 2 : cout << 0;
  if(input.size()>2){
    int i = input.size()/2; //middle
    int left = (input.size()%2!=0)?i:i-1; //even or odd
    int right = i;
    while(i>0){ //start at middle and check palindromes on both sides
      int l_result = longestPalindrome(input, left); 
      result = (result>l_result)?result:l_result;
      int r_result = longestPalindrome(input, right); 
      result = (result>r_result)?result:r_result; 
      left--; right++; i--;
    }
    cout << "longest palindrome is of size: " << result << endl;
  }
  return 0;
}
