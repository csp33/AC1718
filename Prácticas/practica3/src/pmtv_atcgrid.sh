#!/bin/bash

export OMP_SCHEDULE="static"
echo "Static. Chunk por defecto."
./pmtv_openmp 15360

export OMP_SCHEDULE="static,1"
echo "Static. Chunk=1."
./pmtv_openmp 15360

export OMP_SCHEDULE="static,64"
echo "Static. Chunk=64."
./pmtv_openmp 15360
################################
export OMP_SCHEDULE="dynamic"
echo "Dynamic. Chunk por defecto."
./pmtv_openmp 15360

export OMP_SCHEDULE="dynamic,1"
echo "Dynamic. Chunk=1."
./pmtv_openmp 15360

export OMP_SCHEDULE="dynamic,64"
echo "Dynamic. Chunk=64."
./pmtv_openmp 15360

#####################

export OMP_SCHEDULE="guided"
echo "Guided. Chunk por defecto."
./pmtv_openmp 15360

export OMP_SCHEDULE="guided,1"
echo "Guided. Chunk=1."
./pmtv_openmp 15360

export OMP_SCHEDULE="guided,64"
echo "Guided. Chunk=64."
./pmtv_openmp 15360



