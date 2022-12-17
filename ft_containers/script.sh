#!/usr/bin/zsh
RED="\033[1;31m"
GREEN="\033[1;32m"
NOCOLOR="\033[0m"

make stdd > /dev/null || exit 1
make testre > /dev/null || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/std.valgrind" ./a.out > std

make ftt > /dev/null || exit 1
make testre > /dev/null || exit 1
valgrind --leak-check=full --track-origins=yes --log-file="output/ft.valgrind" ./a.out > ft

./sed std "std::" ""
./sed ft "ft::" ""

mv std.replace output/std
mv ft.replace output/ft

rm std ft

if cat output/std.valgrind | grep "no leaks are possible" > /dev/null
then echo "${GREEN}std.leaks are OKAY${NOCOLOR}"
else echo "${RED}std.valgrind" ; sed -e '1,7d' output/std.valgrind ; echo "${NOCOLOR}"
fi

if cat output/std.valgrind | grep "0 errors" > /dev/null
then echo "${GREEN}std.No errors${NOCOLOR}\n"
else echo "${RED}std.valgrind" ; sed -e '1,6d' output/std.valgrind ; echo "${NOCOLOR}\n"
echo "\n"
fi

if cat output/ft.valgrind | grep "no leaks are possible" > /dev/null
then echo "${GREEN}ft.leaks are OKAY${NOCOLOR}"
else echo "${RED}ft.valgrind" ; sed -e '1,7d' output/ft.valgrind ; echo "${NOCOLOR}"
fi

if cat output/ft.valgrind | grep "0 errors" > /dev/null
then echo "${GREEN}ft.No errors${NOCOLOR}\n"
else echo "${RED}ft.valgrind" ; sed -e '1,6d' output/ft.valgrind ; echo "${NOCOLOR}\n"
fi

if echo -n "${RED}" & diff output/std output/ft
then echo "${GREEN}Identical output${NOCOLOR}"
else echo "${NOCOLOR}"
fi

make fclean