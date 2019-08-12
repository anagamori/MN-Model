#!/bin/sh

prefix=/home/hines/neuron/nrnmpi
exec_prefix=/home/hines/neuron/nrnmpi/x86_64
NRNBIN=${exec_prefix}/bin
ARCH=x86_64
MODSUBDIR=x86_64
NEURONHOME=/home/hines/neuron/nrnmpi/share/nrn

cd $1

if [ -x ${MODSUBDIR}/special ] ; then
	program="./${MODSUBDIR}/special"
else
	program="${NRNBIN}/nrniv"
fi

hostname
pwd
shift
shift
echo "time $program $*"
time $program $*

