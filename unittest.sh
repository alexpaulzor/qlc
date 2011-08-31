#!/bin/bash

ARCH=`uname`

#############################################################################
# Engine tests
#############################################################################

pushd .
cd engine/test
DYLD_FALLBACK_LIBRARY_PATH=$DYLD_FALLBACK_LIBRARY_PATH:../src \
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../src ./test_engine
RESULT=$?
if [ $RESULT != 0 ]; then
	echo "Engine unit test failed ($RESULT). Please fix before commit."
	exit $RESULT
fi
popd

#############################################################################
# UI tests
#############################################################################

TESTDIR=ui/test
TESTS=`find ${TESTDIR} -type d -maxdepth 1 -mindepth 1`
for test in ${TESTS}
do
    # Ignore .svn
    if [ `echo ${test} | grep ".svn"` ]; then
        continue
    fi

    # Isolate just the test name
    test=`echo ${test} | sed 's/ui\/test\///'`

    # Execute the test
    pushd .
    cd ${TESTDIR}/${test}
    DYLD_FALLBACK_LIBRARY_PATH=$DYLD_FALLBACK_LIBRARY_PATH:../../../engine/src \
        LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../../../engine/src ./${test}_test
    RESULT=${?}
    popd
    if [ ${RESULT} != 0 ]; then
        echo "${RESULT} UI unit tests failed. Please fix before commit."
        exit ${RESULT}
    fi
done

#############################################################################
# Enttec wing tests
#############################################################################

pushd .
cd plugins/ewinginput/test
DYLD_FALLBACK_LIBRARY_PATH=$DYLD_FALLBACK_LIBRARY_PATH:../src \
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../src ./test_ewing
RESULT=$?
if [ $RESULT != 0 ]; then
	echo "Enttec wing unit test failed ($RESULT). Please fix before commit."
	exit $RESULT
fi
popd

#############################################################################
# Velleman Output tests
#############################################################################

if [ ${ARCH} != "Darwin" ]; then
    pushd .
    cd plugins/vellemanout/test
    DYLD_FALLBACK_LIBRARY_PATH=$DYLD_FALLBACK_LIBRARY_PATH:../src \
	    LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../src ./vellemanout_test
    RESULT=$?
    if [ $RESULT != 0 ]; then
	    echo "Velleman Output unit test failed ($RESULT). Please fix before commit."
	    exit $RESULT
    fi
    popd
fi

#############################################################################
# MIDI Input tests
#############################################################################

pushd .
cd plugins/midiinput/common/test
DYLD_FALLBACK_LIBRARY_PATH=$DYLD_FALLBACK_LIBRARY_PATH:../src \
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../src ./test_common
RESULT=$?
if [ $RESULT != 0 ]; then
    echo "MIDI Input common unit test failed ($RESULT). Please fix before commit."
    exit $RESULT
fi
popd

#############################################################################
# Final judgment
#############################################################################

echo "Unit tests passed."
