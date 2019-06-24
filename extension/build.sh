#!/usr/bin/env bash
phpize
./configure --enable-xor-string
make
make install
