set terminal postscript portrait
set nolabel
set xlabel "x"
set xrange [8:3000]
set ylabel "time/(x*x)"
set yrange [0:0.2]
set output "time.ps"
plot "time.dat" title "Big(O) estimation" with linespoints