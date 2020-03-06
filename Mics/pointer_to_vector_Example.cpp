#include <iostream>
#include <vector>
using namespace std;

class a
{
public :
int t;
    a(){
        t = 10;
        cout<<"constructor"<<endl;
    }
	~a()
	{
		cout << "destroy";
	}
};
int main()
{
  vector <a*> *v1 = new vector<a*>(2);
  v1->at(0) = new a();
  delete v1->at(0);
  cout<<"pointer ends"<<endl;
  vector <a> *v2 = new vector<a>(10);
  vector<a> v3(3);
  return 0;
}
