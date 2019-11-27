export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:lib/
valgrind --track-origins=yes --leak-check=full  ./bin/Ejecutable  
#--gen-suppressions=all