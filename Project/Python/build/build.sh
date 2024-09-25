#!/bin/bash
#/*
# * Copyright (c) 2024 Renwei
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# */
homedir=$(cd `dirname $0`; pwd)

product=$1
bin=`echo $product | tr '[a-z]' '[A-Z]'`-BIN

cd $product

if [ -d "bin_data" ]; then
    rm -rf bin_data
fi
mkdir bin_data
cd bin_data

cp $homedir/build.spec .
cp $homedir/boot.py .

sed -i "s/___FLAG_FOR_PRODUCT___/$product/g" build.spec
sed -i "s/___FLAG_FOR_BIN___/$bin/g" build.spec
sed -i "s/___FLAG_FOR_PRODUCT___/$product/g" boot.py

if [ ! -f "/usr/local/bin/pyinstaller" ]; then
    pip install pyinstaller
fi
if [ ! -f "/usr/bin/jmpy" ]; then
    pip install jmpy3
fi

if [ -d "project" ]; then
    rm -rf project
fi
mkdir project
cd project
cp ../../../../project/dave_main.py ./
cp -r ../../../../project/components ./
mkdir ./product
cp ../../../../project/product/dave_product.py ./product
cp -r ../../../../project/product/$product ./product
cp -r ../../../../project/public ./
cd ../

jmpy -i "project/product/$product" -o "project/dist" -m 0
rm -rf ./project/product/$product
mkdir ./project/product/$product
cp -r ./project/dist/* ./project/product/$product

pyinstaller build.spec

if [ ! -d "../../../../../Deploy/deploy/$product/file_system/project" ]; then
    mkdir -p ../../../../../Deploy/deploy/$product/file_system/project
fi
cp ./dist/$product/$bin ../../../../../Deploy/deploy/$product/file_system/project

cd ..

rm -rf bin_data