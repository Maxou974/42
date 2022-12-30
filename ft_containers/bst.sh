#!/usr/bin/zsh
RED="\033[1;31m"
GREEN="\033[1;32m"
WHITE="\033[1;37m"
NOCOLOR="\033[0m"


c++ -Wall -Werror -Wextra -std=c++98 bst.cpp || exit 1


# valgrind --track-origins=yes --log-file="bst.valgrind" ./a.out > t
valgrind --track-origins=yes --leak-check=full ./a.out

# if grep "no leaks are possible" bst.valgrind > /dev/null && grep "0 errors" bst.valgrind > /dev/null
# then echo "No errors\nNo leaks\n" >> out
# else echo "errors" >> out; sed -e '1,6d' bst.valgrind ; echo "\n" >> out
# fi
