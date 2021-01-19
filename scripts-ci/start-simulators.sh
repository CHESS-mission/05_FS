#!/bin/bash

#imports necessary for the simulators
python -m pip install python-statemachine

#simulators start
python simulators/ADCS/TcpMain.py &


#launch zmqproxy
sudo simulators/EPS/zmqproxy &

#launch EPS simulator
export LD_LIBRARY_PATH=simulators/EPS/packages/csp/lib
python simulators/EPS/CspMain.py -ld &