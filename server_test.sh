#!/bin/bash
# Server test script


echo "Running server test"

echo "*** Running negative tests. All should fail ***"

echo "* Testing argument length *"

echo "No arguments ( four short )"
echo "./server"
./server > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "* Testing port input *"

echo "Check that only numeric values are accepted"
echo "./server bad-port"
./server bad-port > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "Mixed type"
echo "./server bad-123"
./server bad-123 > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "Out of port range ( below )"
echo "./server 123"
./server 123 > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "Out of port range ( above )"
echo "./server 123456789"
./server 123456789 > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "Out of port range ( -1 ) "
echo "./server -1"
./server -1 > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo
