#!/bin/bash

crosses="🔷 "
crosses_mini="🔹 "
noughts="🔶 "
noughts_mini="🔸 "
points="◽️ "

sed "s/O/$crosses/g" |
sed "s/X/$noughts/g" |
sed "/^0.. /s/x/$noughts_mini/g" |
sed "/^0.. /s/o/$crosses_mini/g" |
sed "/^0.. /s/\./$points/g" 
