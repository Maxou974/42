#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cctype>

using namespace std;

void	printascii(string str)
{
	string A[5] = {
	"#####",
	"#   #",
	"#####",
	"#   #",
	"#   #",},
B[5] = {
	"#####",
	"#   #",
	"#####",
	"#   #",
	"#####",},
C[5] = {
	" ####",
	"#    ",
	"#    ",
	"#    ",
	" ####",},
D[5] = {
	"#### ",
	"#   #",
	"#   #",
	"#   #",
	"#### ",},
E[5] = {
	"#####",
	"#    ",
	"#####",
	"#    ",
	"#####",},
F[5] = {
	"#####",
	"#    ",
	"#####",
	"#    ",
	"#    ",},
G[5] = {
	"#### ",
	"#    ",
	"#  ##",
	"#   #",
	"#####",},
H[5] = {
	"#   #",
	"#   #",
	"#####",
	"#   #",
	"#   #",},
I[5] = {
	"#####",
	"  #  ",
	"  #  ",
	"  #  ",
	"#####",},
J[5] = {
	"    #",
	"    #",
	"    #",
	"#   #",
	"#####",},
K[5] = {
	"#  ##",
	"# ## ",
	"###  ",
	"# ## ",
	"#  ##",},
L[5] = {
	"#    ",
	"#    ",
	"#    ",
	"#    ",
	"#####",},
M[5] = {
	"##   ##",
	"# ### #",
	"#  #  #",
	"#     #",
	"#     #",},
N[5] = {
	"#   #",
	"##  #",
	"# # #",
	"#  ##",
	"#   #",},
O[5] = {
	"#####",
	"#   #",
	"#   #",
	"#   #",
	"#####",},
Q[5] = {
	"##### ",
	"#   # ",
	"#   # ",
	"######",
	"    ##",},	
P[5] = {
	"#####",
	"#   #",
	"#####",
	"#    ",
	"#    ",},	
R[5] = {
	"#####",
	"#   #",
	"#####",
	"# #  ",
	"#  # ",},	
S[5] = {
	"#####",
	"#    ",
	"#####",
	"    #",
	"#####",},
T[5] = {
	"#####",
	"  #  ",
	"  #  ",
	"  #  ",
	"  #  ",},
U[5] = {
	"#   #",
	"#   #",
	"#   #",
	"#   #",
	"#####",},
V[5] = {
	"#   #",
	"#   #",
	"#   #",
	" # # ",
	"  #  ",},
W[5] = {
	"#   #",
	"#   #",
	"# # #",
	"# # #",
	"#####",},
X[5] = {
	"#   #",
	" # # ",
	"  #  ",
	" # # ",
	"#   #",},
Y[5] = {
	"#   #",
	"#   #",
	"#####",
	"  #  ",
	"  #  ",},
Z[5] = {
	"#####",
	" #   ",
	"  #  ",
	"   # ",
	"#####",};
	vector<string*> alphabet;
	
	alphabet.push_back(A);
	alphabet.push_back(B);
	alphabet.push_back(C);
	alphabet.push_back(D);
	alphabet.push_back(E);
	alphabet.push_back(F);
	alphabet.push_back(G);
	alphabet.push_back(H);
	alphabet.push_back(I);
	alphabet.push_back(J);
	alphabet.push_back(K);
	alphabet.push_back(L);
	alphabet.push_back(M);
	alphabet.push_back(N);
	alphabet.push_back(O);
	alphabet.push_back(P);
	alphabet.push_back(Q);
	alphabet.push_back(R);
	alphabet.push_back(S);
	alphabet.push_back(T);
	alphabet.push_back(U);
	alphabet.push_back(V);
	alphabet.push_back(W);
	alphabet.push_back(X);
	alphabet.push_back(Y);
	alphabet.push_back(Z);

	std::vector<int> word;
	std::cout << '\n';
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
		word.push_back(str[i] - 'A');
	}
	for (int i = 0; i < 5; i++)	
	{
		for (size_t j = 0; j < str.size(); j++)
			cout << alphabet[word[j]][i] << "  ";
		cout << '\n';
	}
	std::cout << '\n';
}


// int main()
// {
// 	printascii("ITERATOR");
// 	printascii("MAP");
// 	printascii("BST");

// }
