#!/bin/bash

# Performs a simple regression test by comparing
# the results of a test run on some sample files
# in test/ to a file containing reference output

exit_code=0

ALOA_PATH=../make/aloa
CURR_DIR=$(pwd)

if [ "test" != ${CURR_DIR##*/} ]; then
    echo "Run this script from the 'test' directory."
    exit 1
fi
if [ ! -x "$ALOA_PATH" ]; then
    echo "$ALOA_PATH doesn't exist. Please perform a build first."
    exit 1
fi

###################################
# Test output to stdout.
#
$ALOA_PATH -f lint.output.xml > output
diff output output.ref
if [ $? -ne 0 ]; then 
    echo "*** Test (stdout) failed! ***"
    exit_code=1; 
    fi

###################################
# Test XML ouput.
#
$ALOA_PATH -f lint.output.xml -x output.xml 
diff output.xml output.xml.ref
if [ $? -ne 0 ]; then 
    echo "*** Test (XML output) failed! ***"
    exit_code=1; 
    fi

exit $exit_code

