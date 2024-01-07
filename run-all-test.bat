g++ Test/utest.cpp Logger/logger.cpp Utils/*.cpp RootFindingAlgorithms/*.cpp Integration/*.cpp LinearAlgebra/*.cpp -o utest
utest

del *.exe
@REM del *.dll
@REM del *.so