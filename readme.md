### OVERVIEW
#### creates a new shape with a single primitive.

### REQUIREMENTS
#### run it with ubuntu which can be downloaded from windows store or use dual booting for increased performance
#### does not work on tesla

### FEATURES
#### changes colors between green and blue using a sine wave
#### edit variables to create a completely new shape
#### animates instead of drawing it instantly

### LEARNED
#### the main thing I learned from this project is how to use sfml. When animating the triangle, I was using delta time which resulted in the triangles rotating and scaling at different angles. It was very inconsistent which is why I changed to a timer resulting in a much smoother experience. Keyboard inputs and drawing onto a window is something I have done before, it just came down to learning how to do it with sfml

### DEPENDENCIES
#### cmake
```sh
sudo apt-get install cmake
```

#### sfml
```sh
sudo apt-get install libsfml-dev
```

### BUILDING PROJECT
```sh
cmake -S . -B build
cd build && make && ./rainbow
```

### SCREENSHOTS
![Image 1](https://github.com/Arathne/Triangle_Swirl/blob/master/1.png)
![Image 2](https://github.com/Arathne/Triangle_Swirl/blob/master/2.png)
![Image 3](https://github.com/Arathne/Triangle_Swirl/blob/master/3.png)
