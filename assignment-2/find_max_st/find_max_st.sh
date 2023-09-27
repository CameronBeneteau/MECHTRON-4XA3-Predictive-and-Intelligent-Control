# Compiles, runs and plots output from c++ code

g++ find_max_st.cpp

./a.out
gnuplot -persist ./find_max_st.gplot

# 10 outputs for assignment
# for i in {1..10}; do
#     ./a.out
#     gnuplot -persist ./find_max_st.gplot
# done
