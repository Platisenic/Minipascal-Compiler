../parser -o $1.j $1.p > /dev/null 2> /dev/null
jasmin -d class $1.j
jasmin -d class io.j
cd class
java $1
