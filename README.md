# Fractol

Projet de l'école 42. Exploration de différentes fractales comme les ensembles de Mandelbrot ou de Julia.

### Download repository and compile the project
```
git clone https://github.com/almaurgit/Fractol.git Fractol && cd Fractol
make fclean && make opti
```

### Usage
```
./fractol [fractal]
          [fractal] = [mandelbrot | julia | burningship | burningjulia
                       mandel4 | glynn | newton | buddhabrot | barnsley | sierpinski]
```

Press H to turn off the live display of the parameters and improve performances.

Les fractales Mandelbrot et Julia en interaction :
![Mandelbrot and Julia relation](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdXkxMHppb29uaHFscDIxb21oemVjNHc5NjNyNmpxcGRwMWdlbXJ2ZSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/qU25ZRfwKIYMu9VrUv/giphy.gif)

Zoom sur la fractale de Mandelbrot :
<video width="largeur" height="hauteur" controls>
  <source src="(https://www.youtube.com/watch?v=gjHr9Lj5jdM)" type="video/mp4">
  Mandelbrot Zoom
</video>

