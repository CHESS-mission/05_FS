#!/bin/bash

#imports necessary for the simulators
python -m pip install python-statemachine

#simulators start
python simulators/ADCS/TcpMain.py &

#start zmq
sudo chmod 777 simulators/EPS/zmqproxy
sudo ./simulators/EPS/zmqproxy &

#launch EPS simulator
sudo chmod 777 simulators/EPS/packages/csp/lib/libcsp.so simulators/EPS/packages/csp/lib/libcsp_py3.so
python simulators/EPS/CspMain.py &