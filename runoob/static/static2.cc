#include <iostream>
using namespace std;

class Data
{
  public:
    Data(){}
    ~Data(){}
    void show() {
      cout << this->data << "\t" << number << endl;
    }
    static void showData() {
      cout << "\t" << number << endl;
    }
  private: 
    int data;
  public:
    static int number;
};

int Data::number = 0;

int main()
{
  Data::showData();
  Data::number = 100;
  Data d;
  d.show();
  d.showData();

  cout << "End" << endl;
  return 0;
}
