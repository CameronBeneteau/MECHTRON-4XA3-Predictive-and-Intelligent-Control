# Compiles, runs and plots output from c++ code

g++ contLTI.cpp
./a.out
gnuplot -persist ./plots/contLTI.gplot
gnuplot -persist ./plots/contLTI-x-pos.gplot
gnuplot -persist ./plots/contLTI-x-vel.gplot
gnuplot -persist ./plots/contLTI-y-pos.gplot
gnuplot -persist ./plots/contLTI-y-vel.gplot
