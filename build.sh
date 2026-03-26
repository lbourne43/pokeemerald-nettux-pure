#!/bin/bash

echo "Generating shop"
./shop.py > src/nettux_shop.h
echo "Generating trainers.party"
./gen_trainer_pools.py > trainers.party
if [[ "x$1" == "x--clean" ]]; then
  echo "Cleaning"
  make clean
fi
echo "Building"
make -j $(nproc)
echo "Writing to Pokemon Emerald Nettux Pure.gba"
cp pokeemerald.gba "Pokemon Emerald Nettux Pure.gba"
