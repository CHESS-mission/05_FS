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
echo "purging..."; yes | fprime-util purge

#now exit on error
set -e

#build the app
echo "generating..."; fprime-util generate

processed_tests=0
dirs=()
for dir in ./*
do
	if [[ -d "$dir/test" ]]
	then
		#echo -e "\n\nDetected component with unit test : $dir"
		processed_tests=$[processed_tests + 1]
		dirs+=($dir)
		cd $dir
		fprime-util build --ut
		#fprime-util check
		cd ..
fi
done

for dir in "${dirs[@]}"
do
	if [[ -d "$dir/test" ]]
	then
		echo -e "\n\nDetected component with unit test : $dir"
		cd $dir
		fprime-util check
fi
done

echo -e "\n\nTotal : Checked $processed_tests components for unit tests"