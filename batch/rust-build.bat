@echo off
pushd %~dp0
cd ..\c_to_rust
cargo build --release
if errorlevel 1 goto error
copy /y target\release\c_to_rust.lib ..\matlab_to_c\
goto exit
:error
echo Error occurred running cargo build, no copy made
:exit
popd