#!/usr/bin/zsh
RED="\033[1;31m"
GREEN="\033[1;32m"
NOCOLOR="\033[0m"

make stdd  || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/std.valgrind" ./a.out > output/std

make ftt || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/ft.valgrind" ./a.out > output/ft

sed -i 's/std:://g' output/std
sed -i 's/ft:://g' output/ft

if grep "no leaks are possible" output/std.valgrind > /dev/null && grep "0 errors" output/std.valgrind > /dev/null
then echo "${GREEN}std.No errors\nstd.No leaks${NOCOLOR}\n"
else echo "${RED}std.errors" ; sed -e '1,6d' output/std.valgrind ; echo "${NOCOLOR}\n"
fi

if grep "no leaks are possible" output/ft.valgrind > /dev/null && grep "0 errors" output/ft.valgrind > /dev/null
then echo "${GREEN}ft.No errors\nft.No leaks${NOCOLOR}\n"
else echo "${RED}ft.errors" ; sed -e '1,6d' output/ft.valgrind ; echo "${NOCOLOR}\n"
fi

if echo -n "${RED}" & diff output/std output/ft
then echo "${GREEN}Identical output${NOCOLOR}"
else echo "${NOCOLOR}"
fi

make fclean