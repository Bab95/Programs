#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct num{
    string val="";
    num operator +(const num& num1){
        num sum;
        int i=0,j=0,carry=0;
        while(i<num1.val.length()||j<val.length()){
            int a=0,b=0;
            if(i<num1.val.length()){
                a = num1.val[i]-'0';
            }
            if(j<val.length()){
                b = val[j]-'0';
            }
            int tmp = a + b + carry;
            carry = tmp/10;
            tmp = tmp%10;
            sum.val.push_back((char)(tmp+'0'));
            i++;
            j++;
        }
        if(carry!=0){
            sum.val.push_back((char(carry+'0')));
        }
        return sum;
    }

    num operator *(const num& num2){
        num product;
        for(int i=0;i<num2.val.length();++i){
            int current = num2.val[i]-'0';
            num current_product;
            for(int j=0;j<i;j++){
                current_product.val.push_back('0');
            }
            int carry = 0;
            for(int j=0;j<val.length();++j){
                int prod = current*(val[j]-'0')+carry;
                carry = prod/10;
                prod = prod%10;
                current_product.val.push_back((char)(prod+'0'));
            }
            if(carry!=0){
                current_product.val.push_back((char)(carry+'0'));
            }
            product = product + current_product;
        }
        return product;
    }
    void operator*(const int n){
        int carry = 0;
        for(int i=0;i<val.length();++i){
            int prod = n*(val[i]-'0') + carry;
            carry = prod/10;
            prod = prod%10;
            val[i] = prod + '0';
        }
        if(carry!=0){
            val.push_back((char)(carry+'0'));
        }
    }
};
num power_exponent(int n1,int N){
    num result;
    result.val = "1";
    string s = to_string(n1);
    reverse(s.begin(),s.end());
    num a;
    a.val = s;
    while(N>0){
        if(N%2==1){
            result = result * a;
        }
        a = a * a;
        N = N>>1;
    }
    return result;
}
void solve(){
    int n;
    cin>>n;
    num p;
    p.val = "2";
    for(int i=1;i<n;++i){
        p*2;
        //cout<<p.val<<endl;
    }
    //num p = power_exponent(2,n);
    //reverse(p.val.begin(),p.val.end());
    //cout<<"Power_value is: "<<p.val<<endl;
    int ans = 0;
    for(int i=0;i<p.val.length();++i){
        int a = p.val[i]-'0';
        ans += a;
    }
    cout<<ans<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;
void product(vector<uint8_t>& num,int n){
    int carry = 0;
    for(int i=0;i<num.size();++i){
        num[i] = num[i]*n+carry;
        carry = num[i]/10;
        num[i] = num[i]%10;
    }
    if(carry!=0){
        num.push_back(carry);
    }
}
void solve(){
    int n;
    cin>>n;
    if(n<64){
        ulli ans = (ulli)pow(2,n);
        //cout<<ans<<endl;
    }
    vector<uint8_t> num;
    num.reserve(10001);
    num.push_back((uint8_t)2);
    for(int i=1;i<n;++i){
        product(num,2);
    }
    int ans = num[0];
    for(int i=1;i<num.size();++i){
        ans += num[i];
    }
    cout<<ans<<endl;
}
int main() {
    Enter your code here. Read input from STDIN. Print output to STDOUT
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
*/

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ulli;
const ulli _base_power = (ulli)pow(2,63);
struct num{
	string val="";
	num operator +(const num& num1){
		num sum;
		int i=0,j=0,carry=0;
		while(i<num1.val.length()||j<val.length()){
			int a=0,b=0;
			if(i<num1.val.length()){
				a = num1.val[i]-'0';
			}
			if(j<val.length()){
				b = val[j]-'0';
			}
			int tmp = a + b + carry;
			carry = tmp/10;
			tmp = tmp%10;
			sum.val.push_back((char)(tmp+'0'));
			i++;
			j++;
		}
		if(carry!=0){
			sum.val.push_back((char(carry+'0')));
		}
		return sum;
	}

	num operator *(const num& num2){
		num product;
		for(int i=0;i<num2.val.length();++i){
			int current = num2.val[i]-'0';
			num current_product;
			for(int j=0;j<i;j++){
				current_product.val.push_back('0');
			}
			int carry = 0;
			for(int j=0;j<val.length();++j){
				int prod = current*(val[j]-'0')+carry;
				carry = prod/10;
				prod = prod%10;
				current_product.val.push_back((char)(prod+'0'));
			}
			if(carry!=0){
				current_product.val.push_back((char)(carry+'0'));
			}
			product = product + current_product;
		}
		return product;
	}
	void operator*(const int n){
		int carry = 0;
		for(int i=0;i<val.length();++i){
			int prod = n*(val[i]-'0') + carry;
			carry = prod/10;
			prod = prod%10;
			val[i] = prod + '0';
		}
		if(carry!=0){
			val.push_back((char)(carry+'0'));
		}
	}
};

num power_exponent(num a,int N){
	num result;
	result.val = "1";
	while(N>0){
		if(N%2==1){
			result = result * a;
		}
		a = a * a;
		N = N>>1;
	}
	return result;
}
int calculate(num& a){
	int ans = 0;
	for(int i=0;i<a.val.length();++i){
		ans += (a.val[i]-'0');
	}
	return ans;
}
int calculate(ulli a){
	int ans = 0;
	while(a){
		ans += (a%10);
		a /= 10;
	}
	return ans;
}
void solve(num& _base_num){
	int n;
	cin>>n;
	if(n<64){
		ulli ans = (ulli)pow(2,n);
		cout<<calculate(ans)<<endl;
	}
	int _power = n/64;
	int m = n%64;
	ulli multi = pow(2,m);
	num _multi;
	_multi.val = to_string(multi);
	reverse(_multi.val.begin(),_multi.val.end());
	num ans = power_exponent(_base_num,_power);
	ans = ans*_multi;
	cout<<calculate(ans)<<endl;

}
int main() {

	string _base_string = to_string(_base_power);
	reverse(_base_string.begin(),_base_string.end());
	num _base_num;
	_base_num.val = _base_string;
	int t;
	cin>>t;
	while(t--){
		solve(_base_num);
	}
	return 0;
}



*/
