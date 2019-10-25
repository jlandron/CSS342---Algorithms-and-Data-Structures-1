set terminal postscript portrait
set nolabel
set xlabel "n"
set xrange [2:10000]
set ylabel "sweeping"
set yrange [0:100000]
set output "sieve.ps"
plot x * x, x * log( x ), x * log( log(x) ), x, "sieve.dat" title "sieve of eratosthenes" with lines
