#!/bin/bash

#imports necessary for the simulators
python -m pip install python-statemachine

#simulators start
python simulators/ADCS/TcpMain.py &

#start zmq
cd simulators/EPS
ls -la
sudo chmod 777 zmqproxy
ls -la
sudo ./zmqproxy

#launch EPS simulator
export LD_LIBRARY_PATH=simulators/EPS/packages/csp/lib
python simulators/EPS/CspMain.py &