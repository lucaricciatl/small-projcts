=======================binaries launch(windows)=====================
cd Bin 
./accelerometer.exe

=========================binaries launch(linux)=====================
cd linuxbuild

=======================build instructions win=======================

cd build
cmake ..
cmake --build .

=======================build instructions linux====================

cd linuxbuild
cmake ..
cmake --build .



========================================================

unit test - no, but we can easly implement them due to the modularity of the program
end-to-end test - tested on windows and linux
multiplatform - yes
documentation - provided by request