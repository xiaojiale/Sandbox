#include "spread.h"
#include <sstream>

void SpreadSheetCell::setValue(double val)
{
  m_value = val;
  m_string = doubleToString(val);
}
double  SpreadSheetCell::getValue()
{
  return m_value;
}

void SpreadSheetCell::setString(string str)
{
  m_string = str;
  m_value = stringToDouble(str);
}
string SpreadSheetCell::getString()
{
  return m_string;
}

string SpreadSheetCell::doubleToString(double val)
{
  ostringstream ostr;
  ostr << val;
  return ostr.str();
}

double SpreadSheetCell::stringToDouble(string str)
{
  double temp;
  istringstream istr(str);

  istr >> temp;
  if(istr.fail() || !istr.eof()) {
    return (0);
  }

  return temp;
}
int main()
{
  return 0;
}
