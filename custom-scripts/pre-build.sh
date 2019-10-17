#!/bin/sh

make -C $BASE_DIR/../modules/simple_driver

#Compile the syscall_test.c
BUILDROOT_DIR=$BASE_DIR/..
COMPILER=$BUILDROOT_DIR/output/host/bin/i686-buildroot-linux-uclibc-gcc
$COMPILER -o $BUILDROOT_DIR/output/target/bin/syscall_test $BUILDROOT_DIR/custom-scripts/syscall_test.c
$COMPILER -o $BUILDROOT_DIR/output/target/bin/syscall_test2 $BUILDROOT_DIR/custom-scripts/syscall_test2.c
cp $BASE_DIR/../custom-scripts/fstab $BASE_DIR/target/etc/fstab

