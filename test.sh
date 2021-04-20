#!/bin/bash
# Tester for push_swap by @tsannie


# C0l0r$
RED="\033[1m\033[31m"
YELLOW="\033[1m\033[33m"
CYAN="\033[1m\033[36m"
GREEN="\033[1m\033[32m"
END="\033[0m"

# Compile and give permissions
make
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

printf "Test with [${CYAN}100$END] numbers:\n"
generate_test '1..100'

printf "Test with [${CYAN}500$END] numbers:\n"
generate_test '1..500'

printf "Test with [${CYAN}500$END] numbers:\n"
generate_test '1..500'

printf "Test with [${CYAN}500$END] numbers:\n"
generate_test '1..500'

printf "Test with [${CYAN}1000$END] numbers:\n"
generate_test '1..1000'

printf "Test with [${CYAN}10 000$END] numbers:\n"
generate_test '1..10000'

echo
if [[ $RESULT == "OK" ]]; then
	printf "Results : $GREEN%d/%d$END \n" "$CPT" "$NB_TEST"
else
	printf "Results : $RED%d/%d$END \n" "$CPT" "$NB_TEST"
fi

