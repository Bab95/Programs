#include <iostream>

using namespace std;
template<class T> class my_vector{
	private:
		int vcapacity;
		int vsize;
		T *varray;
	public:
		T &operator [](unsigned int i){
			//assert((i>=0)&&i<vsize);
			return varray[i];
		}
		void reserve(int n,bool copy){
			T *newarray;
			newarray = new T[n];
			int i;
			/*if(newarray==NULL){
				throw memoryAllocationError("my_vector reserve():memory allocation failure");
			}*/
			if(copy){
				for(int i=0;i<vsize;i++){
					newarray[i] = varray[i];
				}
			}
			if(varray!=NULL){
				delete[] varray;
			}
			varray = newarray;
			vcapacity = n;
		}
		void push_back(const T &item){
			if(vsize==vcapacity){
				if(vcapacity==0){
					reserve(1, false);
				}else{
					reserve(2*vcapacity, true);
				}
			}
			varray[vsize] = item;
			vsize++;
		}
		unsigned int size(){
			return vsize;
		}
};

int main(int argc, char *argv[]) {
	my_vector<int> my_int_vector;
	my_int_vector.push_back(1);
	my_int_vector.push_back(2);
	for(int i=0;i<my_int_vector.size();i++){
		cout<<my_int_vector[i]<<endl;
	}
	cout<<my_int_vector.size()<<endl;
}
