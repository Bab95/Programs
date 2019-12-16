/* Problem Name is &&& Best Average Grade &&& PLEASE DO NOT REMOVE THIS LINE. */

/*
**  Instructions:
**
**  Given a list of student test scores, find the best average grade.
**  Each student may have more than one test score in the list.
**
**  Complete the bestAverageGrade function in the editor below.
**  It has one parameter, scores, which is an array of student test scores.
**  Each element in the array is a two-element array of the form [student name, test score]
**  e.g. [ "Bobby", "87" ].
**  Test scores may be positive or negative integers.
**
**  If you end up with an average grade that is not an integer, you should
**  use a floor function to return the largest integer less than or equal to the average.
**  Return 0 for an empty input.
**
**  Example:
**
**  Input:
**  [ [ "Bobby", "87" ],
**    [ "Charles", "100" ],
**    [ "Eric", "64" ],
**    [ "Charles", "22" ] ].
**
**  Expected output: 87
**  Explanation: The average scores are 87, 61, and 64 for Bobby, Charles, and Eric,
**  respectively. 87 is the highest.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
**  Find the best average grade.
*/
int convert2int(string s){
  int num = 0;
  for(int i=0;i<s.size();i++){
    int tmp = (int)s[i]-48;
    num = num*10+tmp;
  }
  return num;
}
int max(int a,int b){
  return a>b?a:b;
}
int bestAverageGrade(vector<vector<string>> scores)
{
  // TODO: implement this function
  map<string,vector<int> > m;
  for(int i=0;i<scores.size();i++){
    string name = scores[i][0];
    string score = scores[i][1];
    m[name].push_back(convert2int(score));
  }
  int ans = 0;
  for(map<string,vector<int> >::iterator itr=m.begin();itr!=m.end();itr++){
    int size = itr->second.size();
    int sum = 0;
    for(vector<int>::iterator i=itr->second.begin();i!=itr->second.end();i++){
      sum+=*i;
    }
    int avg = sum/size;
    ans = max(avg,ans);
  }
  return ans;

}

/*
**  Returns true if the tests pass. Otherwise, returns false;
*/
bool doTestsPass()
{
  // TODO: implement more test cases
  vector<vector<string>> tc1 = { { "Bobby", "87" },
                   { "Charles", "100" },
                   { "Eric", "64" },
                   { "Charles", "22" } };

vector<vector<string>> tc2={{"ABC","89"},
                              {"VBC","46"},
                               {"uyhx","98"},
                               {"ABC","94"},
                               {"VBC","90"},
                               {"PQRD","56"}};

   vector<vector<string>> tc3={};

  return bestAverageGrade(tc1) == 0;
}

/*
**  Execution entry point.
*/
int main()
{
  // Run the tests
  if(doTestsPass())
  {
    cout << "All tests pass" << endl;
  }
  else
  {
    cout << "Tests failed" << endl;
  }

  return 0;
}
