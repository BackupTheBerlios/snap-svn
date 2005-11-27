#! /bin/sh

create () {
    if [ ! -d $1 ]; then 
	mkdir $1
    fi
}

dr_create () {
    create $1
    cd $1
    create Debug
    create Release
    cd ..
}

link () {
    ln -s /cs/leff/aviadr/seed/$1/Debug Debug
    ln -s /cs/leff/aviadr/seed/$1/Release Release
}


pushd /cs/leff/aviadr

dr_create seed
cd seed

dr_create Core
dr_create Legacy
dr_create Util
dr_create Persistance

popd 

ln -s /cs/leff/aviadr/seed/Debug Debug
ln -s /cs/leff/aviadr/seed/Release Release
link Core
link Legacy
link Util
link Persistence








