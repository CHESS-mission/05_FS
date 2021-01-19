#!/bin/bash

#imports necessary for the simulators
python -m pip install python-statemachine

#simulators start
python simulators/ADCS/TcpMain.py &


#launch zmqproxy
sudo simulators/EPS/zmqproxy

#launch EPS simulator
python simulators/EPS/CspMain.py