#include <vector>
#include <iostream>
#include <memory>
#include "../includes/vector.hpp"
#include "../includes/iterator.hpp"
#include <string>
#include <string.h>
#include <cstdlib>
// #include "cont/containers/vector.hpp"
// #include "contt/includes/vector.hpp"

#define NL ft::cout << '\n';
using namespace std;

template<typename T>
void fct(ft::vector<T>& vect)
{
	for (typename ft::vector<T>::size_type i = 0; i < vect.size(); i++)
		cout << vect[i] << " | ";
	cout << '\n';
	cout << "ft::capacity: " << vect.capacity() << "  ft::size: " << vect.size() << '\n';
}

void	header_test(string msg)
{
	cout << "\n__________";
	cout << msg;
	cout << "__________\n\n";
}

class	test{
	public:
	char *tab;
	int n;

	test(){
		tab = strdup("random");
	}

	~test(){ free(tab); }
	
	test	(const test& ref){
		tab = strdup(ref.tab);
	}

	test(char* y){
		tab = strdup(y);
	}

	test&	operator=(const test& ref)
	{
		if (&ref == this)
			return *this;
		free(tab);
		tab = strdup(ref.tab);
		return *this;
	}

};

ostream& operator<<(ostream& out, const test& ref)
{
	out << ref.tab; return out;
}

void	vector_test();

void vector_test()
{
	char *tm = strdup("hello");
	char *tm2 = strdup("bye");
	char *tm3 = strdup("ok");
	char *tm4 = strdup("ahah");
	test	tmp(tm);

	header_test("CONSTRUCTOR OPERATOR=");

	ft::vector<test> ve; fct(ve);
	ft::vector<test> vee(1, tm); fct(vee);
	ft::vector<test> veee(5, tm); fct(veee);
	ft::vector<test> veeee(5); fct(veeee);
	ft::vector<test> veeeee(1); fct(veeeee);

	veee = ve = veeee;
	fct(veee);
	fct(ve);

	header_test("RESIZE RESERVE");

	fct(veee);
	veee.resize(1, tmp);
	veee.resize(2);
	veee.resize(1);
	veee.resize(2);
	veee.reserve(5);
	veee.reserve(3);
	veee.resize(2);
	veee.resize(3);
	veee.resize(4); 
	veee.reserve(3);
	veee.resize(10, tmp);
	veee.resize(0, tmp);
	fct(veee);

	header_test("EMPTY CLEAR");

	cout << ve.empty() << " " << veee.empty() << '\n';

	ve.clear();

	cout << ve.empty() << " " << veee.empty() << '\n';

	header_test("PUSH_BACK POP_BACK");

	ve.push_back(tm);
	ve.push_back(tm3);	
	ve.push_back(tm3);
	ve.push_back(tm2);	
	ve.push_back(tm3);
	ve.push_back(tm2);
	ve.push_back(tm2);
	ve.push_back(tm4);
	ve.pop_back();

	cout << ve[2] << '\n';
	fct(ve);
	
	header_test("OPERATOR[]");
	
	test& non = ve[1];
	
	const test& t = ve[1];
	
	cout << "const ref ve[1]: " << t << '\n';
	cout << "ref ve[1]: " << non << '\n';

	header_test("FRONT");

	const test& te = non = ve.front();
	cout <<  "const ref front: " << te << '\n';
	cout <<  "ref front: " << non << '\n';
	
	header_test("BACK");

	const test& tee = non = ve.back();
	cout << "const ref back: " << tee << '\n';
	cout << "ref back: " << non << '\n';

	header_test("DATA");

	ft::vector<test>::value_type *vect = ve.data();
	cout << "ve.data[0]: " << vect[0] << "\nve.data[2]: " << vect[2] << '\n';

	const ft::vector<test>::value_type *vectt = ve.data();
	cout << "const ve.data[0]: " << vectt[0];
	cout << "\nconst ve.data[2]: " << vectt[2] << '\n';


	header_test("ASSIGN");

	ft::vector<test>::iterator beg = ve.begin();
	ft::vector<test>::iterator end = ve.end();
	
	cout << "ve before:" << '\n'; fct(ve);
	cout << "vee before:" << '\n'; fct(vee);

	vee.assign(beg + 1, end - 1);
	cout << "\nvee.assign(beg + 1, end - 1)\n";

	cout << "\nvee after:" << '\n'; fct(vee);

	cout << "veee before:" << '\n'; fct(veee);
	veee.assign(5, tm3);
	cout << "veee.assign(5, tm3)\n";
	cout << "veee after:" << '\n'; fct(veee);
	veee.assign(0, tm4);
	cout << "veee after:" << '\n'; fct(veee);



	header_test("SWAP");

	cout << "ve before:" << '\n'; fct(ve);
	cout << "vee before:" << '\n'; fct(vee);
	ve.swap(vee);
	cout << "ve.swap(vee)\n";
	cout << "ve after:" << '\n'; fct(ve);
	cout << "vee after:" << '\n'; fct(vee);


	header_test("INSERT");
	cout << "ve before:" << '\n'; fct(ve);
	ve.insert(ve.begin() + 1, 3, tm4);
	cout << "ve after:" << '\n'; fct(ve);
	ve.insert(ve.begin() + 4, tm4);
	cout << "ve after:" << '\n'; fct(ve);
	beg = ve.insert(ve.begin() + 1, tm4);
	cout << "ve after:" << '\n'; fct(ve);
	cout << *beg;

	cout << "vee before:" << '\n'; fct(vee);
	vee.insert(vee.begin() + 1, ve.begin()+1, ve.begin()+5);
	cout << "vee after:" << '\n'; fct(vee);
	vee.insert(vee.begin(), ve.begin()+1, ve.begin()+5);
	cout << "vee after:" << '\n'; fct(vee);
	vee.insert(vee.begin()+2, ve.begin(), ve.end());
	cout << "vee after:" << '\n'; fct(vee);
	ve.insert(ve.end() - 2, 6, tm4);
	cout << "ve before:" << '\n'; fct(ve);
	ve.insert(ve.end() - 1 , 4, tm4);
	cout << "ve after:" << '\n'; fct(ve);
	beg = ve.erase(ve.end()-1);
	cout << "ve after:" << '\n'; fct(ve);
	ve.erase(beg);
	cout << "ve after:" << '\n'; fct(ve);
	beg = ve.erase(ve.begin());
	cout << "ve after:" << '\n'; fct(ve);
	ve.erase(beg);
	cout << "ve after:" << '\n'; fct(ve);
	ve.erase(ve.begin(), ve.begin() + 2);
	cout << "vee before:" << '\n'; fct(vee);
	vee.insert(vee.begin() + 1, ve.begin()+1, ve.begin()+5);
	cout << "vee after:" << '\n'; fct(vee);
	vee.insert(vee.begin(), ve.begin()+1, ve.begin()+5);
	cout << "vee after:" << '\n'; fct(vee);
	vee.insert(vee.begin()+2, ve.begin(), ve.end());
	cout << "vee after:" << '\n'; fct(vee);
	ve.insert(ve.end() - 2, 6, tm4);
	cout << "ve after:" << '\n'; fct(ve);
	beg = ve.erase(ve.end()-1);
	cout << "ve after:" << '\n'; fct(ve);
	ve.erase(beg);
	cout << "ve after:" << '\n'; fct(ve);
	beg = ve.erase(ve.begin());
	cout << "ve after:" << '\n'; fct(ve);
	ve.erase(beg);
	cout << "ve after:" << '\n'; fct(ve);
	ve.erase(ve.begin(), ve.begin() + 2);
	cout << "vee before:" << '\n'; fct(vee);
	vee.insert(vee.begin() + 1, ve.begin()+1, ve.begin()+5);
	cout << "vee after:" << '\n'; fct(vee);
	vee.insert(vee.begin(), ve.begin()+1, ve.begin()+5);
	fct(ve);
	fct(vee);
	cout << "max size:" << ve.max_size() << '\n';



	ft::vector<int> v;
	ft::vector<int> vv;

	for (int i = 0; i < 999999; i++)
		vv.push_back(i+1);

	fct(vv);

	v.insert(v.begin(), vv.begin(), vv.end());
	
	v.insert(v.begin() + 124, vv.begin(), vv.end());
	v.insert(v.end(), vv.begin(), vv.end());

	v.insert(v.begin() + 2363, 30000, 234);
	fct(v);

	header_test("REVERSE_ITERATOR");
	ve.clear();
	ve.push_back(tm);
	ve.push_back(tm2);
	ve.push_back(tm3);
	ve.push_back(tm4);
	ve.push_back(tm);
	ve.push_back(tm2);
	ve.push_back(tm3);
	ve.push_back(tm4);
	{
	ft::vector<test>::reverse_iterator rit = ve.rbegin();
	ft::vector<test>::reverse_iterator ritt(rit);

	fct(ve);
	cout << *ritt << '\n';
	cout << *(rit++) << '\n';
	cout << *rit << '\n';
	cout << *(++rit) << '\n';
	cout << *rit << '\n';
	cout << *(rit--) << '\n';
	cout << *rit << '\n';
	cout << *(--rit) << '\n';
	cout << *rit << '\n';
	rit += 4;
	cout << *rit << '\n';
	rit -= 2;
	cout << *rit << '\n';
	rit = rit + 2;
	cout << *rit << '\n';
	rit = rit - 2;
	cout << *rit << '\n';
	rit = 1 + rit;
	cout << *rit << '\n';

	cout << ritt - rit << '\n';
	cout << rit - ritt << '\n';
	
	cout << "rit[3]:" << rit[3] << '\n';
	cout << rit->tab << '\n';
	cout << "==  " << (rit == ritt) << '\n';
	rit++;
	rit++;
	rit++;
	ritt++;
	cout << "!=  " << (rit != ritt) << '\n';
	cout << "<=  " << (rit <= ritt) << '\n';
	cout << ">=  " << (rit >= ritt) << '\n';
	cout << "<  " << (rit < ritt) << '\n';
	cout << ">  " << (rit > ritt) << '\n';
	rit = ve.rbegin();
	test g;
	*rit = g;
	}
	header_test("ITERATOR");
	{
	ft::vector<test>::iterator rit = ve.begin();
	ft::vector<test>::iterator ritt = ve.begin();
	ft::vector<test>::reverse_iterator rittt(rit + 2);
	cout  << *rit << "  " << *rittt << '\n';
	fct(ve);

	cout << *(rit++) << '\n';
	cout << *rit << '\n';
	cout << *(++rit) << '\n';
	cout << *rit << '\n';
	cout << *(rit--) << '\n';
	cout << *rit << '\n';
	cout << *(--rit) << '\n';
	cout << *rit << '\n';

	rit += 4;
	cout << *rit << '\n';
	rit -= 2;
	cout << *rit << '\n';

	rit = rit + 2;
	cout << *rit << '\n';
	rit = 2 + rit;
	cout << *rit << '\n';
	rit = rit - 2;
	cout << *rit << '\n';

	cout << ritt - rit << '\n';
	cout << rit - ritt << '\n';

	cout << "rit[3]:" << rit[3] << '\n';
	cout << rit->tab << '\n';
	cout << (rit == ritt) << '\n';
	rit++;
	rit++;
	rit++;
	ritt++;
	cout << "!=  " << (rit != ritt) << '\n';
	cout << "<=  " << (rit <= ritt) << '\n';
	cout << ">=  " << (rit >= ritt) << '\n';
	cout << "<  " << (rit < ritt) << '\n';
	cout << ">  " << (rit > ritt) << '\n';
	test g;
	*rit = g;

	}
	{
		header_test("COMPARE");
		ft::vector<int> un;
		ft::vector<int> deux;

		un.push_back(3);
		un.push_back(3);
		un.push_back(4);
		deux.push_back(4);
		deux.push_back(4);
		deux.push_back(5);
		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';

		ft::swap(un, deux);
		
		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';
		
		un = deux;
		
		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';

		un.clear(); deux.clear();

		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';

		un.push_back(3);
		un.push_back(4);
		deux.push_back(3);
		deux.push_back(3);
		deux.push_back(3);

		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';

		un.clear(); deux.clear();

		un.push_back(3);
		un.push_back(2);
		deux.push_back(3);
		deux.push_back(3);
		deux.push_back(3);

		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';

		un.clear(); deux.clear();

		un.push_back(3);
		un.push_back(3);
		un.push_back(3);
		deux.push_back(3);
		deux.push_back(3);

		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';

		un.clear(); deux.clear();

		un.push_back(3);
		un.push_back(3);
		un.push_back(3);
		deux.push_back(3);
		deux.push_back(3);
		deux.push_back(3);

		cout << (un < deux) << '\n';
		cout << (un > deux) << '\n';
		cout << (un == deux) << '\n';
		cout << (un != deux) << '\n';
		cout << (un <= deux) << '\n';
		cout << (un >= deux) << '\n';
	}

	cout << "\n\n\nve\n";
	fct(ve);
	cout << "\nvee\n";
	fct(vee);
	cout << "\nveee";
	fct(veee);
	cout << "\nveeee\n";
	fct(veeee);
	cout << "\nveeeee\n";
	fct(veeeee);

	free(tm);
	free(tm2);
	free(tm3);
	free(tm4);
}
