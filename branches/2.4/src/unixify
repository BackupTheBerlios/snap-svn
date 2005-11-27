mv core Core
mv persistance Persistance
mv legacy Legacy

rm -f -a Debug
rm -f -a Release
rm -f -a Core/Debug
rm -f -a Core/Release
rm -f -a Persistance/Debug
rm -f -a Persistance/Release

dos2unix *.*
dos2unix Core/*.*
dos2unix Persistance/*.*
dos2unix Legacy/*.*

for i in *.h *.cpp; do echo "" >> $i ; echo adding newline to $i ; done
for i in Core/*.h Core/*.cpp Legacy/*.h Legacy/*.cpp Persistance/*.h Persistance/*.cpp ; do echo "" >> $i ; echo adding newline to $i ; done
