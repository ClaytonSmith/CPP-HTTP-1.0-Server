#!/bin/bash
# Client test script

echo "Running client test script\n\n"


echo "*** Running negative tests. All should fail ***"

echo "* Testing argument length *"

echo "No arguments ( four short )"
echo "./client"
./client > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo  "One argument ( three short )"
echo "./client fake_host.com"
./client fake_host.com  > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "Two arguments ( two short )"
echo "./client fake_host.com bad-port"
./client fake_host.com bad-port > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo


echo "Three arguments ( one short )" 
echo "./client fake_host.com bad-port request"
./client fake_host.com bad-port request > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo


echo "* Testing port input  *"

echo "Check that only numeric values are accepted"
echo "./client fake_host.com bad-port request index.html"
./client fake_host.com bad-port request index.html > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

echo "Mixed type"
echo "./client fake_host.com bad-123 request index.html"
./client fake_host.com bad-123 request index.html > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo


echo "* Testing request type *"

echo "This request does not exist"
echo "./client fake_host.com 80 bad_request index.html"
./client fake_host.com 80 bad_request index.html > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo


echo "'1337' is not a real request"
echo "./client fake_host.com 80 1337 index.html"
./client fake_host.com 80 1337 index.html > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo


echo "Requests method names should be in all caps"
echo "./client fake_host.com 80 put index.html"
./client fake_host.com 80 put index.html > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo


echo "./client fake_host.com 80 get index.html"
./client fake_host.com 80 get index.html > /dev/null
if [ $? -eq 255 ]
then
    echo "Passed"
else
    echo "Fail"
fi
echo

