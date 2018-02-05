#include <iostream>
using namespace std;

class Point
{
  public:
    void setPoint(int x, int y)
    {
      xPos = x;
      yPos = y;
    }

    void printPoint()
    {
      cout << "x = " << xPos << endl;
      cout << "y = " << yPos << endl;
    }

  private:
    int xPos;
    int yPos;
};

int main()
{
  Point obj;
  obj.setPoint(10, 20);
  obj.printPoint();

  return 0;
}
