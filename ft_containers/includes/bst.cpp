#include "BST.hpp"
#include <string>
#include <map>

int main()
{
	std::pair<std::string, std::string>* tab;

	tab = new std::pair<std::string, std::string>[5];
	tab[0].first = "0";
	tab[0].second = "Zero";
	tab[1].first = "1";
	tab[1].second = "Un";
	tab[2].first = "2";
	tab[2].second = "Deux";
	tab[3].first = "3";
	tab[3].second = "Trois";
	tab[4].first = "4";
	tab[4].second = "Quatre";

	std::map<std::string,std::string> m_map(tab, tab + 5);

	m_map.insert(tab, tab + 5);
	std::cout << m_map.size() << '\n';
 
	delete [] tab;
}