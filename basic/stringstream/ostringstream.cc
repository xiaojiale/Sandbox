#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
  ostringstream ostr1;
  ostringstream ostr2("abcdef");

  ostr1 << "ostr1 " << 2018 << endl;
  cout << ostr1.str();

  long curPos = ostr2.tellp();
  cout << "curPos = " << curPos << endl;

  ostr2.seekp(2);
  ostr2.put('g');
  cout << ostr2.str() << endl;

  ostr2.clear();
  ostr2.str("");

  cout << ostr2.str() << endl;
  ostr2.str("_def");
  cout << ostr2.str() << endl;
  ostr2 << "gggghh";
  cout << ostr2.str() << endl;
  ostr2.str("");
  ostr2.str("_df");
  cout << ostr2.str() << endl;

  const char* buf = ostr2.str().c_str();
  cout << buf << endl;

  string ss = ostr2.str();
  const char *buffer = ss.c_str();
  cout << buffer << endl;
}
