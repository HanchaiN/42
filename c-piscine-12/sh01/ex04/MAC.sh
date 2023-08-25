#!/bin/sh
ifconfig | grep -o "ether ..:..:..:..:..:.." | sed "s/ether //"
