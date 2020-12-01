#!/bin/bash

#check if an app name is specified
if [[ -z "$1" ]]
then
	echo "Please specify your app name, exiting..."
	exit 1
fi

#activate the python environnement
. ./fprime-venv/bin/activate

#purge an old app if it exists
cd $1
base_directory=$(pwd)
echo "purging..."; yes | fprime-util purge

#now exit on error
set -e

#generate the build folder for UT
echo "generating..."; fprime-util generate

echo "Searchign Unit Test on $base_directory..."
#get directories that have test in them
dirs=($(find $base_directory -type d -name "test" -not -path "$base_directory/build-*"))
#number of dirs
processed_tests=${#dirs[@]}

for dir in "${dirs[@]}"
do
	echo "found dirs : $dir"
done

#iterate over directories to build their UT
for dir in "${dirs[@]}"
do
	cd $dir
	cd ..
	fprime-util build --ut
	cd $base_directory
done

#iterate over directories to check their tests
for dir in "${dirs[@]}"
do
	echo -e "\n\nDetected component with unit test : $dir"
	cd $dir
	cd ..
	fprime-util check
	cd $base_directory
done

echo -e "\n\nTotal : Checked $processed_tests components for unit tests"