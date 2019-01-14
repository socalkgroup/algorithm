
class Main {

static final String[] hashTable = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};

  public static void main (String[] args) {
    int number[] = {2, 3, 4};
    int n = number.length;

   char result[] = new char[n];
   printWordsUtil(number, 0, result, n);
  }

 // A recursive function to print all possible words that can be obtained
 // by input number[] of size n. The output words are one by one stored
 // in output[]
 static void printWordsUtil(int number[], int curr_digit, char output[], int n)
 {
   // Base case, if current output word is prepared
   int i=0;
   if (curr_digit == n)
   {
    
     System.out.print(output);
     System.out.print(" ");
     return;
   }

   // Try all possible characters for current digit in number[]
   // and recur for remaining digits
     while(curr_digit<n) {
       while(i<hashTable[number[curr_digit]].length())
       {
         if (number[curr_digit] == 0 || number[curr_digit] == 1) {
             curr_digit++;
             continue;
         }
         output[curr_digit] = hashTable[number[curr_digit]].charAt(i);
         printWordsUtil(number, curr_digit+1, output, n);
         i++;
       }
       curr_digit++;
     }
   }
}

