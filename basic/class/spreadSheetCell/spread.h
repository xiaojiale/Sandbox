#include <iostream>
#include <string>
using namespace std;

class SpreadSheetCell
{
  public:
    void setValue(double val);
    double getValue();
    void setString(string str);
    string getString();

  protected:
    string doubleToString(double val);
    double stringToDouble(string str);

  private:
    double m_value;
    string m_string;
};
