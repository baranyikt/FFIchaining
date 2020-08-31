@echo off
pushd %~dp0
cd ..\c_to_rust
rustc src/lib.rs --crate-type staticlib --print=native-static-libs
popd