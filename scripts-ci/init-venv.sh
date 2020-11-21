#!/bin/bash

app="./App"

#stop on error
set -e

#create the venv
python3 -m venv ./fprime-venv

#activate the venv
. ./fprime-venv/bin/activate

#get the git submodule and go inside it
cd fprime/

#build the venv
pip install --upgrade wheel setuptools pip
pip install ./Fw/Python
pip install ./Gds

#deactivate the venv
deactivate
