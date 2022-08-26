echo Checking if /build is a directory
DIRECTORY='build/'
if [ -d "$DIRECTORY" ];
then
  cd build/
else
  echo Creating directory build/
  mkdir build/
  cd build/
fi

echo Generating Makefile
cmake ..
echo Making project
make
echo Running all Google Tests
./Google_tests/Google_Tests_run
cd ..
echo Done