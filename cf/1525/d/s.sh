for((i = 1; i <= 10000; i++));
do
    echo $i
    ./gen.exe $i > int
    ./d.exe < int > out1
    ./ed.exe < int > out2
    diff -w out1 out2 || break
done
