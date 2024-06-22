#!/bin/bash
g++ ./*.cpp -L/usr/lib/x86_64-linux-gnu/ -lmariadbcpp -o executable 
./executable
