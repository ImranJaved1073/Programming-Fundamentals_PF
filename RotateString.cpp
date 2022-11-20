//ROTATE STRING
//Scturtle likes strings very much.He is getting bored today, because he has already completed this week's task 
//and doesn't have anything else to do.So he starts left - rotating a string.If the length of the string is, then 
//he will rotate it n times and note down the result of each rotation on a paper.
//
//For a string S=s1 s2...sn, n rotations are possible.Let's represent these rotations by r1,r2...rn. 
//Rotating it once will result in string r1=s2 s3...sns1, rotating it again will result in string 
//r2=s3s4...sn s1 s2 and so on. Formally, ith  rotation will be equal to ri=si+1 ... sn-1sns1...si. Note that rn=S.
//
//Your task is to display all n rotations of string S.
//
//For example, if S = abc then it has 3 rotations.They are r1= bca, r2= cab and r3= abc.
//
//Input Format
//The first line contains an integer, T , which represents the number of test cases to follow.Then follows T lines,
//which represent a test case each.
//Each test case contains a string, S , which consists of lower case latin characters  only.
//
//Output Format
//For each test case, print all the rotations,r1 r2 ... rn , separated by a space.
//
//Sample Input
//
//5
//abc
//abcde
//abab
//aaa
//z
//Sample Output
//
//bca cab abc
//bcdea cdeab deabc eabcd abcde
//baba abab baba abab
//aaa aaa aaa
//z


 #include <iostream>
 #include <string>
 
 using namespace std;

 string leftRotateString(string s, int n)
 {
	 string temp = s.substr(0, n);
	 s.erase(0, n);
	 s += temp;
	 return s;
 }

 int main()
 {
     int N;
	 cout << "How many strings do you want to enter? ";
     cin >> N;
     string* s = new string[N];
     for (int i = 0; i < N; i++)
     {
		 cout << "Enter string " << i + 1 << ": ";
         cin >> s[i];
	 }
	 for (int i = 0; i < N; i++)
	 {
		 for (int j = 0; j < s[i].length(); j++)
		 {
			 s[i] = leftRotateString(s[i], 1);
             cout << s[i] << " ";
		 }
         cout << endl;
	 }
	 delete[] s;
	 s = nullptr;
	 return 0;

 }
 
