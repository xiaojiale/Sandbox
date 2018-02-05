#include <iostream>
using namespace std;

class Box
{
  public:
    static int objCount;    // declare the static variable

    Box(double len, double wid, double hei)
      : m_length(len),
        m_width(wid),
        m_height(hei)
    {
      cout << "Constructor called." << endl;
      objCount++;
    }

    double volume()
    {
      return m_length * m_width * m_height;
    }

  private:
    double m_length;
    double m_width;
    double m_height;
};

/*
 * initialize the static variable.
 */
int Box::objCount = 0;

int main(void)
{
  Box box1(1, 2, 3);
//  Box box2(2, 3, 4);

  cout << "Total objects: " << Box::objCount << endl;
  return 0;
}
