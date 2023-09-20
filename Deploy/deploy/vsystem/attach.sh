#!/bin/bash
#/*
# * Copyright (c) 2023 Renwei
# *
# * This is a free software; you can redistribute it and/or modify
# * it under the terms of the MIT license. See LICENSE for details.
# */

CONTAINER=$1

if [ "$CONTAINER" == "" ]; then
   CONTAINER="vsystem-hub"
fi

docker attach ${CONTAINER}