# Compiles, runs and plots output from c++ code

g++ LTI.cpp main.cpp
./a.out
# gnuplot -persist ./plots/LTI.gplot
# gnuplot -persist ./plots/LTI-x-pos.gplot
# gnuplot -persist ./plots/LTI-x-vel.gplot
# gnuplot -persist ./plots/LTI-y-pos.gplot
# gnuplot -persist ./plots/LTI-y-vel.gplot
gnuplot -persist ./plots/LTI-x-y-pos.gplot

