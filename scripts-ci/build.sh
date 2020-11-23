#!/bin/bash


#Activate the python environnement
. ./fprime-venv/bin/activate

#purge an old app if it exists
cd App/
echo "purging..."; yes | fprime-util purge

#now exit on error
set -e

#build the app
echo "generating..." && fprime-util generate &&
echo "building..." && fprime-util build

#start the gds if "start" is an argument
if [[ "$1" == "start" ]]
then
	if  [[ $? -eq 0 ]]
	then
		echo "starting gds..."
		fprime-gds
	else
		echo "build failed, gds start aborted"
	fi
fi
