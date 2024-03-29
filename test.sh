#!/bin/bash
# Tester for push_swap by @tsannie


# C0l0r$
RED="\033[1m\033[31m"
YELLOW="\033[1m\033[33m"
CYAN="\033[1m\033[36m"
GREEN="\033[1m\033[32m"
END="\033[0m"

# Compile and give permissions

chmod 755 push_swap
chmod 755 checker

TMP='.tmp';
CPT=0
NB_TEST=0

# test with yours numbers
test()
{
	./push_swap $@ > $TMP
	NB_LINE=$(wc -l < $TMP)
	RESULT=$(./checker $@ < $TMP)
	if [[ $RESULT == "OK" ]]; then
		printf "status:              [$GREEN%s$END]\n" "$RESULT"
		printf "nb_instructions: $YELLOW%s$END" "$NB_LINE"
		((CPT++))
	else
		printf "status:              [$RED%s$END]\n" "$RESULT"
	fi

	rm ${TMP}
	((NB_TEST++))
	echo
	echo
}

# test with generated numbers
generate_test()
{
	GENERATE=`ruby -e "puts ($@).to_a.shuffle.join(' ')"`
	test $GENERATE
}

# all tests

printf "Test with [${CYAN}1$END] numbers:\n"
test '1'

printf "Test with [${CYAN}2$END] numbers:\n"
test '1 -50'

printf "Test with [${CYAN}3$END] numbers:\n"
test '3 2 1'

printf "Test with [${CYAN}3$END] numbers:\n"
test '1 2 3'

printf "Test with [${CYAN}5$END] numbers:\n"
generate_test '1..5'

printf "Test with [${CYAN}10$END] numbers:\n"
generate_test '1..10'

printf "Test with [${CYAN}20$END] numbers:\n"
generate_test '1..20'

printf "Test with [${CYAN}50$END] numbers:\n"
generate_test '1..50'

printf "Test with [${CYAN}100$END] numbers:\n"
generate_test '1..100'

printf "Test with [${CYAN}500$END] numbers:\n"
generate_test '1..500'

printf "Test with [${CYAN}1000$END] numbers:\n"
generate_test '1..1000'

printf "Test with [${CYAN}2000$END] numbers:\n"
generate_test '-1000..1000'

printf "Test with [${CYAN}5000$END] numbers:\n"
generate_test '1..5000'

echo
if [[ $RESULT == "OK" ]]; then
	printf "Results : $GREEN%d/%d$END \n" "$CPT" "$NB_TEST"
else
	printf "Results : $RED%d/%d$END \n" "$CPT" "$NB_TEST"
fi

