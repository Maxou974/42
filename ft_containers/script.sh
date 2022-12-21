#!/usr/bin/zsh
RED="\033[1;31m"
GREEN="\033[1;32m"
NOCOLOR="\033[0m"

make stdd > /dev/null || exit 1
make re > /dev/null || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/std.valgrind" ./a.out > output/std

make ftt > /dev/null || exit 1
make re > /dev/null || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/ft.valgrind" ./a.out > output/ft

./sed output/std "std::" ""
./sed output/ft "ft::" ""

mv output/std.replace output/std
mv output/ft.replace output/ft

if grep -e "no leaks are possible" -e "0 errors" output/std.valgrind > /dev/null
then echo "${GREEN}std.No errors\nstd.No leaks${NOCOLOR}\n"
else echo "${RED}std.errors" ; sed -e '1,6d' output/std.valgrind ; echo "${NOCOLOR}\n"
fi

if grep -e "no leaks are possible" -e "0 errors" output/ft.valgrind > /dev/null
then echo "${GREEN}ft.No errors\nft.No leaks${NOCOLOR}\n"
else echo "${RED}ft.errors" ; sed -e '1,6d' output/ft.valgrind ; echo "${NOCOLOR}\n"
fi

if echo -n "${RED}" & diff output/std output/ft
then echo "${GREEN}Identical output${NOCOLOR}"
else echo "${NOCOLOR}"
fi

make fclean