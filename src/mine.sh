#!/bin/bash
for i in {1..999}
do
	echo " $i "
	./terraaustralis-cli -testnet -generate
done
