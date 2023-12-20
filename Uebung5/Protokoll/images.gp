################################################
# Resonanzkurve
################################################
set terminal epslatex color
set output "bilder/resonanzkurve.tex"

# Set data file separator and skip the first line as it's a comment
set datafile separator whitespace
set xlabel "$f$ (Hz)"
set ylabel "$\\varphi_{\\text{max}}$ (rad)"
set key top left
set grid

plot "plot_data/resonanzkurve.dat" using 1:2:3 with yerrorbars title "Messpunkte mit Fehlerbalken"

################################################
# Erregerfrequenz Erregerspannung
################################################
set terminal epslatex color
set output "bilder/erregerfrequenz_erregerspannung_linear_fit.tex"

# Set data file separator and skip the first line as it's a comment
set datafile separator whitespace
set xlabel '$U$ (V)'
set ylabel '$f$ (Hz)'
set grid

# Linear fit
f(x) = a + b*x
fit f(x) 'plot_data/erregerfrequenz_erregerspannung.dat' using 1:2 via a, b

# Specify the columns for x, y, x error, and y error
plot "plot_data/erregerfrequenz_erregerspannung.dat" using 1:2:4 with yerrorbars title 'Messpunkte mit Fehlerbalken', f(x) title '$f(U)$'

