#!/bin/bash

#imports necessary for the simulators
python -m pip install python-statemachine

#simulators start
python simulators/ADCS/TcpMain.py &

#start zmq

sudo chmod 777 simulators/EPS/zmqproxy
sudo ./simulators/EPS/zmqproxy &

#launch EPS simulator
export LD_LIBRARY_PATH=packages/csp/lib
cd simulators/EPS/packages/csp/lib
ls -la