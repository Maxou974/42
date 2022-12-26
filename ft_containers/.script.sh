#!/usr/bin/zsh
RED="\033[1;31m"
GREEN="\033[1;32m"
WHITE="\033[1;37m"
NOCOLOR="\033[0m"

echo "${WHITE}Running std:"

make stdd > /dev/null || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/std.valgrind" ./a.out > output/std

if grep "no leaks are possible" output/std.valgrind > /dev/null && grep "0 errors" output/std.valgrind > /dev/null
then echo "${GREEN}No errors\nNo leaks${NOCOLOR}\n"
else echo "${RED}errors" ; sed -e '1,6d' output/std.valgrind ; echo "${NOCOLOR}\n"
fi
sed -i 's/std:://g' output/std


echo "${WHITE}Running ft:"

make ftt > /dev/null || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/ft.valgrind" ./a.out > output/ft

if grep "no leaks are possible" output/ft.valgrind > /dev/null && grep "0 errors" output/ft.valgrind > /dev/null
then echo "${GREEN}No errors\nNo leaks${NOCOLOR}\n"
else echo "${RED}Errors" ; sed -e '1,6d' output/ft.valgrind ; echo "${NOCOLOR}\n"
fi
sed -i 's/ft:://g' output/ft


echo "${WHITE}Output diff:"

if echo -n "${RED}" & diff output/std output/ft
then echo "${GREEN}Identical output${NOCOLOR}"
else echo "${NOCOLOR}"
fi

make fclean > /dev/null