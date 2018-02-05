#include <iostream>

class Box
{
  public:
    Box(){}
//    Box(double wid);
  protected:
    double width;
};

//Box::Box(double wid) :
//  width(wid)
//{
//  std::cout << "width = " << width << std::endl;
//}


class SmallBox : public Box
{
  public:
    SmallBox(double);
    void setSmallBoxWidth(double val);
    double getSmallWidth(void);
};

SmallBox::SmallBox(double val)
{
  std::cout << val << std::endl;
}

void SmallBox::setSmallBoxWidth(double val)
{
  width = val;
}

double SmallBox::getSmallWidth(void)
{
  return width;
}

int main(int argc, char* argv[])
{
//  Box(3.4);
  SmallBox smallBox = SmallBox(3.0);
  SmallBox(3.0).setSmallBoxWidth(4.5);
  smallBox.setSmallBoxWidth(3.5);
  std::cout << smallBox.getSmallWidth() << std::endl;
  return 0;
}
