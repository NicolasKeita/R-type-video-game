#!/bin/sh

if [ -z "$1" ] ; then
cd "test_1_source_code/" || exit 42
else
cd "$1/test_1_source_code/" || exit 42
fi
g++ serv.cpp ../../ServerWrapper.cpp -l pthread  -o serv -I ../../
g++ client.cpp ../../ClientWrapper.cpp -l pthread -I ../../../my_string/ -I ../../ -o client
./serv > /dev/null 2>&1 &
./client >> ../log_client.txt 2>&1 &
sleep 4
ps -ef | grep -w ./serv | grep -v grep | awk '{print $2}' | xargs kill
ps -ef | grep -w ./client | grep -v grep | awk '{print $2}' | xargs kill
FIRST_TIME_RESULT=$(grep "FIRST TEST SUCCESSFULLY COMPLETED" ../log_client.txt)
SECOND_TIME_RESULT=$(grep "SECOND TEST" ../log_client.txt)
rm ../log_client.txt
rm ./serv
rm ./client
if [ -n "$FIRST_TIME_RESULT" ] && [ -n "$SECOND_TIME_RESULT" ] ; then
#echo "[Test Network] Test_1 passed."
exit 0
else
#echo "[Test Network] Test_1 failed"
exit 1
fi
