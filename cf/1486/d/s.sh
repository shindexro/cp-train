FAST="d"
BRUTE="brute"
GEN="gen"

g++ -ulimit -Wall -Wno-unused-result -std=c++17 -O2 -DONLINE_JUDGE $FAST.cpp -o $FAST.exe
g++ -ulimit -Wall -Wno-unused-result -std=c++17 -O2 -DONLINE_JUDGE $BRUTE.cpp -o $BRUTE.exe
g++ -ulimit -Wall -Wno-unused-result -std=c++17 -O2 -DONLINE_JUDGE $GEN.cpp -o $GEN.exe

for((i = 1; i <= 10000; i++));
do
    echo $i
    ./$GEN.exe $i > gen_in.txt
    ./$FAST.exe < gen_in.txt > gen_fast.txt
    ./$BRUTE.exe < gen_in.txt > gen_brute.txt
    diff -w gen_fast.txt gen_brute.txt || break
done

read -n 1 -s -r -p "Press any key to continue"
