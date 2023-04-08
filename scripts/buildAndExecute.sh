# Create dirs for recoding
mkdir -p ../recording
mkdir -p ../recording/images

# Create MakeFile
cmake -B../build -H..

# Compile using make
cd ../build
make

# Execute the app
cd ../bin
./physics_simulations

# Return to previous
cd -