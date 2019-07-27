reset

set linetype  1 lc rgb "dark-violet" lw 1
set linetype  2 lc rgb "#009e73" lw 1
set linetype  3 lc rgb "#56b4e9" lw 1
set linetype  4 lc rgb "#e69f00" lw 1
set linetype  5 lc rgb "#f0e442" lw 1
set linetype  6 lc rgb "#0072b2" lw 1
set linetype  7 lc rgb "#e51e10" lw 1
set linetype  8 lc rgb "black"   lw 1
set linetype  9 lc rgb "gray50"  lw 1
set linetype cycle  9

points = "entropy_x_d_L.txt"

set terminal postscript enhanced dashed color

set grid
set key left top title "System Size\n(Natural Units)" box

set xlabel "Sampling Size (bits)"
set ylabel "Entropy (J/K)"
set title "Entropy behavior when \n changing sampling size and system size"

set output "entropy_x_d_L.eps"

plot points u 1:2 title "64"
replot points u 1:3 title "128"
replot points u 1:4 title "256"
replot points u 1:5 title "512"
replot points u 1:6 title "1024"
replot points u 1:7 title "2048"

replot 

reset